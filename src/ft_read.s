section	.text
extern	__errno_location
global	ft_read ; rdi = int fd, rsi = const void *buf, rdx = size_t count

ft_read:
	xor	rax, rax
	mov	rax, 0		; read sys_code
	syscall			; call read
	cmp	rax, 0
	jl	.error
	ret
.error:
	neg	rax
	push	rax
	call	__errno_location
	pop	rdx
	mov	[rax], edx
	mov	rax, -1
	ret
