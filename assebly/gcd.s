SYSEXIT  = 1
SYSREAD  = 3
SYSWRITE = 4

STDIN  = 0
STDOUT = 1

EXIT_SUCCESS = 0

number1 = 14
number2 = 35

.data
format: .asciz "%lu\n"
.text
.global _start

_start:

mov $number1, %eax
mov $number2, %ecx

warunek:
cmp $0, %ecx    #jezeli liczba2 = 0 koniec programu
je _exit

xor %edx, %edx  #zerowanie reszty   
div %ecx        #eax liczb1, ecx liczba 2, liczb1/liczba2, reszta w edx
mov %ecx, %eax  #liczba1 = liczba2
mov %edx, %ecx  #liczba2 = reszta
cmp $0, %edx    #reszta = 0 to koniec algorytmu, wynik w eax
jne warunek



_exit:
mov $SYSEXIT, %eax
mov $EXIT_SUCCESS, %ebx
int $0x80
