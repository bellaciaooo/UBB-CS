;Exercitiul 4)
; Sa se construiasca o functie care intoarce suma atomilor numerici
; dintr-o lista, de la orice nivel.
;
; Modelul matematic
; suma(x) = - x, daca x este atom numeric
;           - 0, daca x este atom nenumeric
;           - (i=1...n) ∑ suma(xi), daca x este lista

(defun suma(x)
(cond
  ((numberp x) x)
  ((listp x) (apply '+(mapcar #'suma x)))
  (t 0)
)
)

(print (suma '(b 2 a (c 11 (f)) (3 1) 1 (b))))
; => 18