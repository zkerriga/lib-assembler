section	.text

global	_ft_tolower	; int ft_tolower(int c);

_ft_tolower:
	mov	rax, rdi
	cmp	rax, 'A'
	jl	.return
	cmp	rax, 'Z'
	jg	.return
	add	rax, 'a' - 'A'
.return:
	ret
