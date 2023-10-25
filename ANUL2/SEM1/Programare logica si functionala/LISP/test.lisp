;(+ 2 3) 
;(print "hello world")
;(print (+ 2 3))

;(defun hello-name (name) (format nil "Hello ~A" name))
;(print (hello-name 'bella))

;functie pentru suma superficiala a elementelor unei liste

;Modelul matematic
;suma(l1l2...ln) = 0 , daca lista este vida
;                  l1 + suma(l2...ln), daca l1 = atom numeric
;                  suma(l2..ln), altfel


(defun suma(l)
 ; forma COND – forma condițională: permite ramificarea prelucrărilor
 (cond
 ; prima conditie daca lista este vida
 ((null l) 0)
 ; a doua conditie daca este atom numeric, NUMBERP – returnează T dacă argumentul e număr
 ((numberp (car l)) (+ (car l) (suma (cdr l))))
 ; conditia de altfel
 (t (suma (cdr l)))
 )
)

(print (suma '(1 (2 (3 4) 5) 1 3 4)))

;model matematic
; ce (e) = true, daca e este atom numeric
;          nil, altfel

(defun ce (e)
 (cond 
  ((numberp e) t)
 )
)

(print (ce 'x))