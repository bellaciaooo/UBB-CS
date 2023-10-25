bits 32 
global start        
extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    a dd 9
    b db 1
    c db 1
    x dq -4

segment code use32 class=code
    start:
        ; a-doubleword b,c-byte x-qword
        ;(a+b)/(2-b*b+b/c)-x Interpretarea cu semn
        ;(a+b)
        mov ebx, [a] ; EBX = a
        mov al, [b] ; AL = b
        cbw ; AX = b
        cwde ; EAX = b
        add ebx, eax ; EBX = a + b
        ;(2-b*b+b/c)
        mov al, [b]   
        imul byte [b] ; AX = b * b
        mov edx, 2
        sub dx, ax ; DX = 2 - b * b
        mov al, [b] ; AL = b
        cbw ; AX = b
        idiv byte [c] ; AL= b / c 
        mov ah, 0 ; scapam de restul din AH in caz ca e
        add dx, ax ; DX= 2 - b * b + b / c
        ;(a+b)/(2-b*b+b/c)
        mov eax, ebx ; EAX = a + b
        mov ecx, edx ; ECX = 2 - b * b + b / c
        mov edx, 0
        idiv ecx ;EAX =(a+b)/(2-b*b+b/c)
        ;(a+b)/(2-b*b+b/c)-x
        cdq ; EDX:EAX = (a+b)/(2-b*b+b/c)
        mov ebx, dword[x+0]
        mov ecx, dword[x+4]
        sub eax, ebx
        sbb edx, ecx
        push    dword 0      
        call    [exit]   