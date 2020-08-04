section .text

global	ft_strcmp ; rdi = const char *s1, rsi = const char *s2

ft_strcmp:
	xor	rax, rax
	xor	rdx, rdx
.loop:
	mov	al, byte [rdi]
	mov	dl, byte [rsi]
	sub	rax, rdx
	jnz	.endloop
	test	dl, dl
	jz	.endloop
	inc	rdi
	inc	rsi
	jmp	.loop
.endloop:
	ret
