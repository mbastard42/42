section .text

    global ft_read
    extern __errno_location

ft_read:

    ; rdi = fd | rsi = buf | rdx = count

    mov rax, 0              ; rax = 1 => syscall = red
    syscall                 ; write(rdi, rsi, rdx) => rax = error code
    test rax, rax           ;
    js error                ; if rax < 0 => jump to error label
    ret

    error:

        mov rbx, rax            ; tmp = write error code
        neg rbx                 ; tmp *= -1
        call __errno_location   ; rax = *errno
        mov [rax], rbx          ; errno = tmp
        mov rax, -1
        ret
