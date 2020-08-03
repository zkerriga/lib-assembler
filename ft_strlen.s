section .text

global ft_strlen

ft_strlen:
	mov	rax, rdi
cycle:
	cmp	byte [rax], 0
	je	endcycle
	inc	rax
	jmp	cycle
endcycle:
	sub	rax, rdi
	ret
