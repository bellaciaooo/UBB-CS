%Exercitiul 8
%b) Sa se scrie un predicat care elimina primele 3 aparitii ale unui element
% intr-o lista. Daca elementul apare mai putin de 3 ori, se va elimina
% de cate ori apare.

%Modelul matematic
%-la inceput k=0
%-el este elementul care trebuie sters
%
%elimina(l1l2...ln,el,k) = - [], daca n = 0
%                          - [l1], daca el != l1 si n=1 sau el = l1 si
%                           k>=3
%                          - [], daca el = l1 si n=1 si k<3
%                          - l1 U elimina(l2l3...ln,el,k), daca (el !=
%                           l1 si n>1) sau (el = l1 si n>1 si k = 3)
%                          - elimina(l2l3...ln,el,k+1), daca el = l1 si
%                           n>1 si k<3

%elimina(Lista, El, K, R)
%flux(i,i,i,o)
elimina([],_,_,[]).
elimina([L],El, _, [L]):- not(L == El).
elimina([L],El, K, [L]):- L == El, K>=3.
elimina([L], L, K, []):- K<3.
elimina([H, H2|T],El, K, [H | R]) :- not(El==H), elimina([H2|T],El,K,R).
elimina([H, H2|T],El, K, [H | R]) :- El==H, K==3, elimina([H2|T],El,K,R).
elimina([H, H2|T],El, K, R) :- El==H, K<3, K1 is K+1, elimina([H2|T],El,K1,R).

%Apel:
% elimina([1,2,1,1,3,4,5,1],1,0,R). => R= [2,3,4,5,1]
% elimina([1,2,3,4,5,1],1,0,R). => R= [2,3,4,5]
% elimina([],1,0,R). => R = []
