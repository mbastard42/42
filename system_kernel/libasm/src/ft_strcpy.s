section .text

    global ft_strcpy

ft_strcpy:

    ; rdi = dst | rsi = src

    mov rbx, rdi    ; hold = dst

    copy:

        cmp byte [rsi], 0   ; *src == 0
        je end              ; if cmp = true => jump to end
        mov al, byte [rsi]  ; tmp = *src
        mov byte [rdi], al  ; *dst = tmp
        inc rdi             ; dst++
        inc rsi             ; src++
        jmp copy            ; loop

    end:

        mov byte [rdi], 0   ; *dst = 0
        mov rax, rbx        ; return = hold
        ret
