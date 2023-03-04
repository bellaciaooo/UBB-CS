bits 32 
global start        
extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    a dd 7
    b db 1
    c db 1
    x dq 2

segment code use32 class=code
    start:
        ; a-doubleword b,c-byte x-qword
        ;(a+b)/(2-b*b+b/c)-x Interpretarea fara semn
        ;(a+b)
        mov eax, [a] ; EAX = a
        mov ebx, 0 ; EBX = 0
        mov bl, [b] ; EBX = b
        add ebx, eax ; EBX = a + b
        ;(2-b*b+b/c)
        mov al, [b]
        mul byte [b] ; AX = b * b
        mov edx, 2
        sub dx, ax ; DX = 2 - b * b
        mov ah, 0
        mov al, [b]
        div byte [c] ; AL= b / c 
        mov ah, 0 ; scapam de restul din AH in caz ca e
        add dx, ax ; DX= 2 - b * b + b / c
        ;(a+b)/(2-b*b+b/c)
        mov eax, ebx ; EAX = a + b
        mov ecx, edx ; ECX = 2 - b * b + b / c
        mov edx, 0
        div ecx ;EAX =(a+b)/(2-b*b+b/c)
        ;(a+b)/(2-b*b+b/c)-x
        mov edx, 0
        mov ebx, dword[x+0]
        mov ecx, dword[x+4]
        sub eax, ebx
        sbb edx, ecx
        push    dword 0      
        call    [exit]   