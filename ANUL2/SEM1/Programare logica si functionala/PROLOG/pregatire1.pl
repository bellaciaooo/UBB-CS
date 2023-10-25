% a. Sa se scrie un predicat care intoarce intersectia a doua multimi.
%
% exista(l1l2...ln,e) = True, l1 = e
%                       exista(l2..ln), l1 != e
%                       False, in caz contrar

exista([H|_],H).
exista([H|T],E) :- H\=E , exista(T,E).

%
% intersectie(a1...an, b1...bm) =
%      - [], daca n = 0 sau m = 0
%      - a1 U intersectie(a2...an,b1...bm),daca exista(b1...bm,a1)
%      - intersectie(a2...an,b1...bm),daca not(exista(b1...bm,a1))
%
% intersectie(A:lista,B:lista,R:lista)
% modele de flux: (i,i,o),(i,i,i) - determinist

intersectie([],_,[]).
intersectie(_,[],[]).
intersectie([H|T],[H1|T1],[H|R]):- exista([H1|T1],H), intersectie(T,[H1|T1],R).
intersectie([H|T],[H1|T1],R):- not(exista([H1|T1],H)), intersectie(T,[H1|T1],R).
