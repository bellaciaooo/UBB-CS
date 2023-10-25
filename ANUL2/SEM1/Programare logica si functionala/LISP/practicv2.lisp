; Un arbore binar se memoreaza (radacina (lista-subarbore-1)(lista-subarbore-2)).
; Sa se determine lista nodurilor de pe nivelul k din arbore. Nivelul radacinii se considera 0. 
; ex: (A (B) (C)) 0 -> (A)

; Modelul matematic
; nivel(a1...an, k ,niv) = - [] ,daca n = 0
;                          - [a1] ,daca k = niv si a = lista 
;                          - nivel(a2, k, niv+1), daca n = 2
;                          - nivel(a2, k, niv+1) U nivel(a3, k ,niv+1), daca k!=niv si n = 3
;                          //- i=2,n U nivel(ai, k, niv+1), unde a = lista si k!= niv

; a = arborele
; k = nivelul de pe care se cer nodurile
; niv = nivelul curent, initial 0

(defun nivel(arbore k niv)
(cond
 ((null arbore) nil)
 ((= k niv) (list (car arbore)))
 (t (mapcan #'(lambda (i) (nivel i k (+ 1 niv))) (cdr arbore)))
)
)

; noduriNivel(arbore k) = nivel(arbore k 0)
(defun noduriNivel(arbore k)
  (nivel arbore k 0)
)

(print (noduriNivel '(A (B (F (G) (H))) (C (L)) (D (M)) (E (N))) '2))

