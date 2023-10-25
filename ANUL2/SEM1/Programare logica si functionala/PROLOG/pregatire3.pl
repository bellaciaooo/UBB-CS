% Sa se calculeze cel mai mare divizor comun al elementelor unei liste.
 cmmdc(X,0,X):-!.
 cmmdc(0,X,X):-!.
 cmmdc(X,Y,Z):- X \= 0,Y \= 0, X > Y, X1 is X-Y, cmmdc(X1,Y,Z),!.
 cmmdc(X,Y,Z):- X \= 0,Y \= 0, Y1 is Y-X, cmmdc(X,Y1,Z),!.

 %daca lista are un element cmmdc-ul ei este acel element

 cmmdcLista([X],X).
 cmmdcLista([H|T],R):- cmmdcLista(T,R1),cmmdc(H,R1,R).
