bits 32
global start

extern exit, printf, fopen, fscanf, fclose
import exit msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fscanf msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    frecv times 256 db 0            ; vectorul de frecventa a caracterelor din fisier
    
    descr_fis dd -1                 ; descriptorul fisierului
    mod_acces db "r", 0             ; modul de acces la fisier
    nume_fisier db "sir_de_caractere.txt", 0   ; numele fisierului
    
    c db 0                          ; caracterul citit din fisier
    format db '%c', 0               ; formatul de citire din fisier
    nr_aparitii_max db 0
    carac_max db 0
    mesaj db "Caracterul %c apare de %d ori", 0
    
;Se da un fisier text. Sa se citeasca continutul fisierului, sa se determine caracterul special (diferit de litera) cu cea mai mare frecventa si sa se afiseze acel caracter, impreuna cu frecventa acestuia. Numele fisierului text este definit in segmentul de date.
    
segment code use32 class=code
    start:
        ; apelam functia fopen() pentru a deschide fisierul
        ; functia va returna in EAX descriptorul fisierului sau 0 in caz de eroare
        ; eax = fopen(nume_fisier, mod_acces)
        push dword mod_acces     
        push dword nume_fisier
        call [fopen]
        add esp, 4*2

        ; verificam daca functia fopen a deschis cu succes fisierul (EAX != 0)
        cmp eax, 0
        je final                    ; daca a aparut o eroare (EAX = 0), terminam executia programului
    
        ; stocam descriptorul de fisier (valoarea returnata de functia fopen())
        mov [descr_fis], eax
    
        ; citim caracterele din fisier unul cate unul
        mov ecx, 300            ; citim maximum 300 de caractere
        cld
       
    citire:
        ; apelam functia fscanf() pentru a citi din fisier
        ; functia va returna in EAX valoarea 1 (daca a citit cu succes un caracter din fisier) sau 0 in caz de eroare
        ; eax = fscanf(descr_fis, format, c)
        push dword c                ; adresa la care stocam caracterul citit
        push dword format           ; formatul de citire
        push dword [descr_fis]      ; descriptorul fisierului
        call [fscanf]
        add esp, 4*3
        
        cmp eax, 1                  ; verificam daca citirea a avut loc cu succes (EAX = 1)
        jne stop                    ; in caz contrar (EAX != 1), incheiem citirea
        
        ;verificam daca caracterul c este litera
        mov al, [c]                 
        cmp al, 'a'                 ; verificam daca c >= 'a'
        jae verificam_litera_mica
        jmp verificam_litera_mare
        
    verificam_litera_mica:          ; stim ca c >= 'a'
        cmp al, 'z'                 ; verificam daca c <= 'z'
        jna citire                  ; daca c <= 'z' trecem la urmatoarea citire
        
    verificam_litera_mare:
        cmp al, 'A'                 ; verificam daca c >= 'A'
        jae verificam_litera_mare2
        jmp memorare
       
    verificam_litera_mare2:         ; stim ca c >= 'A'
        cmp al, 'Z'                 ; verificam daca c <= 'Z'
        jna citire                  ; daca c <= 'Z' trecem la urmatoarea citire
        
    memorare:                       ; stim ca c nu este litera 
        mov eax, 0
        mov al, [c]
        inc byte[frecv + eax]       ; incrementam nr de aparitii a caracterului c
        
    actualizare_maxim:
        mov bl, byte[nr_aparitii_max]
        cmp byte[frecv + eax], bl     ; comparam nr curent de aparitii al caract curent cu nr de aparitii maxim
        jle continua                  ; daca e mai mic sau egal cu nr de aparitii maxim trecem mai departe
        mov bl, [frecv + eax]         
        mov [nr_aparitii_max], bl     ; daca e mai mare decat nr de aparitii maxim acesta se actualizeaza
        mov bl, [c]
        mov [carac_max], bl           ; de asemenea si caracterul cu nr de aparitii maxim 
         
    continua:
        
        dec ecx                       
        cmp ecx, 0
        jg citire
     
    stop:
        
        ; apelam functia fclose() pentru a inchide fisierul
        ; fclose(descr_fis)
        push dword [descr_fis]
        call [fclose]
        add esp, 4*1
        
        ; afisam caracterul special (diferit de litera) cu cea mai mare frecventa impreuna cu nr sau de aparitii
        mov eax, 0
        mov al, [nr_aparitii_max]
        push eax
        mov eax, 0
        mov al, [carac_max]
        push eax
        push dword mesaj
        call [printf]
        add esp, 4*3
    
    final:
        ; exit(0)
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
        
        
        