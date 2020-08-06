section	.text

global	_ft_list_size	; int ft_list_size(t_list *begin_list);
			;				rdi
_ft_list_size:
	xor	rax, rax	; counter
.while_not_null:
	test	rdi, rdi
	jz	.return
	inc	rax
	mov	rdi, qword [rdi + 8]
	jmp	.while_not_null
.return:
	ret
