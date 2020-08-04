section .text

global	ft_strcpy ; rdi = char *dest, dsi = const char *src

ft_strcpy:
	mov	rax, rdi
.loop:
	mov	dl, byte [rsi]
	mov	byte [rdi], dl
	test	dl, dl
	jz	.endloop
	inc	rdi
	inc	rsi
	jmp	.loop
.endloop:
	ret
	
