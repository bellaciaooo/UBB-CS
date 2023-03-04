bits 32 
global start        
extern exit               
import exit msvcrt.dll
segment data use32 class=data
    a db 2
    b db 3
    c db 1
    g dw 5
segment code use32 class=code
    start:
        
        ;a,b,c-byte, g-word
        ;[(a+b+c)*2]*3/g
        mov al, [a]
        add al, [b]
        add al, [c]
        mov cl, 2
        mul cl
        mov cx, 3
        mul cx
        mov bx, [g]
        div bx        

        push    dword 0     
        call    [exit]       