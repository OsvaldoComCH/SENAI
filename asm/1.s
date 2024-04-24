.section .rdata
l1:
	.asciz "%i\n"
.section .text
.globl main
main:
	pushl	%ebp
	movl	%esp, %ebp
	movl	$0, %ebx
	movl	$0, %esi
	movl	$1, %edi
	pushl	%esi
	pushl	$l1
	call	_printf
	cmp		%ebx, $5
	je		finish
fib:
	movl	%edi, 4(%esp)
	call	_printf
	cmp		%ebx, $5
	je		finish
	addl	%edi, %esi
	movl	%esi, 4(%esp)
	call	_printf
	cmp		%ebx, $5
	je		finish
	addl	%esi, %edi
	jmp		fib

finish:
	movl	%ebp, %esp
	popl	%ebp
	ret
