% Sa se calculeze inversa unei liste
% invers(l1...ln,c1..cn) = c1...cn, daca n = 0
%                          invers(l2..ln, l1c1...cn), daca n>=1
%
% invers(L:lista,C:lista,R:lista)
% L: lista de inversat
% C: lista in care se salveaza pe rand inversarea listei L
% R: rezultatul listei inversate

invers([],C,C).
invers([H|T],C,R):- invers(T,[H|C],R).

inversa(L,R):-invers(L,[],R).
