;Exercitiul 14)
; Definiti o functie care da adancimea unui arbore n-ar reprezentat sub forma:
; (radacina lista_noduri_subarb1...lista_noduri_subarbn)
; Ex: adancimea arborelui este (a (b (c)) (d) (e (f))) este 3
;            a
;         /  |  \
;        b   d   e
;       /       /
;      c       f
;
; Modelul matematic
; adancime(arbore) = 
;           - 0 , daca arborele este lista vida
;           - 1 + max(adancime(subarbore_1),adancime(subarbore_2)...adancime(subarbore_n) , altfel
;

(defun adancime(arbore)
(cond
   ((null arbore) 0)
   (t (+ 1 (apply #'max (mapcar #'adancime (cdr arbore))))))
)

(print (adancime '(a (b (c)) (d) (e (f)))))
