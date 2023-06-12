import sys
import os
from pwn import *
from unicorn import *
from unicorn.arm64_const import *
from unicorn.arm_const import *
from unicorn.m68k_const import *
from unicorn.mips_const import *
from unicorn.ppc_const import *
from unicorn.riscv_const import *
from unicorn.s390x_const import *

from unicorn.sparc_const import *
from unicorn.x86_const import *
import click

def get_unicorn(arch):
    if   arch == "i386":    return Uc(UC_ARCH_X86, UC_MODE_32)
    elif arch == "amd64":   return Uc(UC_ARCH_X86, UC_MODE_64)
    elif arch == "arm":     return Uc(UC_ARCH_ARM, UC_MODE_ARM)
    elif arch == "aarch64": return Uc(UC_ARCH_ARM64, UC_MODE_ARM)
    elif arch == "m68k":    return Uc(UC_ARCH_M68K, UC_MODE_32)
    elif arch == "mips":    return Uc(UC_ARCH_MIPS, UC_MODE_32)
    elif arch == "ppc":     return Uc(UC_ARCH_PPC, UC_MODE_64)
    elif arch == "riscv":   return Uc(UC_ARCH_RISCV, UC_MODE_64)
    elif arch == "s390x":   return Uc(UC_ARCH_S390X , UC_MODE_32)
    else:                   raise ValueError("Unknown arch")

def get_syscall_regs(arch):
    if   arch == "i386":    return (UC_X86_REG_EAX, UC_X86_REG_EBX, UC_X86_REG_ECX, UC_X86_REG_EDX)
    elif arch == "amd64":   return (UC_X86_REG_RAX, UC_X86_REG_RDI, UC_X86_REG_RSI, UC_X86_REG_RDX)
    elif arch == "arm":     return (UC_ARM_REG_R7, UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2)
    elif arch == "aarch64": return (UC_ARM64_REG_X8, UC_ARM64_REG_X0, UC_ARM64_REG_X1, UC_ARM64_REG_X2)
    elif arch == "m68k":    return (UC_M68K_REG_D0, UC_M68K_REG_D1, UC_M68K_REG_D2, UC_M68K_REG_D3)
    elif arch == "mips":    return (UC_MIPS_REG_V0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_A3)
    elif arch == "ppc":     return (UC_PPC_REG_0, UC_PPC_REG_3, UC_PPC_REG_4,
UC_PPC_REG_5)
    elif arch == "riscv":   return (UC_RISCV_REG_A7, UC_RISCV_REG_A0, UC_RISCV_REG_A1, UC_RISCV_REG_A2)
    elif arch == "s390x":   return (UC_S390X_REG_R1, UC_S390X_REG_R2, UC_S390X_REG_R3, UC_S390X_REG_R4)
    else:                   raise ValueError("Unknown arch")

def get_stack_ptr_reg(arch):
    if   arch == "i386":    return UC_X86_REG_ESP
    elif arch == "amd64":   return UC_X86_REG_RSP
    elif arch == "arm":     return UC_ARM_REG_SP
    elif arch == "aarch64": return UC_ARM64_REG_SP
    elif arch == "m68k":    return UC_M68K_REG_A7
    elif arch == "mips":    return UC_MIPS_REG_SP
    elif arch == "ppc":     return UC_PPC_REG_1
    elif arch == "riscv":   return UC_RISCV_REG_SP
    elif arch == "s390x":   return UC_S390X_REG_R15
    else:                   raise ValueError("Unknown arch")

def run_unicorn(code, arch):
    code_len = len(code)
    code_addr = 0x1000
    mem_sz = 0x1000
    stack_addr = 0x10000
    # mu = Uc(UC_ARCH_X86, UC_MODE_32)
    mu = get_unicorn(arch)

    def hook_syscall(mu, intno, user_data):
        syscall_str = f"[{arch}] syscall"
        for reg in get_syscall_regs(arch):
            syscall_str = f"{syscall_str} {mu.reg_read(reg):#x}"
        print(syscall_str)
        # eax = mu.reg_read(UC_X86_REG_EAX)
        # ebx = mu.reg_read(UC_X86_REG_EBX)
        # ecx = mu.reg_read(UC_X86_REG_ECX)
        # print("int 0x80 {} {} {:x}".format(eax, ebx, ecx))
        # print(mu.mem_read(ecx, 16))

    mu.hook_add(UC_HOOK_INTR, hook_syscall)

    mu.mem_map(code_addr, mem_sz)
    mu.mem_write(code_addr, code)

    mu.mem_map(stack_addr-mem_sz, stack_addr+mem_sz)
    # mu.reg_write(UC_X86_REG_ESP, stack_addr)
    mu.reg_write(get_stack_ptr_reg(arch), stack_addr)

    mu.emu_start(code_addr, code_addr + code_len)

if __name__ == '__main__':
    syscall_num = 234
    syscall_arg1 = 52790
    syscall_string = b"sharp"
    str1 = int.from_bytes(syscall_string[:4], "little")
    str2 = int.from_bytes(syscall_string[4:], "little")
    x86_shellcode = asm(f'''
        mov eax, {str2}
        push eax
        mov eax, {str1}
        push eax
        mov eax, {syscall_num}
        mov ebx, {syscall_arg1}
        mov ecx, esp
        int 0x80
    ''', arch="i386", bits=32)

    x86_64_shellcode = asm(f'''
        mov rax, {int.from_bytes(syscall_string, "little")}
        push rax
        mov rax, {syscall_num}
        mov rdi, {syscall_arg1}
        mov rsi, rsp
        syscall
    ''', arch="amd64", bits=64)

    arm_shellcode = asm(f'''
        movw r7, #0x70
        push {{r7}}
        movw r7, #0x6873
        movt r7, #0x7261
        push {{r7}}
        mov r0, {syscall_arg1}
        mov r1, sp
        mov r7, {syscall_num}
        swi 0
    ''', arch="arm")

    aarch64_shellcode = asm(f'''
        movz x8, 0x6873
        movk x8, 0x7261, lsl 16
        movk x8, 0x70, lsl 32
        str x8, [sp, #0x0]
        mov x1, sp
        mov x0, #{syscall_arg1}
        mov x8, #{syscall_num}
        svc #0
    ''', arch="aarch64")

    mips_shellcode = asm(f'''
        ori $t1, $zero, 0x70
        sw $t1, 4($sp)
        lui $t1, 0x6873
        ori $t1, $zero, 0x7261
        sw $t1, 0($sp)

        move $a1, $sp
        li $a0, {syscall_arg1}
        li $v0, {syscall_num}
        syscall
    ''', arch="mips", endian="little")

    run_unicorn(x86_shellcode, "i386")
    run_unicorn(x86_64_shellcode, "amd64")
    run_unicorn(arm_shellcode, "arm")
    run_unicorn(aarch64_shellcode, "aarch64")
    run_unicorn(mips_shellcode, "mips")
