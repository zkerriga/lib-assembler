section	.text

extern	_ft_list_swap	; void	ft_list_swap(t_list *l1, t_list *l2);
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
		push	rdi			;;;
		push	rsi			;;;
		push	r8			;;;
		push	r9			;;;
		mov		rdx, rsi	; rdx = cmp()
		mov		rdi, qword [r9]		; j_list->data
		mov		rsi, qword [rax]	; j_list->next->data
		call	rdx
		pop		r9			;;; not all pop (!)
		cmp		eax, 0
		jng		.no_swap_please_oh_thanks
		push	r9
		mov		rdi, r9				;; rdi = j_list
		mov		rsi, qword [r9 + 8]	;; rsi = j_list->next
		call	_ft_list_swap
		pop		r9
		.no_swap_please_oh_thanks:
			pop		r8
			pop		rsi
			pop		rdi
			mov		r9, qword [r9 + 8]	; j_list = j_list->next
			jmp		.while_j
	.end_while_j:
		mov		r8, qword [r8 + 8]	; i_list = i_list->next
		jmp		.while_i
.end_while_i:
	ret
