bits 32 
global start        
extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    a db 1
    b dw 2
    c dd 1
    d dq 7
segment code use32 class=code
    start:
        ;a - byte, b - word, c - double word, d - qword - Interpretare fara semn
        ;(d-c)+(b-a)-(b+b+b)
        ;(d-c)
        mov eax, dword [d+0]
        mov edx, dword [d+4]
        mov ebx, dword [c]
        sub eax, ebx
        sbb edx, 0
        ;(b-a)
        mov ebx, 0
        mov bx, [b]
        mov cl, [a]
        mov ch, 0
        sub bx, cx
        ;(d-c)+(b-a)
        add eax, ebx
        ;(b+b+b)
        mov ebx, 0
        mov bx, [b]
        mov ecx, 0
        mov cx, [b]
        add ebx, ecx
        add ebx, ecx
        ;(d-c)+(b-a)-(b+b+b)
        sub eax, ebx 
        push    dword 0      
        call    [exit]       
