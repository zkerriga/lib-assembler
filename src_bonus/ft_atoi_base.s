section	.text

extern	ft_isspace	; int ft_isspace(int c);
extern	ft_tolower	; int ft_tolower(int c);
extern	get_digit	; int get_digit(char c, int base);
global	ft_atoi_base	; int ft_atoi_base(const char *s, int base);
			;				rdi	rsi

ft_atoi_base:
	xor	rax, rax	; rax = result
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
	mov	dword [sign], 1
	cmp	byte [rdi], '-'
	je	.if_sign_minus
	cmp	byte [rdi], '+'
	je	.if_sign_plus
	jmp	.after_sign

.if_sign_minus:
	neg	dword [sign]
.if_sign_plus:
	inc	rdi
	jmp	.after_sign

.after_sign:
	mov	rax, [sign]	; for check (delete this)
	ret

section	.bss
sign	resq	1
