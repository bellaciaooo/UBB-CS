% Det un predicat care det produsul unui nr reprezentat cifra cu cifra
% intr o lista cu o anumita cifra , fara a transforma lista intr-un
% numar. ex: [1,9,3,5,9,9] * 2 => [3,8,7,1,9,8]
%
% Modelul matematic
% -folosim inversa listei pentru a calcula produsul
% invers(l1l2...ln,c1...cn) = c1...cn, daca n=0
%                             invers(l2...ln,l1c1...cn), daca n>=1
%
% invers(L:lista,C:lista,R:lista)
% L:lista de inversat
% C:lista prin care se realizeaza inversatea
% R:lista L inversata
% Model de flux: (i,i,o) -determinist

invers([],C,C).
invers([H|T],C,R):- invers(T,[H|C],R).

% produs(l1l2...ln, c, cf) = - [cf] , daca n = 0 si cf != 0
%                           // - c*l1 + cf U produs([],c,c*l1/10),
%                           // daca n = 1
%                            - (c*l1 + cf)%10 U
%                            produs(l2...ln,c,(c*l1+cf)/10), daca n>=1 -
%                            [] , daca n = 0 si cf = 0
%
% produs(L:lista, C:intreg, CF:intreg, R:lista)
% L: lista care contine cifrele numarului de inmultit ca elemente
% C: cifra cu care trebuie sa inmultim cifra cu cifra elem din lista L
% CF: carry flag-ul inmultirii celor doua cifre
% R: lista cu numarul rezultat in urma inmultirii
% Modele de flux: (i,i,i,o)
% Predicat determinist
%

produs([],_,0,[]).
produs([],_,CF,[CF]):- CF \= 0.
produs([H|T],C,CF,[R1|R]):- R1 is (H*C+CF) mod 10, CF1 is (H*C+CF) div 10,
       produs(T,C,CF1,R).

% Modelul matematic
% produsLista(l1l2...ln,c) = produs(invers(l1..ln),c,0
%
% produsLista(L:lista,C:intreg,R:lista)
% L:lista pt care realizam produsul
% C: cifra cu care se inmultesc cifrele listei
% R: lista rezultata in urma produsului
% (i,i,o) - determinist

produsLista(L,C,R):-invers(L,[],LR),produs(LR,C,0,R1),invers(R1,[],R).




