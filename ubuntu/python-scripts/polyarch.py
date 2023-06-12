arch_dict = {
    # Common
    'aarch64' : {
        'pwntools' : 'aarch64',
        'rasm2'    : ('arm', 64),
        'capstone' : 'arm64',
    },
    'arm' : {
        'pwntools' : 'arm',
        'rasm2'    : ('arm', 32),
        'capstone' : 'arm',
    },
    'bpf' : {
        'pwntools' : None,
        'rasm2'    : None,
        'capstone' : 'bpf',
    },
    'ebpf' : {
        'pwntools' : None,
        'rasm2'    : None,
        'capstone' : 'ebpf',
    },
    'hexagon' : {
        'pwntools' : None,
        'rasm2'    : ('hexagon', 32),
        'capstone' : None,
    },
    'm68k' : {
        'pwntools' : 'm68k',
        'rasm2'    : ('m68k.cs', 32),
        'capstone' : 'm68k',
    },
    'mips' : {
        'pwntools' : 'mips',
        'rasm2'    : ('mips', 32),
        'capstone' : 'mips',
    },
    'msp430' : {
        'pwntools' : 'msp430',
        'rasm2'    : ('msp430', 16),
        'capstone' : None,
    },
    'ppc' : {
        'pwntools' : 'powerpc',
        'rasm2'    : ('ppc', 64),
        'capstone' : 'ppc64',
    },
    'riscv32' : {
        'pwntools' : 'riscv',
        'rasm2'    : ('riscv', 32),
        'capstone' : 'riscv32',
    },
    'riscv' : {
        'pwntools' : 'riscv',
        'rasm2'    : ('riscv', 64),
        'capstone' : 'riscv64',
    },
    'sparc' : {
        'pwntools' : 'sparc',
        'rasm2'    : ('sparc', 64),
        'capstone' : 'sparc',
    },
    'thumb' : {
        'pwntools' : 'thumb',
        'rasm2'    : ('arm', 16),
        'capstone' : 'thumb',
    },
    'wasm' : {
        'pwntools' : None,
        'rasm2'    : ('wasm', 32),
        'capstone' : 'wasm',
    },
    'i386' : {
        'pwntools' : 'i386',
        'rasm2'    : ('x86', 32),
        'capstone' : 'x32',
    },
    'amd64' : {
        'pwntools' : 'amd64',
        'rasm2'    : ('x86', 64),
        'capstone' : 'x64',
    },
    'xtensa' : {
        'pwntools' : None,
        'rasm2'  : ('xtensa', 32),
        'capstone' : None,
    },
}
