; Un arbore binar se memoreaza (radacina (lista-subarbore-1)(lista-subarbore-2)).
; Sa se determine lista nodurilor de pe nivelul k din arbore. Nivelul radacinii se considera 0. 
; ex: (A (B) (C)) 0 -> (A)

; Modelul matematic
; noduri(a1...an, k, niv) = - [], daca n = 0
;                           - [a1], daca k = niv
;                           - noduri(a2), daca n = 2
;                           - noduri(a2) U noduri(a3) , daca n = 3

; a1a2...an = reprezinta arborele dat
; k = reprezinta nivelul de pe care dorim nodurile din arbore
; niv = reprezinta nivelul curent la care ne aflam in arbore, o sa inceapa de la 0 initial

(defun noduri (arbore k niv)
(cond
  ((null arbore) nil)
  ((= k niv) (list(car arbore)))
  (t (append (noduri (car (cdr arbore)) k (+ 1 niv)) (noduri (car (cddr arbore)) k (+ 1 niv))))
)
)

;(print (noduri '(A (B) (C)) '1 '0))
; => (B C)

;functie principala
; Modelul matematic
; noduriNivel(a1...an,k) = noduri(a1...an,k,niv)
;
; a1a2...an = reprezinta arborele dat
; k = reprezinta nivelul de pe care dorim nodurile din arbore
; niv = reprezinta nivelul curent la care ne aflam in arbore, o sa inceapa de la 0 initial

(defun noduriNivel (arbore k)
  (noduri arbore k 0))

(print (noduriNivel '(A (B) (C (D) (E))) '1))


;(print (noduriNivel '(A (B) (C)) '0))
; => (A) 

;(print (noduriNivel '(A (B (F)) (C (G (R)) (H))) '2))
; => (F G H)