# Introduction

This repo contains demo scripts for transfering Arm's wrapper functions `$Super$$sym` and `$Sub$$sym` to Gnu toolchain's `__wrap_sym` and `__real_sym`.

Reference: 
* [Arm patch symbols](https://developer.arm.com/documentation/dui0474/i/accessing-and-managing-symbols-with-armlink/about-using--super---and--sub---to-patch-symbol-definitions)
* [GNU --wrap=symbol](https://ftp.gnu.org/old-gnu/Manuals/ld-2.9.1/html_node/ld_3.html#IDX183)

There are 2 scripts in this repo:

* Pre-assemble script: transfer `$Super$$sym` and `$Sub$$sym` to `__wrap_sym` and `__real_sym`.
* Pre-link script: scane the input *.o files and add `--wrap=symbol` ld options if there are symbols starts with `__wrap`.


**Note that this is a POC demo, not a complete solution.**


## Demo:

Prerequests:

* Make sure RISC-V toolchain is in $PATH.
* Install python package to parse mangled symbols.
  ```
  $ pip install -u itanium_demangler
  ```

Build lib.cpp. First generates assebley code, then use pre-assemble script to transfer symbols.
```
$ riscv64-unknown-elf-g++ -S lib.cpp -o lib.s
$ ./wrap-symbols lib.s -o lib.s
$ riscv64-unknown-elf-g++ lib.s -c
```

Build main.cpp
```
$ riscv64-unknown-elf-g++ main.cpp -c
```

Link
```
$ ./ld-wrapper lib.o main.o -o main
```

We can use QEMU user mode to run the program:

```
$ qemu-riscv64 main
$Sub$$Build
Build
```

## Future work
It is possible to integrate these scripts into RISC-V toolchain and provide a SPEC file.
Ideally the build process can be simpilified to

```
$ riscv64-unknown-elf-g++ -specs=wrap.spec main.cpp lib.cpp
```
