; 1)o functie care substituie prima aparitie a unui element intr-o lista data

; Modelul matematic
; substituie(elem, l1l2...ln, nouElem) = - [], daca n = 0
;                                        - nouEleml2..ln, daca l1 = elem si n > 0
;                                        - l1 U substituie(elem,l2...ln,nouElem), daca l1 != elem si n > 0

(defun substituie(e lista noue)
(cond
  ((null lista) nil)
  ((equal (car lista) e) (cons noue (cdr lista)))
  (t (cons (car lista) (substituie e (cdr lista) noue)))
)
)

;(print (substituie '2 '(3 a 2 4 j 5 2 1) '123))
;=> (3 A 123 4 J 5 2 1) 

; 2) cmmdc-ul a doua numere

; Modelul matematic
; cmmdc(a, b) =  - a , daca a = b
;              - cmmdc(a-b, b) , daca a > b
;              - cmmdc(a, b-a) , daca b > a

(defun cmmdc(a b)
(cond
  ((= a b) a)
  ((> a b) (cmmdc (- a b) b))
  (t (cmmdc a (- b a)))
)
)

;(print (cmmdc '56 '48))
;=> 8

; 3) interclasarea a doua liste sortate fara pastrarea dublurilor

; Modelul matematic

; interclasare(a1a2...an, b1b2...bm) = 
;  - [], daca n = 0 si m = 0
;  - b1...bm, daca n = 0 si m != 0
;  - a1...an, daca m = 0 si n != 0 
;  - a1 U interclasare(a2...an, b2...bm), daca a1 = b1 si n != 0 si m != 0
;  - a1 U interclasare(a2...an, b1b2...bm), daca a1 < b1 si  n != 0 si m != 0
;  - b1 U interclasare(a1a2...an, b2...bm), daca b1 < a1 si  n != 0 si m != 0

(defun interclasare(a b)
(cond
  ((and (null a) (null b)) nil)
  ((null a) b)
  ((null b) a)
  ((= (car a) (car b)) (cons (car a) (interclasare (cdr a) (cdr b))))
  ((< (car a) (car b)) (cons (car a) (interclasare (cdr a) b)))
  (t (cons (car b) (interclasare a (cdr b))))
)
)

;(print (interclasare '(2 3 4 5 ) '(1 4 5 6 7 8)))
; => (1 2 3 4 5 6 7 8) 

; foarte dubioasa => nu mere
;4) adancimea unui arbore

;Model matematic
; adancime(arbore) = 

;(defun max-level (tree level)
;  (if (null tree)
;      level 
;      (#'max (mapcar (lambda (subtree) (max-level subtree (1+ level)))
;                   (rest tree)) level))
;) 

;(print (max-level '(A (B) (C (D) (E)) (F (G))) 1))


;5) Se dă o listă neliniară. Se cere să se dubleze valorile numerice de la orice nivel
;al listei, păstrând structura ierarhică a acesteia.
(defun dublare(l)
(cond
((null l) nil)
((numberp (car l)) (cons (* 2 (car l)) (dublare (cdr l))))
((atom (car l)) (cons (car l) (dublare (cdr l))))
(t (cons (dublare (car l)) (dublare (cdr l))))
)
)

; (print (dublare '(1 b 2 (c (3 h 4)) (d 6))))
; => (2 B 4 (C (6 H 8)) (D 12))

;6) Definiti o functie care obtine dintr-o lista data lista tuturor atomilor
;care apar, pe orice nivel, dar in aceeasi ordine. De exemplu:
;(((A B) C) (D E)) --> (A B C D E)

; Modelul matematic
; olista(l1l2...ln) = - [], daca n = 0
;                     - [l1] daca l1 este atom si n=1 ;mai apoi folosim APPEND care concateneaza listele de atomi
;                     - olista(l1) U olista(l2...ln), daca l1 este lista si n>1
;

(defun olista(lista)
(cond
  ((null lista) nil)
  ((atom lista) (list lista))
  (t (append (olista (car lista))(olista(cdr lista))))
)
)

;(print (olista '(((A B) C) (D E) F)))
