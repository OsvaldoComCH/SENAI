.section .rdata
x:
    .ascii  "Bom Dia"
.text
.globl main
main:
    pushl	$7
    pushl	$x
    call    _printf
    addl    $8, %esp
