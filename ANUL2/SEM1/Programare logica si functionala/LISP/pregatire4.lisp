
(defun elimin (l e e1)
(cond
  ((null l) nil)
  ((and (atom l) (not (equal l e))) l)
  ((and (atom l) (equal l e)) e1)
  (t (mapcar #'(lambda (i) (elimin i e e1)) l))
)
)

(print (elimin '(1 (2 A (3 A)) (A)) 'A 'B))