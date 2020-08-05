section	.text

extern	malloc		; void   *malloc(size_t size);
global	ft_lstnew	; t_list ft_lstnew(void *data);
			;			rdi

ft_lstnew:
	push	rdi
	mov	rdi, 16			; 2 * 8 byte for malloc
	call	malloc
	test	rax, rax
	jz	.error
	pop	qword [rax]		; saved rdi to *rax
	mov	qword [rax + 8], 0x0
	ret
.error:
	pop	rdi
	ret
