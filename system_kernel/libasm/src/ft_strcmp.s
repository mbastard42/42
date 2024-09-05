section .text

    global ft_strcmp

ft_strcmp:

    ; rdi = s1 | rsi = s2

    mov rbx, -1         ; neg = -1
    mov rcx, 1          ; pos = 1
    mov rdx, 0          ; nul = 0

    comp:

        mov al, byte [rdi]  ; tmp = *s1 
        sub al, byte [rsi]  ; tmp -= *s2
        cmp al, 0           ; tmp == 0
        jne end             ; if cmp = false => jump to end
        cmp byte [rdi], 0   ; *s1 == 0
        je end              ; cmp = true => jump to end
        cmp byte [rsi], 0   ; *s2 == 0
        je end              ; if cmp = true => jump to end
        inc rdi             ; s1++
        inc rsi             ; s2++
        jmp comp            ; loop

    end:

        test al, al         ;
        cmovs rax, rbx      ; if al < 0 => rax = neg
        cmovns rax, rcx     ; if al >= 0 => rax = pos
        cmove rax, rdx      ; if al == 0 => rax = nul
        ret
