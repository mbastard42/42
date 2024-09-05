section .text

    global ft_strlen

ft_strlen:
    
    ; rdi = str

    xor rcx, rcx    ; count = 0

    count:

        cmp byte [rdi], 0   ; *str = 0
        je end              ; if cmp = true => jump to end
        inc rdi             ; str++
        inc rcx             ; count++
        jmp count           ; loop

    end:

        mov rax, rcx        ; return = count
        ret
