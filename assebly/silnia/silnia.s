SYSEXIT  = 1
SYSREAD  = 3
SYSWRITE = 4

STDIN  = 0
STDOUT = 1

EXIT_SUCCESS = 0
INPUT_LEN = 11

number = 99

.section .bss

.section .data

.section .text

.global main

main:

mov $number, %rcx # liczba, z ktorej bedzie liczona silnia jest w rcx
cmp $0, %rcx # jesli liczba = 0, to wynik = 0
je zero

cmp $1, %rcx # jesli liczba = 1, to wynik = 1
je one

inc %rcx # zwiekszamy liczbe na potrzeby petli 
mov $1, %rdx # rdx - licznik petli
mov $1, %rax # wynik w rax
jmp main_loop

one:
mov $1, %rax # wynik w rax
jmp _exit
ret

zero:
mov $0, %rax # wynik w rax
jmp _exit
ret
# wynik powstaje poprzez mnozenie aktulanego wyniku przez licznik w kazdej iteracji
main_loop:
cmp %rdx, %rcx # jesli liczba+1 = licznik, to koniec petli
je _exit
imul %rdx, %rax # iteracyjne wyliczanie silni (mnozymy 1*2*3... itd az do maskymalnej wartosci licznika)
inc %rdx # zwiekszamy licznik
jmp main_loop
ret

_exit: # wyswietlenie wyniku i wyjscie
mov %rax, %rdx
mov $SYSWRITE, %rax
mov $STDOUT, %rbx
mov $3, %rcx

