global ft_strcpy

section .text

ft_strcpy:
	mov rax, rdi

strcpy_loop:
	mov dl, byte [rsi]
	mov byte [rdi], dl
	test dl, dl
	je strcpy_done
	inc rsi
	inc rdi
	jmp strcpy_loop

strcpy_done:
	ret;
