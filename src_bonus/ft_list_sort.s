section	.text

global	_ft_list_sort	; void	ft_list_sort(t_list **begin_list, int (*cmp)());						;							rdi				rsi

_ft_list_sort:
	mov		r8, qword [rdi]			; i_list = *begin_list (r8)
.while_i:
	mov		rax, qword [r8 + 8]		; rax = i_list->next
	test	rax, rax
	jz		.end_while_i
	mov		r9, qword [rdi]			; j_list = *begin_list (r9)
	.while_j:
		mov		rax, qword [r9 + 8]	; rax = j_list->next
		test	rax, rax
		jz		.end_while_j
		;;;; body
	.end_while_j:
		mov		r8, qword [r8 + 8]	; i_list = i_list->next
		jmp		.while_i
.end_while_i:
	ret
