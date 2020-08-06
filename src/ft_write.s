section	.text
extern	___error
global	_ft_write ; rdi = int fd, rsi = const void *buf, rdx = size_t count

_ft_write:
	xor	rax, rax
	mov	rax, 0x2000004		; write sys_code
	syscall					; call write
	jc	.error
	ret
.error:
	push	rax
	call	___error
	pop	rdx
	mov	dword [rax], edx
	mov	rax, -1
	ret
