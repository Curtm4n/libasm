global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc

section .text

ft_strdup:
	test rdi, rdi
	jz return_null

	push rdi
	call ft_strlen
	inc rax

	mov rdi, rax
	call malloc wrt ..plt
	test rax, rax
	jz restore

	pop rdi
	mov rsi, rdi
	mov rdi, rax
	call ft_strcpy

	ret

restore:
	pop rdi

return_null:
	xor rax, rax
	ret
