section	.text

global	_ft_list_swap	; void	ft_list_swap(t_list *l1, t_list *l2);
						;						rdi				rsi

_ft_list_swap:
	mov		rcx, qword [rdi]	; swap = l1->data
	mov		rax, qword [rsi]	;
	mov		qword [rdi], rax	; l1->data = l2->data
	mov		qword [rsi], rcx	; l2->data = swap
	ret
