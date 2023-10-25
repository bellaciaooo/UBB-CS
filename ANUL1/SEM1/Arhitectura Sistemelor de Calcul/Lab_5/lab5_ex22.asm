bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
	s1 db 1, 3, 6, 2, 3, 7
    s2 db 6, 3, 8, 1, 2, 5
    len equ $-s1
    d times len db 0

;Se dau 2 siruri de octeti S1 si S2 de aceeasi lungime. Sa se construiasca sirul D astfel incat fiecare ;element din D sa reprezinte minumul dintre elementele de pe pozitiile corespunzatoare din S1 si S2.

segment code use32 class=code
    start:
        mov ecx, len
        mov esi, 0
        jecxz final
    repeta:
        mov al, [s1+esi]
        mov ah, [s2+esi]
        cmp al, ah
        ja s2_mai_mic
        mov [d+esi], al
        jmp mai_departe
    s2_mai_mic:
        mov [d+esi], ah
    mai_departe:
        inc esi        
    loop repeta        
    final:
        push dword 0        
        call [exit]        