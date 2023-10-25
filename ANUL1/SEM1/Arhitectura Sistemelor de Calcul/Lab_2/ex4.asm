bits 32 
global start        
extern exit               
import exit msvcrt.dll
segment data use32 class=data
    a db 3
    b db 2
    c db 5
    d dw 7
segment code use32 class=code
    start:
        
        ;a,b,c - byte, d - word
        ;(50-b-c)*2+a*a+d
        mov al, 50
        sub al, [b]
        sub al, [c]
        mov cl, 2
        mul cl
        mov cx, ax
        mov al, [a]
        mul al
        add cx, ax
        add cx, [d]
        push    dword 0     
        call    [exit]       