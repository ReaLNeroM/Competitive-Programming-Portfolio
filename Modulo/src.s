	.file	"src.cpp"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$5, -4(%rbp)
	movl	$2, -8(%rbp)
.L3:
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jl	.L2
	movl	-8(%rbp), %eax
	subl	%eax, -4(%rbp)
	jmp	.L3
.L2:
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 7.1.0"
	.section	.note.GNU-stack,"",@progbits
