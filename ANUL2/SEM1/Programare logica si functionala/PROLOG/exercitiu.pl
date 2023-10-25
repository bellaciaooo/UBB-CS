%  Modelul matematic
%  adaugapar(l1l2..ln)=  - [],  daca n=0.
%                        - l1 + 1 + adaugapar(l2l3..ln), daca l1%2=0.
%                        - l1 + adaugapar(l2l3..ln), daca l1%2!=0.
%

adaugapar([],[]).
adaugapar([H|T],[H,1|REZ]):- mod(H,2)=:=0,adaugapar(T,REZ).
adaugapar([H|T],[H|REZ]):- not(mod(H,2)=:=0),adaugapar(T,REZ).
