bits 32 
global start        
extern exit               
import exit msvcrt.dll
segment data use32 class=data
    a db 12
    b db 2
    c db 7
    d db 3
segment code use32 class=code
    start:
        
        ;a,b,c,d - byte
        ;(a+a)-(c+b+d)
        mov al, [a]
        add al, [a]
        mov cl, [c]
        add cl, [b]
        add cl, [d]
        sub al,cl
        push    dword 0     
        call    [exit]       