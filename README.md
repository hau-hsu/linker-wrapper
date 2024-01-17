# Introduction

The linker wrapper is a simple shell script.

This is gcc/linker wrapper that:
  1. dumps symbols for all input object files
  2. find functions begin with `__wrap`
  3. add --wrap option to linekr


## Demo:

```
$ module load sifive/freedom-tools/toolsuite
$ riscv64-unknown-elf-gcc -c lib.c stub.c main.c
$ ./ld lib.o stub.o main.o -o main
Original command:
  lib.o stub.o main.o -o main
Added --wrap command:
  riscv64-unknown-elf-ld lib.o stub.o main.o -o main --wrap=foo --wrap=bar
riscv64-unknown-elf-ld: warning: cannot find entry symbol _start; defaulting to 00000000000100e8
```

The last line is because we didn't link with the crt0.o. It's not important in this demo.
