;Exercitiul 12) Sa se construiasca lista nodurilor unui arbore de tipul (2) parcurs in preordine.
; tipul (2) : (A (B) (C (D) (E)))
; preordine-RSD-se parcurge mai intai radacina (R),apoi subarborele stang (S), apoi subarborele 
; drept (D)

; Modelul matematic
; preordine(l1...ln) = - ∅ ,daca l este vida
;                      - [l1] , daca n=1
;                      - l1 U preordine(l2), daca n=2
;                      - l1 U preordine(l2) U preordine(l3) ,altfel
;
; l : lista nodurilor unui arbore de tipul(2) care urmeaza sa fie parcurs in preordine

(defun preordine(lista)
(cond
  ((null lista) nil)
  (t(append (list (car lista)) (preordine (cadr lista)) (preordine (caddr lista))))
)
)

(print (preordine '(A (B) (C (D) (E)))))
; => A B C D E