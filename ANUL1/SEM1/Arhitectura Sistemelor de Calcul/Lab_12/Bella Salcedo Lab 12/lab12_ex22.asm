bits 32 

global _transformare        
            
segment data use32 class=data
    cifreHexa db "0123456789ABCDEF"

; functia in limbaj C    
; void convert(char* s,char* rezultat)
; {
    ; for (int i = 0; i<8; i++)
    ; {
        ; int cifHex = 0;
        ; cifHex *= 2;
        ; cifHex += s[i*4]-'0';
        ; cifHex *= 2;
        ; cifHex += s[i*4+1]-'0';
        ; cifHex *= 2;
        ; cifHex += s[i*4+2]-'0';
        ; cifHex *= 2;
        ; cifHex += s[i*4+3]-'0';
        ; rezultat[i] = cifreHexa[cifHex];
    ; }
    ; rezultat[8] = 0;
; }

segment code use32 class=code
_transformare:
    ; [ebp + 8] = s , [ebp + 12] = rezultat
    push ebp
    mov ebp, esp
    sub esp, 4            ; rezervam spatiu pt adresa sirului de caractere
    
    pushad                ; punem registrii pe stiva
    
    mov esi, [ebp + 8]    ; mutam in ESI adresa sirului "s"
    mov edi, [ebp + 12]   ; mutam in EDI adresa sirului "rezultat"
    mov ecx, 8
    cld
repeta:
    mov bl, 0 ; construim cifHex
    shl bl, 1 ; inmultim cu 2
    lodsb ; AL = s[i], i++
    sub al, '0'
    add bl, al
    shl bl, 1 ; inmultim cu 2
    lodsb ; AL = s[i], i++
    sub al, '0'
    add bl, al
    shl bl, 1 ; inmultim cu 2
    lodsb ; AL = s[i], i++
    sub al, '0'
    add bl, al
    shl bl, 1 ; inmultim cu 2
    lodsb ; AL = s[i], i++
    sub al, '0'
    add bl, al
    mov al, bl
    mov ebx, cifreHexa
    xlat   ; AL = cifreHexa[AL]
    stosb  ; rezultat[i++] = al    
    loop repeta
    
    mov al, 0 
    stosb
    
    popad   ;restauram registrii
    
    mov esp, ebp
    pop ebp
    
    ret
    
    
    