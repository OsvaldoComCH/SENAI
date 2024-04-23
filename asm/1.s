.section .rdata
l1:
	.ascii "%i\n"
l2:
	.ascii "%i "
.section .data
x:
	.long 0
.section .text
.globl main
.globl printnumber
printnumber:
	movl	4(%esp), %eax
	test	%eax, %eax
	jz		pn0
	pushl	$l1
	jmp		pn1
pn0:
	pushl	$l2
pn1:
	call	_printf
	addl	$4, %esp
	ret
main:
	pushl	$1
	pushl	$10
	call	printnumber
