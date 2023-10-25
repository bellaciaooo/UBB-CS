%Exercitiul 8
%a) Sa se scrie un predicat care testeaza daca o lista este multime.
%
%Modelul matematic
%exista(l1l2...ln, elem) = - False, daca n=0
%                          - True, daca elem = l1 si n>=1
%                          - exista(l2...ln,elem), daca elem != l1 si
%                          n>=1

exista([H|_], El) :- El=H.
exista([H|T], El) :-  not(El=H), exista(T, El).

%multime(l1l2...ln,aux1aux2...auxm) = - True, daca n=0
%				    // Not Exista(aux,l1), daca n=1
%                                     - Not Exista(aux,l1) si
%                                   multime(l2...ln, l1aux1...auxm),
%                                   daca n>=1

multime([],_).
multime([H|T], Aux) :- not(exista(Aux,H)), multime(T,[H|Aux]).

%Apel: multime([1,2,3],[]). => true
%      multime([],[]). => true
%      multime([1,2,1,2],[]). =>false

verificaMultime(Lista) :- multime(Lista,[]).
