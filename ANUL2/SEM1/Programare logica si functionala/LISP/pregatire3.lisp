;1)Se da un arbore n-ar (are cel mult n fii) reprezentat sub forma (radacina (subarbore 1) (subarbore 2) ... 
; (subarbore n)). Sa se determine nr total al nodurilor dispuse pe nivele pare.

; Modelul matematic
; suma(x, niv) = - 0, daca n = 0
;                - 1, x = atom, niv = nr par
;                - i=1,n Σ suma(xi, niv + 1), x = lista si x != lista vida 
;                - 0, altfel

; sumaPrincipala(x) = suma(x, 0) 
;incepem cu 0 pentru ca o sa creasca si radacina este pe nivelul 1 si o sa se sara un nivel

(defun suma(x niv)
(cond
  ((null x) nil)
  ((and (atom x) (= (mod niv 2) 0)) 1)
  ((listp x) (apply #'+(mapcar #'(lambda (i) (suma i (+ niv 1))) x)))
  (t 0)
)
)

;(print (suma '(a (b (c)) (d) (e (f))) '0))
;=>3


;2) Sa se numere toate sublistele unei liste (inclusiv lista insasi daca este cazul) pentru care primul atom
; numeric, indiferent de nivel este 5.
; ex: (A (B (C 5) 1) (A 1 5) 5) => 3
;            ---
;        -----------
;     -------------------------
; Presupunem ca avem functia care verifica conditia ca sa se numere sublistele

; Modelul matematic - luam doar atomii numerici intr-o lista
; liniarizeaza(x) = - [], daca x = atom nenumeric
;                   - [x], daca x = atom numeric
;                   - i=1,n U liniarizeaza(li) , daca x = lista
;
; mapcan face append pe fiecare rezultat al functiei apelate pe fiecare argument al listei

(defun liniarizeaza(x)
(cond
  ((numberp x) (list x))
  ((atom x) nil)
  (t (mapcan #'liniarizeaza x))
)
)

; Modelul matematic
; verifica(l) = - T, daca n > 0 si l1' = 5 unde l1'...ln' = liniarizeaza(l)
;               - F, altfel

(defun verifica(l)
  (equal (car (liniarizeaza l)) 5)
)

; Modelul matematic
; numara(l) = - 0, daca l = atom
;             - 1 + i=1,n Σ numara(li), daca l = lista si verifica(l) = T
;             - i=1,n Σ numara(li), daca l = lista si verifica(l) = F

(defun numara(l)
(cond
  ((atom l) 0)
  ((and (listp l) (verifica l)) (+ 1 (apply '+ (mapcar #'numara l))))
  (t (apply #'+(mapcar #'numara l)))
)
)

(print (numara '(A (B (C 5) 1) (A 1 5) 5)))