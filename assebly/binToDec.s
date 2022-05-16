SYSEXIT  = 1
SYSREAD  = 3
SYSWRITE = 4

STDIN  = 0
STDOUT = 1

EXIT_SUCCESS = 0
INPUT_LEN = 36

.bss
    .comm buffer_input, 36    #max int + \n
    .comm buffer_help, 36

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
je to_dec

mov $10, %eax 
mul %edx    
mov %eax, %edx
subb $48, %cl  #zamiana ascii na liczbe bo kod ascii '0' to 48
mov %cl, buffer_help(%esi, 1)
add %ecx, %edx
inc %esi
jmp ascii_to_num

to_dec:
xor %ecx, %ecx
xor %ebx, %ebx
mov %edx, %ebx  #wynik w ebx czyli liczba binarna
xor %edx, %edx
mov $2, %ebx    #ebx to 2^n, gdzie n to pozycja cyfry
mov $1, %eax

dec %esi    #bo indeksujemy od 0, nie od 1
mov buffer_help(%esi, 1), %cl   #ostatnia cyfre z bufora przekazujemy do edi
                                #edi ostateczny wynik
mov %ecx, %edi

cmp $0, %esi
je _exit
num_to_dec:
dec %esi
mov buffer_help(%esi, 1), %cl
mul %ebx                       
mul %cl                     #1*2^n*cyfra
add %eax, %edi              #dodajemy do wyniku
add %ebx, %ebx              #2^n+1
mov $1, %eax
cmp $0, %esi
jne num_to_dec




_exit:
mov $SYSEXIT, %eax
mov $EXIT_SUCCESS, %ebx
int $0x80
