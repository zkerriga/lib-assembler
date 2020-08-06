section	.text

global	_ft_list_swap	; void	ft_list_swap(t_list *l1, t_list *l2);
						;						rdi				rsi

_ft_list_swap:
	push	qword [rdi]			; swap = l1->data
	mov		rax, qword [rsi]
	mov		qword [rdi], rax	; l1->data = l2->data
	pop		qword [rsi]			; l2->data = swap
	ret
