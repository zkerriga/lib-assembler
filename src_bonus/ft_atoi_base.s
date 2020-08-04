section	.text

extern	ft_isspace	; int ft_isspace(int c);
extern	ft_tolower	; int ft_tolower(int c);
extern	get_digit	; int get_digit(char c, int base);
global	ft_atoi_base	; int ft_atoi_base(const char *s, int base);
			;				rdi	rsi

ft_atoi_base:
	xor	rax, rax
.while_space:
	push	rdi		; save rdi
	mov	al, byte [rdi]
	xor	rdi, rdi
	mov	di, ax
	call	ft_isspace
	pop	rdi
	test	rax, rax	; if (ft_isspace(c))
	jz	.end_space
	inc	rdi
	jmp	.while_space
.end_space:
	mov	byte [sign], 1
	cmp	byte [rdi], '-'
	je	.if_sign_minus
	cmp	byte [rdi], '+'
	je	.if_sign_plus
	jmp	.after_sign

.if_sign_minus:
	neg	byte [sign]
.if_sign_plus:
	inc	rdi
	jmp	.after_sign

.after_sign:
	xor	rax, rax
	mov	qword [result], rax	; result = 0
	push	rbx		; save rbx
.while_digit:
	push	rdi		; save rdi
	mov	al, byte [rdi]
	xor	rdi, rdi
	mov	di, ax
	push	rsi		; save rsi
	call	ft_tolower
	mov	rdi, rax
	call	get_digit
	pop	rsi
	pop	rdi
	cmp	rax, 0		; get_digit() >= 0
	jl	.end_digit

	push	rax		;;; result = result * base
	mov	rax, [result]
	mov	rbx, rsi
	mul	rbx
	mov	[result], rax	;;;

	pop	rax		;;;;; digit * sign
	cmp	byte [sign], 0
	jg	.plus
	sub	[result], rax	; result = result - digit
	jmp	.after_sum
.plus:
	add	[result], rax	; result = result + digit
.after_sum:
	inc	rdi
	jmp	.while_digit
.end_digit:
	pop	rbx		; checkout rbx
	mov	rax, qword [result]
	ret

section	.bss
sign	resb	1
result	resq	1
