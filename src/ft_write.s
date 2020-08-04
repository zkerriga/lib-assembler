section	.text
extern	__errno_location
global	ft_write ; rdi = int fd, rsi = const void *buf, rdx = size_t count

ft_write:
	xor	rax, rax
	mov	rax, 1		; write sys_code
	syscall			; call write
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
