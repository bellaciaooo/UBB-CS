% a) Sa se interclaseze fara pastrarea dublurilor doua liste sortate.
%
% Modelul matematic
%
% interclasare(a1a2...an, b1b2...bm) =
%           - [], daca n = 0 si m = 0
%           - [a1a2...an] , daca m = 0 si n != 0
%           - [b1b2...bm] , daca n = 0 si m != 0
%           - a1 U interclasare(a2...an,b1...bm),
%             daca n > 0 si m > 0 si a1 < b1
%           - b1 U interclasare(a1...an,b2...bm),
%             daca n > 0 si m > 0 si b1 <= a1
%
% interclasare(L1: lista, L2: lista, R: lista)
% Modele de flux: (i,i,o), (i,i,i)
% Predicat determinist
% L1: prima lista sortata pentru a se realiza interclasarea cu L2
% L2: a doua lista sortata pentru a se realiza interclasarea cu L1
% R: lista rezultata in urma interclasarii celor doua liste sortate L1
% si L2

interclasare([],[],[]):-!.
interclasare(L,[],L):-!.
interclasare([],L,L):-!.
interclasare([H|T],[H2|T2],[H|Aux]) :- H < H2,!, interclasare(T,[H2|T2],Aux).
interclasare([H|T],[H2|T2],[H2|Aux]) :- interclasare([H|T],T2,Aux).

% Modelul matematic
%
% eliminDuplicate(l1...ln) =
%           - l1...ln, daca n <= 1
%           - l1 U eliminDuplicate(l2...ln), daca n > 1 si l1 != l2
%           - eliminDuplicate(l2...ln), daca n > 1 si l1 = l2
%
% eliminDuplicate(L: lista, R: lista)
% Modele de flux: (i,o), (i,i)
% Predicat determinist
% L: lista din care urmeaza sa se elimine duplicatele
% R: lista rezultata in urma eliminarii duplicatelor din lista L

eliminDuplicate([],[]).
eliminDuplicate([L],[L]).
eliminDuplicate([H1,H2|T],[H1|R]) :- H1 \= H2, eliminDuplicate([H2|T],R).
eliminDuplicate([H,H|T],R) :- eliminDuplicate([H|T],R).

% Modelul matematic
%
% interclasarePrincipala(a1...an,b1...bm) =
%           - eliminDuplicate(interclasare(a1...an,b1...bm))
%
% interclasarePrincipala(L1:lista,L2:lista,R:lista)
% Modele de flux: (i,i,o) , (i,i,i)
% Predicat determinist
% L1: prima lista sortata pentru a se face interclasarea cu lista L2
% L2: a doua lista sortata pentru a se face interclasarea cu lista L1
% R: lista rezultata in urma interclasarii celor doua liste sortate fara
% pastrarea dublurilor

interclasarePrincipala(A,B,R):- interclasare(A,B,R1),eliminDuplicate(R1,R).

%Teste
% interclasare([1,12,24],[2,4,11,12,13,14,24],Aux).
% => Aux = [1, 2, 4, 11, 12, 13, 14, 24].
% interclasare([1,2,3,4,5,6],[1,2,3,4,5],Aux).
% => Aux = [1, 2, 3, 4, 5, 6].
% interclasare([],[],Aux).
% => Aux = [].
% interclasare([1,2,3,4,5,6],[],Aux)
% => Aux = [1, 2, 3, 4, 5, 6].

%b) Se da o lista eterogena, formata din numere intregi si liste de numere
% sortate. Sa se interclaseze fara pastrarea dublurilor toate
% sublistele.
%
% Modelul matematic
%
% interclasareLista(l1l2...ln, aux) =
%       - aux , daca n = 0
%       - interclasareLista(l2...ln, l1 U aux ),
%       daca n > 0 si l1 este atom
%       - interclasareLista(l2...ln, interclasare(aux,l1)),
%       daca n > 0 si l1 este lista
%
% interclasareLista(L:lista, Aux:lista, R:lista)
% Modele de flux (i,i,o), (i,i,i)
% Predicat determinist
% L: lista eterogena data pentru interclasare fara pastrarea dublurilor
% toate sublistele
% Aux: lista auxiliara unde salvam atomii cu care o sa se faca
% interclasarea sublistelor din lista L
% R: lista rezultata in urma interclasarii fara pastrarea dublurilor
% toate sublistele
interclasareLista([],L,L).
interclasareLista([H|T],Aux,R) :- not(is_list(H)),!,interclasarePrincipala([H],Aux,R1),
    interclasareLista(T,R1,R).
interclasareLista([H|T],Aux,R) :- interclasarePrincipala(H,Aux,R1), interclasareLista(T,R1,R).

% interclasareListaPrincipala(l1l2...ln)=
%     -interclasareLista(l1l2...ln, [])

interclasareListaPrincipala(L,R) :- interclasareLista(L,[],R).
