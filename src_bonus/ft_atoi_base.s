section	.text

extern	_ft_isspace	; int ft_isspace(int c);
extern	_ft_tolower	; int ft_tolower(int c);
extern	_get_digit	; int get_digit(char c, int base);
global	_ft_atoi_base	; int ft_atoi_base(const char *s, int base);
			;				rdi	rsi

_ft_atoi_base:
	xor	rax, rax
	cmp	rsi, 2
	jl	.error
	cmp	rsi, 16
	jg	.error
	jmp	.while_space
.error:
	ret
.while_space:
	push	rdi		; save rdi
	mov	al, byte [rdi]
	xor	rdi, rdi
	mov	di, ax
	push	rsi
	call	_ft_isspace
	pop	rsi
	pop	rdi
	test	rax, rax	; if (ft_isspace(c))
	jz	.end_space
	inc	rdi
	jmp	.while_space
.end_space:
	mov	r8b, 1			; r8b = sign
	cmp	byte [rdi], '-'
	je	.if_sign_minus
	cmp	byte [rdi], '+'
	je	.if_sign_plus
	jmp	.after_sign

.if_sign_minus:
	neg	r8b
.if_sign_plus:
	inc	rdi

.after_sign:
	xor	rax, rax
	mov	r9, rax	; r9 = result = 0
	push	rbx		; save rbx
.while_digit:
	push	rdi		; save rdi
	mov	al, byte [rdi]
	xor	rdi, rdi
	mov	di, ax
	push	rsi		; save rsi
	call	_ft_tolower
	mov	rdi, rax
	call	_get_digit
	pop	rsi
	pop	rdi
	cmp	rax, 0		; get_digit() >= 0
	jl	.end_digit
	
	push	rax		;;; result = result * base
	mov	rax, r9
	mov	rbx, rsi
	mul	rbx
	mov	r9, rax	;;;

	pop	rax		;;;;; digit * sign
	cmp	r8b, 0
	jg	.plus
	sub	r9, rax	; result = result - digit
	jmp	.after_sum
.plus:
	add	r9, rax	; result = result + digit
.after_sum:
	inc	rdi
	jmp	.while_digit
.end_digit:
	pop	rbx		; checkout rbx
	mov	rax, r9
	ret
