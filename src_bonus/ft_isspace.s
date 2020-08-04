section	.text

global	ft_isspace	; int ft_isspace(int c);

ft_isspace:
	xor	rax, rax
	cmp	rdi, 0x8	; 0x8 = '\b'
	jg	.true1
	ret
.true1:
	cmp	rdi, 0xD ; 0xD = '\r'
	jg	.true2
	inc	rax
	ret
.true2:
	cmp	rdi, ' '
	je	.true3
	ret
.true3:
	inc	rax
	ret
