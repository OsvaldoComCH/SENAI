.data
x: .asciz  "Bom Dia"

.text
.globl main
main:
    movl $4, %eax
    movl $1, %ebx
    movl $x, %ecx
    movl $8, %edx
    int $0x80
    
    movl $1, %eax
    movl $0, %ebx
    int $0x80