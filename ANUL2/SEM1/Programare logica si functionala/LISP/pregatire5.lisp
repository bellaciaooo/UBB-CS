;1)atomi nenumerici care apar de un nr par de ori intr o lista
;(F A 2 3 (B 1 (A D 5) C C (F)) 8 11 D (A F) F) => (C D F)

;Modelul matematic => functie care da atomi nenumerici a unei liste neliniare intr o lista liniara
;liniarizeaza(x) = - [], daca x = atom numeric
;                  - [x], daca x = atom nenumeric
;                  - i=1,n U liniarizeaza(xi), daca x = lista si n > 0

(defun liniarizeaza (x)
(cond
  ((numberp x) nil)
  ((atom x) (list x))
  (t (mapcan #'liniarizeaza x))
)
)

;(print (liniarizeaza '(F A 2 3 (B 1 (A D 5) C C (F)) 8 11 D (A F) F)))
; => (F A B A D C C F D A F F) 

;Modelul matematic =>functie care verifica daca nr de aparitii al unui element intr o lista este par
;verifica(e, l1...ln) = - 0, daca n=0
;                       - 1 + verifica(e, l2...ln), daca e = l1 si n>0
;                       - verifica(e, l2...ln), daca e != l1 si n>0

(defun verifica(e l)
(cond
  ((null l) 0)
  ((equal e (car l)) (+ 1 (verifica e (cdr l))))
  (t (verifica e (cdr l)))
)
)

;(print (verifica 'A '(F A B A D C C F D A F F)))
; => 3

;Modelul matematic
; invp(l1...ln, r , e) = - [], daca n = 0
;                 - invp(l2...ln, r+l1, e), daca verifica(l1 l)%2 = 0 si verifica(l1, r) = 0 
;                    si verifica(l1, e) = 0
;                 - invp(l2...ln,r, e+l1) , altfel

(defun invp (l r e)
(cond
  ((null l) r)
  ((and (= (mod (verifica (car l) l) 2) 0) (= (verifica (car l) r) 0) (= (verifica (car l) e) 0)) 
  (invp (cdr l) (append (list (car l)) r) e))
  (t (invp (cdr l) r (append e (list (car l)))))
)
)

(defun fctPrincipala (l)
  (invp (liniarizeaza l) () ())
)

;(print (fctPrincipala '(F A 2 3 (B 1 (A D 5) C C (F)) 8 11 D (A F) F)))
; => (C D F)

;2)substituie un elem e cu e1 la orice nivel impar al unei liste neliniare.
; ex: (1 d (2 d (d))), e = d, e1 = f
; =>  (1 f (2 d (f)))

(defun substituie(e e1 l niv)
(cond
  ((null l) nil)
  ((and (equal l e) (= (mod niv 2) 1)) e1)
  ((listp l) (mapcar #'(lambda (i) (substituie e e1 i (+ niv 1))) l))
  (t l) 
)
)

;(print (substituie 'd 'f '(1 d (2 d (d))) 0))
;=> (1 F (2 D (F))) 

;3)se verifica daca un nod x apare pe un nivel par in arbore sau nu
;(a (b (g)) (c (d (e))) (f))) , x = g => T, x = h => Nil

(defun verificaNod(a x niv)
(cond
  ((null a) nil)
  ((and (equal a x) (= (mod niv 2) 0)) (list t))
  ((listp a) (mapcan #'(lambda (i) (verificaNod i x (+ niv 1))) a))
  (t nil)
)
)

(defun verificaNodP(a x)
 (car (verificaNod a x -1))
)

;(print (verificaNodP'(a (b (g)) (c (d (e))) (f)) 'h))

;4)calea de la radacina la nodul dat
; (a (b (g)) (c (d (e)) (f)))
; nod = e => (a c d e)
; nod = v => ()

(defun calea(a nod c)
(cond
  ((null a) nil)
  ((equal a nod) c)
  ((listp a) (mapcan #' (lambda (i) (calea i nod (append c (list (car a))))) a))
  (t nil)
))

;(print (calea '(a (b (g)) (c (d (e)) (f))) 'e '()))

;5) sa se inlocuiasca nodurile de pe nivelul k cu o valoare e data, niv rad = 0

(defun inlocuire(a e k niv)
(cond
  ((null a) nil)
  ((and (atom a) (= niv k)) e)
  ((and (atom a) (not (= niv k))) a)
  ((listp a) (mapcar #' (lambda (i) (inlocuire i e k (+ niv 1))) a))
  (t nil)
)
)

;(print (inlocuire '(a (b (g)) (c (d (e)) (f))) 'h 2 -1))
; => (A (B (H)) (C (H (E)) (H))) 

;(print (inlocuire '(a (b (g)) (c (d (e)) (f))) 'h 4 -1))
; => (A (B (G)) (C (D (E)) (F)))

;6) se elimina atomii de pe nivelul k, niv artificial= 1

(defun elimina(l k niv)
(cond
  ((null l) nil)
  ((and (atom l) (not (= niv k))) (list l))
  ((listp l) (list (mapcan #' (lambda (i) (elimina i k (+ niv 1))) l)))
  (t nil)
)
)

(defun eliminaPrincipal(l k)
 (car (elimina l k 0))
)

;(print (eliminaPrincipal '(a (1 (2 b)) (c (d))) 1))
; k = 4 => (A (1 (2 B)) (C (D))) 


;7) inlocuire valorilor numerice impare situate pe nivel par cu nr nat succesor
; (1 s 4 (3 f (7))) => (1 s 4 (4 f (7)))

(defun inval(l niv)
(cond
 ((null l) nil)
 ((and (numberp l) (= (mod niv 2) 0) (= (mod l 2) 1)) (+ l 1))
 ((listp l) (mapcar #'(lambda (i) (inval i (+ niv 1))) l))
 (t l)
)
)

;(print (inval '(1 s 4 (3 f (7))) 0))
; =>(1 S 4 (4 F (7)))

