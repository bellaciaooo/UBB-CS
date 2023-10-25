bits 32
global start

extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data
    a dd 0
    b dd 0
    k dd 3
    messa db "Introduceti valoarea lui 'a': ", 0
    messb db "Introduceti valoarea lui 'b': ", 0
    messfinal db "Rezultatul calculului (a+b)*k cu k = %d este: %d ", 0
    format db "%d",0
    string db "pause",0
    
;Se citesc de la tastatura doua numere a si b. Sa se calculeze valoarea expresiei (a+b)*k, k fiind o constanta definita in segmentul de date. Afisati valoarea expresiei (in baza 10).


segment code use32 class=code
    start:
        ; vom apela printf(messa) => se va afisa "Introduceti valoarea lui 'a': "
        push dword messa
        call [printf]
        add esp, 4*1
        
        ; vom apela scanf(format, a) => se va citi un numar in variabila a
        push dword a
        push dword format
        call [scanf]
        add esp, 4*2
        
        ; vom apela printf(messb) => se va afisa "Introduceti valoarea lui 'b': "
        push dword messb
        call [printf]
        add esp, 4*1
        
        ; vom apela scanf(format, b) => se va citi un numar in variabila b
        push dword b
        push dword format
        call [scanf]
        add esp, 4*2
        
        ; vom calcula valoarea expresiei (a+b)*k in registrul EAX
        mov eax, [a]
        add eax, [b]
        imul dword[k]           
  
        ; vom apela printf(messfinal2, k, eax) => se va afisa "Rezultatul calculului (a+b)*k cu k = %d este: %d "
        push dword eax
        push dword [k]
        push dword messfinal
        call [printf]
        add esp, 4*3      
       
        push dword 0        ; push the parameter for exit onto the stack
        call [exit]         ; call exit to terminate the program
        
        
        
 
        