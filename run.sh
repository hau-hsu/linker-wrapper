riscv64-unknown-elf-gcc -c lib.c stub.c main.c
./ld lib.o stub.o main.o -o main

