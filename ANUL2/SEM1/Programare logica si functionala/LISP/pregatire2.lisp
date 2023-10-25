(SET 'X 'A)
;(print X)
;=> A

(SET 'X 'B)
;(print X)
;=>B

;(SET 'X 'A 'L (CDR L)) 
;(print X)
; nu mere

(SETQ A '(B C D))
(print A)
;=>(B C D)

(SETF (CADR A) 'X)
(print A)
;=>(B X D)

(SET (CADR A) 'Y)
(print A)
(print X)
;=> (B X D) si Y