bits 32
 
global get_val_hex    
         
segment code use32 class=code
    get_len:
        mov edi, [esp + 4] ; mutam in registrul EDI offset-ul string-ului la care ne trebuie sa aflam lungimea
        xor eax, eax       ; golim registrul EAX sa punem in el rezultatul si pt a lucra cu scan
        mov ecx, 0x03fff   ; valoarea maxima limita pe care o poate avea lungimea
        cld                ; DF = 0
        repne scasb        ; cmp AL, <ES:EDI>  (while ECX != 0 or ZF != 1)
        sub ecx, 0x03fff   ; scadem din ecx valoarea maxima pe care am pus-o initial
        neg ecx            ; rezultatul scaderii o sa fie lungimea actuala, dar negativa => trebuie negata
        dec ecx            ; decrementam cu o valoare pt rep-ul care a mers cu una in plus
        mov eax, ecx       ; lungimea va fi salvata in eax    
        
        ret 4*1
    
    get_inmultit_16:
        mov ecx, [esp + 4] ; mutam in registrul ECX valoarea puterii la care trebuie ridicat nr 16
        mov eax, 1
        jecxz final2
        xor edx, edx
        mov ebx, 16
        repeta2:
            mul ebx        ; EDX:EAX <= EAX * EBX (facem inmultirea cu 16)
            loop repeta2
        ; produsul dorit se va afla in EAX
        final2:
        ret 4*1
    
    get_val_hex:
        mov esi, [esp + 4] ; mutam in registrul ESI valoarea offset-ului sirului de caractere cifre dat 
      
        ; get_len(sir) aflam lungimea string-ului nostru
        push dword esi     ; punem pe stiva offset-ul sirului de caractere
        call get_len
       
        ; incepem conversia din string in hex
        mov ecx, eax       ; punem in registrul ECX lungimea string-ului
        dec eax            ; decrementam lungimea string-ului ca sa putem obtine puterea produsului pentru construirea numarului
        push ecx
        push eax
        call get_inmultit_16
        pop ecx
        mov edi, eax       ; punem in registrul EDI produsul cu care vom inmulti cifrele
        jecxz final
        xor eax, eax       ; golim registrul EAX
        xor edx, edx       ; golim registrul EDX
        xor ebx,ebx        ; golim registrul ca sa construim numarul in el  
    repeta:
        mov al, [esi]      ; mutam in AL primul caracter din sir
        ; verificam daca caracterul e cifra hexazecimala sau decimala        
        cmp al, '9'
        ja e_cifra_hex
        cmp al, '0'
        jb e_cifra_hex
        ; daca nu s-a efectuat niciun jump => e cifra decimala
        sub al,'0'         ; transformam din caracter in cifra
        jmp continua
    
    e_cifra_hex:
        sub al, 'a'        ; transformam din caracter in cifra
        add al, 10       
        
    continua: 
        push ecx
        mov ecx, edi       ; ECX <= EDI (produsul de inmultit pentru construirea numarului)
        mul ecx            ; EDX:EAX <= EAX * ECX
        add ebx, eax       ; construim numarul in EBX
        pop ecx            
        shr edi, 4         ; impartim produsul din EDI la 16 
        inc esi            
        loop repeta
    
    final:    
        ret 