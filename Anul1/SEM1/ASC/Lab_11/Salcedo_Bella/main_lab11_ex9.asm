bits 32

global start 
       
extern exit
extern printf
extern scanf
extern get_val_hex               

import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    mesaj db "Introduceti sirul de cifre (dat in baza 16): ", 0
    format_sir db "%s", 0
    format_zec_semn db "Valoarea zecimala a numarului cu semn: %d", 0
    format_zec_fara db "Valoarea zecimala a numarului fara semn: %u", 10,13, 0
    
    max_len equ 30
    sir times max_len db 0
    

;   Se cere sa se citeasca de la tastatura un sir de numere, date in baza 16 (se citeste de la tastatura un sir de caractere si in memorie trebuie stocat un sir de numere). Sa se afiseze valoarea zecimala a nr atat ca numere fara semn cat si ca numere cu semn.    

segment code use32 class=code
    start:
        ; printf(mesaj)
        push dword mesaj    ; afisarea mesajului corespunzator
        call [printf]
        add esp, 4*1
        
        ; scanf(format_sir, sir) citire sir de cifre
        push dword sir      ; adresa unde stocam sirul
        push dword format_sir
        call [scanf]
        add esp, 4*2
        
        ; get_val_hex(sir) obtinem valoarea in hexazecimal a sirului de caractere cifre dat
        push dword sir      ; punem adresa de inceput a sirului pe stiva          
        call get_val_hex
        add esp, 4*1
        
        ; printf(format_zec_fara, ebx)
        push dword ebx  
        push dword format_zec_fara
        call [printf]
        add esp, 4*2
        
        ; printf(format_zec_semn, ebx)
        push dword ebx  
        push dword format_zec_semn
        call [printf]
        add esp, 4*2
        
        push    dword 0     
        call    [exit]  
        
        