section	.text

extern	_free			; void free(void *);
global	_ft_list_remove_if	; void ft_list_remove_if(t_list **, void *, int (*cmp)());
				; rdi = **begin_list, rsi = *data_ref, rdx = int (*cmp)()

_ft_list_remove_if:
	test	rdi, rdi
	jz	.error
	push	rbx		; save rbx
.start_remove_loop:
	mov	rax, qword [rdi]	; rax = *begin_list
	test	rax, rax
	jz	.end_start_remove_loop
	push	rdi		;;
	push	rsi		;; save parametrs
	push	rdx		;;
	mov	rdi, qword [rax]	; rdi = (*begin_list)->data
	call	rdx			; call cmp(rdi, rsi)
	pop	rdx		;;
	pop	rsi		;; checkout parametrs
	pop	rdi		;;
	test	rax, rax
	jnz	.end_start_remove_loop
					; Actually, the cycle-boby
	mov	rax, qword [rdi]	; rax = *begin_list
	mov	rbx, qword [rax + 8]	; rbx = (*begin_list)->next
	mov	qword [rdi], rbx	; *begin_list = (*begin_list)->next
	push	rdi
	push	rsi
	push	rdx
	mov	rdi, rax
	call	_free
	pop	rdx
	pop	rsi
	pop	rdi
	jmp	.start_remove_loop
.end_start_remove_loop:
	mov	rcx, qword [rdi]	; rcx = *begin_list
.middle_remove_loop:
	test	rcx, rcx
	jz	.end_middle_remove_loop
	mov	rax, qword [rcx + 8]	; rax = rcx->next
	test	rax, rax
	jz	.end_middle_remove_loop
	push	rdi		;; save rdi
	push	rsi		;;
	push	rdx		;;
	push	rcx		;;
	mov	rdi, qword [rax]	; rdi = rcx->next->data
	call	rdx			; call cmp()
	pop	rcx		;;
	test	rax, rax		; rax = cmp() retutn
	jnz	.cmp_false	
	mov	rdi, qword [rcx + 8]	; rdi = rcx->next
	mov	rax, qword [rdi + 8]	; rax = rcx->next->next
	mov	qword [rcx + 8], rax	; rcx->next = rax
	push	rcx
	call	_free
	pop	rcx
.cmp_false:
	pop	rdx
	pop	rsi
	pop	rdi
	mov	rcx, qword [rcx + 8]	; rcx = rcx->next
	jmp	.middle_remove_loop
.end_middle_remove_loop:
	pop	rbx		; checkout rbx
	ret
.error:
	ret
