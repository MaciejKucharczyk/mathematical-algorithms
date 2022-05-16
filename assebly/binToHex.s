SYSEXIT = 1
SYSREAD = 3
SYSWRITE = 4

STDIN = 0
STDOUT = 1

EXIT_SUCCESS = 0


.bss
    .comm buffer, 9

.data
number:
    .long 123456789

.global _start

.text

_start:
movb $'\n', (buffer + 8)
mov $8, %esi
mov $0, %ecx


loop:
    movl (number), %edx

    shr %cl, %edx
    andb $0xf, %dl

    cmpb $10, %dl
    jl _number
    jmp letter

add:
    movb %dl, buffer(%esi)
    add $4, %ecx
    dec %esi

    cmp $0, %esi
    jg loop

    mov $SYSWRITE, %eax
    mov $STDOUT, %ebx
    mov $buffer, %ecx
    mov $9, %edx
    int $0x80

    mov $SYSEXIT, %eax
    mov $EXIT_SUCCESS, %ebx
    int $0x80

letter:
    addb $55, %dl
    jmp add

_number:
    addb $48, %dl
    jmp add

