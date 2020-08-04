section	.text

global	ft_tolower	; int ft_tolower(int c);

ft_tolower:
	mov	rax, rdi
	cmp	rax, 'A'
	jl	.return
	cmp	rax, 'Z'
	jg	.return
	add	rax, 'a' - 'A'
.return
	ret
