section .text

global ft_strlen

ft_strlen:
	mov	rax, rdi
.loop:
	cmp	byte [rax], 0
	je	.endloop
	inc	rax
	jmp	.loop
.endloop:
	sub	rax, rdi
	ret
