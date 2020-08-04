section	.text

extern	ft_strlen	; size_t ft_strlen(const char *s);
extern	malloc		; void   *malloc(size_t size);
extern	ft_strcpy	; char   *ft_strcpy(char *dest, const char *src);
global	ft_strdup	; rdi = const char *s

ft_strdup:
	push	rdi		; save const char *s
	call	ft_strlen
	mov	rdi, rax
	inc	rdi
	call	malloc		; rax = (void *)malloc return
	pop	rsi		; rsi = const char *s
	test	rax, rax
	jz	.error
	mov	rdi, rax
	call	ft_strcpy
	ret
.error:
	ret
	
