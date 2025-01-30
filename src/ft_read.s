global ft_read
extern __errno_location

section .text

ft_read:
	mov rax, 0
	syscall

	test rax, rax
	js set_errno
	ret

set_errno:
	neg rax
	mov rdi, rax
	call __errno_location wrt ..plt
	mov [rax], edi
	mov rax, -1
	ret
