bits 32 
global start        
extern exit               
import exit msvcrt.dll
segment data use32 class=data
segment code use32 class=code
    start:
        
        ;13/3
        mov ax,13
        mov cl,3
        div cl
   
        push    dword 0     
        call    [exit]       