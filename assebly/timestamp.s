.global timestamp

# Segment kodu
.text

timestamp:
push %ebx

xor %eax, %eax
cpuid
rdtsc

pop %ebx
ret