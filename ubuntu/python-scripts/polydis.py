#!/usr/bin/env python3

import argparse
import subprocess
import sys
import click
from polyarch import arch_dict

# https://www.assemblyai.com/blog/the-definitive-guide-to-python-click/
# https://www.geeksforgeeks.org/click-module-in-python-making-awesome-command-line-utilities/ - simple overview

# TODO: rewrite in rust? - eventually
# DONE: disassemble an instruction using all three backends or just one of them or any one that works (e.g., "all", "any", "pwn|cap|r2")
# TODO: make a shellen like interface using prompt toolkit
# DONE: disassemble bytes using all archs specified, e.g. -a aarch64,arm,x86,mips:32:little,

@click.command("polydis")
@click.argument('hexstring')
@click.option("-p", "--pwn", default=False, flag_value="pwn", help="Use pwntools to disassemble")
@click.option("-r", "--rasm2", default=False, flag_value="rasm2", help="Use rasm2 to disassemble")
@click.option("-c", "--capstone", default=False, flag_value="capstone", help="Use capstone to disassemble")
@click.option("-A", "--all-backends", default=False, flag_value="all-backends", help="Use all backends to disassemble")
@click.option("-a", "--arch", default="amd64", help="Which architectures to disassemble for")
def polydis(hexstring, pwn, rasm2, capstone, all_backends, arch):
    if all_backends:
        pwn = True
        rasm2 = True
        capstone = True
    if pwn:
        print("--> Pwntools Disassembly:")
        arch_list = arch.split(",")
        for a in arch_list:
            print(f"arch: {a}")
            pwn_arch = arch_dict[a]['pwntools']
            if pwn_arch:
                output = subprocess.check_output(f"pwn disasm -c {pwn_arch} {hexstring}", shell=True).decode().strip()
                print(output + "\n")
            else:
               print(f"{a} not supported by pwntools")
    if rasm2:
        print("--> rasm2 Disassembly:")
        arch_list = arch.split(",")
        for a in arch_list:
            print(f"arch: {a}")
            rasm2_arch = arch_dict[a]['rasm2'][0]
            rasm2_bits = arch_dict[a]['rasm2'][1]
            if rasm2_arch:
                output = subprocess.check_output(f"rasm2 -d -a {rasm2_arch} -b {rasm2_bits} {hexstring}", shell=True).decode().strip()
                print(output + "\n")
            else:
               print(f"{a} not supported by rasm2")
    if capstone:
        print("--> Capstone Disassembly:")
        arch_list = arch.split(",")
        for a in arch_list:
            print(f"arch: {a}")
            capstone_arch = arch_dict[a]['capstone']
            if capstone_arch:
                try:
                    output = subprocess.check_output(f"cstool {capstone_arch} {hexstring}", shell=True).decode().strip()
                    print(output + "\n")
                except subprocess.CalledProcessError:
                    print(f"error: cstool failed to disassemble {hexstring}")
            else:
               print(f"{a} not supported by capstone")

# Common
# arm
# bpf
# hexagon
# m68k
# mips
# msp430
# ppc
# riscv
# sparc
# wasm
# x86
# x86_64
# xtensa

# pwntools
                        # linux/i386), choose from: ['16', '32',
                        # '64', 'android', 'baremetal', 'cgc',
                        # 'freebsd', 'linux', 'windows',
                        # 'powerpc64', 'aarch64', 'powerpc',
                        # 'sparc64', 'mips64', 'msp430', 'alpha',
                        # 'amd64', 'riscv', 'sparc', 'thumb',
                        # 'cris', 'i386', 'ia64', 'm68k', 'mips',
                        # 's390', 'none', 'avr', 'arm', 'vax',
                        # 'little', 'big', 'be', 'eb', 'le', 'el']

# capstone (cstool)
# AArch64 ARM BPF EVM M68OX M68K MOS65XX Mips PowerPC RISCV Sparc SystemZ TMS320C64X WASM X86 XCore

# Less Common
# 6502 (r2, cap)
# 8051
# avr (pwn, r2)
# hppa
# sh
# z80
#
# s390 (pwn)
# cris (r2, pwn)
# vax (r2, pwn)
# alpha (pwn)
# m680X (r2, cap)
# bpf (cap)
# xcore (r2, cap)
# systemz (r2, cap)
# tms320 (cap, r2)
# evm (cap) ethereum vm

# Uncommon
# amd29k
# arc
# bf
# chip8
# cr16
# cris
# dalvik
# dcpu16
# ebc
# gb
# h8300
# i4004
# i8080
# java
# lanai
# lh5801
# lm32
# m680x
# malbolge
# mcore
# mcs96
# nios2
# or1k
# pic
# propeller
# rsp
# snes
# spc700
# sysz
# tms320
# tms320c64x
# tricore
# v810
# v850
# vax
# wasm
# ws
# xap
# xcore

if __name__ == '__main__':
    polydis()
