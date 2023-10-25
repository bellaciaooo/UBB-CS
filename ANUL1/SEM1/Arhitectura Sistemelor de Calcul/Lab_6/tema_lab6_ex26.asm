bits 32 
global start      
  
extern exit               
import exit msvcrt.dll

segment data use32 class=data
    s dd 12345678h, 1A2B3C4Dh, 0FE98DC76h 
    len equ ($-s)/4
    d times len db 0
    zece db 10

;Se da un sir de dublucuvinte. Sa se obtina sirul format din octetii superiori ai cuvintelor inferioare din elementele sirului de dublucuvinte, care sunt multiplii de 10.

segment code use32 class=code
    start:
        mov esi, s
        cld
        mov ecx, len
        jecxz final
        mov edi, 0
    repeta: 
        lodsb
        lodsb
        add esi, 2
        mov bl, al
        mov ah, 0
        ;mov dl, 10
        ;div dl
        
        div byte[zece]
        cmp ah, 0
        
        jz multiplu10
        jmp mai_departe
       
    multiplu10:
        mov [d+edi], bl 
        inc edi

    mai_departe:
    
    loop repeta
    
    final:
        push dword 0        
        call [exit]         