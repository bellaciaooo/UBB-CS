% 8) Un jucator la PRONOSPORT vrea sa aleaga pronosticuri
% pentru 4 meciuri. Pronosticurile pot fi 1,X,2. Sa se genereze toate
% variantele posibile stiind ca:
% - ultimul pronostic nu poate fi 2
% - sa nu fie mai mult de doua pronosticuri X
%
% Modelul matematic
%
% solutie(nr, nrX)=
%  1. [1], dacă nr=1
%  2. [X], dacă nr=1 și nrX<2
%  3. 1 U solutie(nr-1, nrX), daca nr>1
%  4. 2 U solutie(nr-1, nrX), daca nr>1
%  5. X U solutie(nr-1, nrX+1), dacă nr>1 și nrX<2
%
% solutie(Nr: Intreg, NrX: Intreg, R:Lista)
% Nr: numarul de meciuri ramase pentru alegerea pronosticului curent
% NrX: numarul curent de X-uri folosite pentru pronostic
% R: lista unde se salveaza pronosticurile alese pentru meciuri
%
% Modele de flux: (i,i,o) - predicat nedeterminist
% Apel: solutie(4,0,R)

solutie(1,_,[1]).
solutie(1,NrX,['X']):- NrX < 2.
solutie(Nr,NrX,[1|R]):- Nr > 1, Nr1 is Nr-1, solutie(Nr1,NrX,R).
solutie(Nr,NrX,[2|R]):- Nr > 1, Nr1 is Nr-1, solutie(Nr1,NrX,R).
solutie(Nr,NrX,['X'|R]) :- Nr > 1, NrX < 2, Nr1 is Nr-1, NrX1 is NrX+1,
    solutie(Nr1,NrX1,R).

%Modelul matematic
% pronostic() = [solutie(4,0,R)]
%
% pronostic(R)
% R: variabila unde o sa se colecteze rezultatul functiei
% Model de flux: (o) - predicat determinist
% Apel: pronostic(R)

pronostic(R):-findall(C,solutie(4,0,C),R).
