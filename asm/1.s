.section .rdata
x:
    .ascii  "Bom Dia"
.text
.globl main
main:
    pushl	$-11
    call    _GetStdHandle@4
    pushl	$0
    pushl	$0
    pushl   $7
    pushl	$x
    pushl	%eax
    call    _WriteConsoleA@20
