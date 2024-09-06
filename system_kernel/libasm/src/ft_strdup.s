section .text

    global ft_strdup
    extern ft_strlen
    extern ft_strcpy
    extern malloc
    extern __errno_location

ft_strdup:

    ; rdi = str

    mov r9, rdi         ; hold = str
    call ft_strlen      ; len = ft_strlen(str)
    mov rdi, rax        ; rdi = len
    inc rdi             ; rdi++
    call malloc         ; ptr = malloc(rdi)
    test rax, rax       ;
    jz error            ;
    mov rdi, rax        ; rdi = ptr
    mov rsi, r9         ; rsi = hold
    call ft_strcpy      ;
    ret

    error:

        call __errno_location       ; rax = *errno
        mov dword [rax], 12         ; errno = ENOMEM
        mov rax, 0                  ; return = NULL
        ret
