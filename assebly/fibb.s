.data
format: .asciz "%lu\n"

.text

.global fibb

fibb:
push %ebp
mov %esp, %ebp
push %ebx

cmpl $0, 8(%ebp)
je zero

cmpl $1, 8(%ebp)
je jeden

movl 8(%ebp), %edx
dec %edx

push %edx
call fibb
pop %edx
mov %eax, %ebx

dec %edx
push %edx
call fibb
pop %edx
add %ebx, %eax
jmp koniec

zero:
mov $0, %eax
jmp koniec

jeden:
mov $1, %eax
jmp koniec

koniec:

pop %ebx
pop %ebp
ret