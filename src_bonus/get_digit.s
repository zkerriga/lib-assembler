section	.text

global	_get_digit	; int	get_digit(char c, int base);

_get_digit:		; rdi = char c, rsi = base
	cmp	rsi, 0xB	; if base <= 10
	jl	.true1
	add	rsi, 'a' - 0xA	; rsi = max_digit
	jmp	.check_digit_lim
.true1:
	add	rsi, '0'	; rsi = max_digit
.check_digit_lim:
	cmp	rdi, rsi	; c <= max_digit
	jg	.ret_error
	cmp	rdi, '0'	; c >= 0
	jl	.ret_error
	cmp	rdi, '9'	; c <= 9
	jg	.check_alpha_lim
	mov	rax, rdi
	sub	rax, '0'
	ret
.check_alpha_lim:
	cmp	rdi, 'a'	; c >= 'a'
	jl	.ret_error
	cmp	rdi, 'f'	; c <= 'f'
	jg	.ret_error
	mov	rax, rdi
	sub	rax, 'a' - 10
	ret
.ret_error:
	mov	rax, -1
	ret
