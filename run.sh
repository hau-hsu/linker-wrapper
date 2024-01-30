riscv64-unknown-elf-g++ -S lib.cpp -o lib.s
./wrap-symbols lib.s -o lib.s
riscv64-unknown-elf-g++ lib.s -c
riscv64-unknown-elf-g++ main.cpp -c
./ld-wrapper lib.o main.o -o main

