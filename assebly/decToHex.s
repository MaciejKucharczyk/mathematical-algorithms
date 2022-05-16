SYSEXIT  = 1
SYSREAD  = 3
SYSWRITE = 4

STDIN  = 0
STDOUT = 1

EXIT_SUCCESS = 0
INPUT_LEN = 11
OUTPUT_LEN = 36

.bss
    .comm buffer_input, 11     #max int + \n
    .comm buffer_output, 36

.text
.global _start

_start:

#wczytaj liczbe dziesietna

mov $SYSREAD, %eax
mov $STDIN, %ebx
mov $buffer_input, %ecx
mov $INPUT_LEN, %edx

int $0x80

#zerujemy ecx i edx 
xor %ecx, %ecx
xor %edx, %edx

#przechozde przez cala liczbe, czyliprzesuwam bufor o 1, az napotkam znak konca linii
#aby zamienic wpisane ascii na liczbe

#funkcja ascii_to_num: eax 10^n, gdzie n to miejsce cyfry w buforze (liczone od 0)
#ecx to jedna cyfra z bufora
#edx to wynik

ascii_to_num:
mov buffer_input(%edi, 1), %cl
cmp $'\n', %cl
je to_bin

mov $10, %eax 
mul %edx    
mov %eax, %edx
subb $48, %cl  #zamiana ascii na liczbe bo kod ascii '0' to 48
add %ecx, %edx
inc %edi
jmp ascii_to_num

to_bin:
mov %edx, %eax  #wynik do eax
mov $OUTPUT_LEN, %edi

dec %edi
movb $'\n', buffer_output(%edi, 1)

num_to_bin:
xor %edx, %edx  #zeruje reszte
mov $16, %ebx
div %ebx        #wynik/16
cmp $10, %dl
jl number
jmp letter
add:
mov %dl, buffer_output(%edi, 1)
dec %edi
cmp $0, %eax    #dzielimy liczbe az bedzie 0
jg num_to_bin



mov $SYSWRITE, %eax
mov $STDOUT, %ebx
mov $buffer_output, %ecx
mov $OUTPUT_LEN, %edx

int $0x80


mov $SYSEXIT, %eax
mov $EXIT_SUCCESS, %ebx
int $0x80

letter:
addb $55, %dl
jmp add

number:
addb $48, %dl
jmp add
