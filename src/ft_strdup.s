section	.text

extern	_ft_strlen	; size_t ft_strlen(const char *s);
extern	_malloc		; void   *malloc(size_t size);
extern	_ft_strcpy	; char   *ft_strcpy(char *dest, const char *src);
global	_ft_strdup	; rdi = const char *s

_ft_strdup:
	push	rdi		; save const char *s
	call	_ft_strlen
	mov	rdi, rax
	inc	rdi
	call	_malloc		; rax = (void *)malloc return
	pop	rsi		; rsi = const char *s
	test	rax, rax
	jz	.error
	mov	rdi, rax
	call	_ft_strcpy
	ret
.error:
	ret
	
