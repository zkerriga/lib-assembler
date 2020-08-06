section	.text

extern	_ft_lstnew		; t_list *ft_lstnew(void *data)
global	_ft_list_push_front	; void   ft_list_push_front(t_list **, void *);
				; rdi = **begin_list, rsi =  *data
_ft_list_push_front:
	test	rdi, rdi
	jz	.error
	push	rdi
	mov	rdi, rsi
	call	_ft_lstnew
	pop	rdi
	test	rax, rax		; rax = new t_list *
	jz	.error
	mov	rdx, qword [rdi]	; rdx = *begin_list
	mov	qword [rax + 8], rdx
	mov	qword [rdi], rax
.error:
	ret
