bits 32 
global start        
extern exit               
import exit msvcrt.dll    
segment data use32 class=data
    a dw 0111011101010111b
    b dw 1001101110111110b
    c dd 0

segment code use32 class=code
    start:
        ;Se dau cuvintele A si B. Se cere dublucuvantul C:
        ;   bitii 0-3 ai lui C coincid cu bitii 5-8 ai lui B
        ;   bitii 4-8 ai lui C coincid cu bitii 0-4 ai lui A
        ;   bitii 9-15 ai lui C coincid cu bitii 6-12 ai lui A
        ;   bitii 16-31 ai lui C coincid cu bitii lui B
        
        ; bitii 0-3 ai lui C coincid cu bitii 5-8 ai lui B
        mov eax, 0 ; golim tot ce e in eax 
        mov ebx, 0 ; in registrul ebx vom calcula rezultatul
        mov ax, [b] ; ax = b
        and ax, 0000011110000000b ; izolam bitii 5-8 ai lui B
        rol eax, 21 ; mutam bitii pe pozitiile 0-3
        or ebx, eax ; punem bitii in rezultat
        
        ; bitii 4-8 ai lui C coincid cu bitii 0-4 ai lui A
        mov eax, 0
        mov ax, [a] ;izolam bitii 0-4 ai lui A
        and ax, 1111100000000000b
        rol eax, 12 ; mutam bitii pe pozitiile 4-8 in eax
        or ebx, eax ; punem bitii in rezultat
        
        ; bitii 9-15 ai lui C coincid cu bitii 6-12 ai lui A
        mov eax, 0
        mov ax, [a]
        and ax, 0000001111111000b
        rol eax, 13 ; mutam bitii pe pozitiile 9-15 in eax
        or ebx, eax ; punem bitii in rezultat
        
        ; bitii 16-31 ai lui C coincid cu bitii lui B
        mov eax, 0
        mov ax, [b]
        or ebx, eax
        
        mov [c], ebx
        
        push    dword 0       
        call    [exit]       
