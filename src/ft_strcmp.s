global ft_strcmp

section .text

ft_strcmp:
	xor rax, rax

strcmp_loop:
	mov al, byte [rdi]
	mov dl, byte [rsi]
	sub al, dl
	jne strcmp_done
	test al, al
	je strcmp_done
	inc rdi
	inc rsi
	jmp strcmp_loop

strcmp_done:
	movsx rax, al
	ret
