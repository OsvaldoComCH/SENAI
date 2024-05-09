	.file	"Sort.c"
	.section .rdata,"dr"
LC0:
	.ascii "%i, \0"
	.text
	.globl	_Sort
	.def	_Sort;	.scl	2;	.type	32;	.endef
_Sort:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	12(%ebp), %eax
	cmpl	16(%ebp), %eax
	jge	L11
	movl	16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -28(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	jmp	L4
L8:
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	cmpl	-28(%ebp), %eax
	jge	L5
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -32(%ebp)
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movl	(%eax), %eax
	movl	%eax, (%edx)
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-32(%ebp), %eax
	movl	%eax, (%edx)
	addl	$1, -12(%ebp)
	movl	$0, -20(%ebp)
	jmp	L6
L7:
	movl	-20(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	addl	$1, -20(%ebp)
L6:
	cmpl	$15, -20(%ebp)
	jle	L7
	movl	$10, (%esp)
	call	_putchar
L5:
	addl	$1, -16(%ebp)
L4:
	movl	-16(%ebp), %eax
	cmpl	16(%ebp), %eax
	jle	L8
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -36(%ebp)
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	16(%ebp), %eax
	leal	0(,%eax,4), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movl	(%eax), %eax
	movl	%eax, (%edx)
	movl	16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-36(%ebp), %eax
	movl	%eax, (%edx)
	movl	$0, -24(%ebp)
	jmp	L9
L10:
	movl	-24(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	addl	$1, -24(%ebp)
L9:
	cmpl	$15, -24(%ebp)
	jle	L10
	movl	$10, (%esp)
	call	_putchar
	movl	-12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_Sort
	movl	-12(%ebp), %eax
	leal	1(%eax), %edx
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%edx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_Sort
	jmp	L1
L11:
	nop
L1:
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$96, %esp
	call	___main
	movl	$2, 28(%esp)
	movl	$3, 32(%esp)
	movl	$5, 36(%esp)
	movl	$6, 40(%esp)
	movl	$8, 44(%esp)
	movl	$9, 48(%esp)
	movl	$10, 52(%esp)
	movl	$12, 56(%esp)
	movl	$13, 60(%esp)
	movl	$7, 64(%esp)
	movl	$16, 68(%esp)
	movl	$1, 72(%esp)
	movl	$14, 76(%esp)
	movl	$4, 80(%esp)
	movl	$15, 84(%esp)
	movl	$11, 88(%esp)
	movl	$15, 8(%esp)
	movl	$0, 4(%esp)
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	_Sort
	movl	$0, 92(%esp)
	jmp	L13
L14:
	movl	92(%esp), %eax
	movl	28(%esp,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	addl	$1, 92(%esp)
L13:
	cmpl	$15, 92(%esp)
	jle	L14
	movl	$0, %eax
	leave
	ret
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
