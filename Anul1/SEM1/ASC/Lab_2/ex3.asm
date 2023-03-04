bits 32 
global start  
extern exit               
import exit msvcrt.dll
segment data use32 class=data
    a dw 11
    b dw 3
    c dw 5
segment code use32 class=code
    start:
    ;a,b,c - word
    ;b-(b+c)+a
    mov ax, [b]
    mov cx, [b]
    add cx, [c]
    sub ax,cx
    add ax, [a]
    
    push    dword 0     
    call    [exit]  