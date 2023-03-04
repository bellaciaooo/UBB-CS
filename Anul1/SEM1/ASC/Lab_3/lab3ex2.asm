bits 32 
global start        
extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    a db 2
    b dw -3
    c dd 2
    d dq 7

segment code use32 class=code
    start:
        ;a - byte, b - word, c - double word, d - qword - Interpretare cu semn
        ;d-(a+b+c)-(a+a)
        ;(a+b+c)
        mov al, [a] ; AL = a
        cbw ; AX = a
        add ax, [b] ; AX = a + b 
        cwde ; EAX = a + b 
        add eax, [c] ; EAX = a + b + c
        ;d-(a+b+c)
        mov ebx, dword[d+0]
        mov ecx, dword[d+4]
        sub ebx, eax
        sbb ecx, 0
        ;(a+a)
        mov al, [a] ; AL = a 
        add al, [a] ; AL = a + a
        cbw ; AX = a + a
        cwde ; EAX = a + a
        ;d-(a+b+c)-(a+a)
        sub ebx, eax
        sbb ecx, 0
        push    dword 0      
        call    [exit]       
