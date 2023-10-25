;Exercitiul 7
;a) Sa se scrie o functie care testeaza daca o lista este liniara.

; Modelul matematic
; listaLiniara(l1l2...ln) = - True, daca n = 0
;                           - listaLiniara(l2...ln), daca l1 = atom si n >= 1   
;                           - False, daca l1 = lista si n >= 1

(defun listaLiniara(lista)
(cond
 ((null lista) t)
 ((atom (car lista)) (listaLiniara(cdr lista)))
 ((listp (car lista)) nil)
)
)

;(print (listaLiniara '(2 3 (4 (5)) 6 7)) ) 
; => NIL
; (print (listaLiniara '(2 3 4 5 6 7)) ) 
; => T


;b) Definiti o functie care substituie prima aparitie a unui element intr-o lista data
; substituie = inlocuim cu alt element dat ca si parametru
; Modelul matematic
; substituie(elem, l1l2...ln, nou_elem) = - [], daca n = 0
;                                         - l1 U substituie(elem, l2...ln), daca l1 != elem si n >= 1
;                                         - nou_eleml2...ln , daca l1 = elem si n >= 1

(defun  substituie(e lista noue)
(cond
 ((null lista) nil)
 ((not (equal e (car lista))) (cons (car lista) (substituie e (cdr lista) noue)))
 ((equal e (car lista)) (cons noue (cdr lista)))
)
)

 ;(print (substituie '2 '(1 2 4 3 2 3) '8))
; => (1 8 4 3 2 3)
 ;(print (substituie '7 '(1 2 4 3 2 3) '9))
; => (1 2 4 3 2 3)


;c) Sa se inlocuiasca fiecare sublista a unei liste cu ultimul ei element.
; Prin sublista se intelege element de pe primul nivel, care este lista.
; Exemplu: (a (b c) (d (e (f)))) ==> (a c (e (f))) ==> (a c (f)) ==> (a c f)
; (a (b c) (d ((e) f))) ==> (a c ((e) f)) ==> (a c f)

; Modelul matematic
; ultimElement(l1...ln) = - [], daca n = 0
;                         - l1, daca n = 1 si l1 este atom
;                         - ultimElement(l1) , daca n = 1 si l1 este lista
;                         - ultimElement(l2...ln), daca n > 1 

(defun ultimElement(lista)
(cond
 ((null lista) nil)
 ((AND (equal (cdr lista) nil) (atom (car lista))) (car lista))
 ((AND (equal (cdr lista) nil) (listp (car lista))) (ultimElement (car lista)))
 ((not (equal (cdr lista) nil)) (ultimElement (cdr lista)))
)
)

(print (ultimElement '((2) 3 (4 (7))))) 
;=> 7

; Modelul matematic
; ultimLista(l1...ln) = - [], daca n = 0
;                       - l1 U ultimLista(l2...ln), daca n >= 1 si l1 este atom 
;                       - ultimElement(l1) U ultimLista(l2...ln), daca n >= 1 si l1 este lista

(defun ultimLista(lista)
(cond
 ((null lista) nil)
 ((atom (car lista)) (cons (car lista) (ultimLista (cdr lista))))
 ((listp (car lista)) (cons (ultimElement (car lista)) (ultimLista (cdr lista))))
)
)

;(print (ultimLista '(a b c)))
; => (a b c)
(print (ultimLista '(a (b c) (d (e (f))))))
; => (a c f)
;(print (ultimLista '(a (b c) (d ((e) f)))))
; => (a c f) 


;d) Definiti o functie care interclaseaza fara pastrarea dublurilor doua liste liniare sortate.

; Modelul matematic
; interclasare(a1a2...an, b1b2...bm) =
;           - [], daca n = 0 si m = 0
;           - [a1a2...an] , daca m = 0 si n != 0
;           - [b1b2...bm] , daca n = 0 si m != 0
;           - a1 U interclasare(a2...an,b1...bm),
;             daca n > 0 si m > 0 si a1 < b1
;           - b1 U interclasare(a1...an,b2...bm),
;             daca n > 0 si m > 0 si b1 <= a1

(defun interclasare(a b)
(cond
 ((AND (null a) (null b)) nil)
 ((AND (null b) (not (null a))) a)
 ((AND (null a) (not (null b))) b)
 ((< (car a) (car b)) (cons (car a) (interclasare (cdr a) b)))
 ((<= (car b) (car a)) (cons (car b) (interclasare a (cdr b))))
)
)

;(print (interclasare '(1 1 6 7) '(1 2 3 5 6 8)))
; => (1 1 1 2 3 5 6 6 7 8)

;Modelul matematic
; eliminDuplicate(l1...ln) =
;            - [] , daca n = 0
;            - [l1] , daca n = 1
;            - l1 U eliminDuplicate(l2...ln), daca n > 1 si l1 != l2
;            - eliminDuplicate(l2...ln), daca n > 1 si l1 = l2

(defun eliminDuplicate(lista)
(cond
 ((null lista) nil)
 ((equal (cdr lista) nil) lista)
 ((AND (not (equal (cdr lista) nil)) (not (= (car lista) (car (cdr lista))))) (cons (car lista) (eliminDuplicate (cdr lista))))
 ((AND (not (equal (cdr lista) nil)) (= (car lista) (car (cdr lista)))) (eliminDuplicate (cdr lista)))
)
)

;(print (eliminDuplicate '(1 2 2 3 3 3 4 4 55))) => (1 2 3 4 55) 

;Modelul matematic
; interclasarePrincipala(a1...an,b1...bm) = - eliminDuplicate(interclasare(a1...an,b1...bm))

(defun interclasarePrincipala(a b)
 (eliminDuplicate (interclasare a b))
)

;(print (interclasarePrincipala '(1 1 6 7 11) '(1 2 3 5 6 8 9)))
; => (1 2 3 5 6 7 8 9 11) 