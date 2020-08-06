section .text

global _ft_strlen ; rdi = const char *str

_ft_strlen:
	mov	rax, rdi
.loop:
	cmp	byte [rax], 0
	je	.endloop
	inc	rax
	jmp	.loop
.endloop:
	sub	rax, rdi
	ret
