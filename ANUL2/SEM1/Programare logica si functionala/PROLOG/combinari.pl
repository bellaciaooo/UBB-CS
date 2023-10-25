%combinari din elem unei liste luate cate k
%comb(L:lista,K:Intreg,R:lista)

comb([H|_],1,[H]).
comb([_|T],K,R) :- comb(T,K,R).
comb([H|T],K,[H|R]) :- K > 1, K1 is K - 1, comb(T,K1,R).

%apel([1,2,3],2,R).

combinari(L,K,R) :- findall(C,comb(L,K,C),R).

%predicat ce insereaza un element pe toate pozitiile unei liste
%insereaza(E:Intreg,L:lista,R:lista)

insereaza(E,L,[E|L]).
insereaza(E,[H|T],[H|R]):- insereaza(E,T,R).

insp(E,L,R) :- findall(C,insereaza(E,L,C),R).

%permutarile elementelor unei liste
%perm(L,R::lista)

perm([],[]).
perm([H|T],C) :- perm(T,R), insereaza(H,R,C).

permt(L,R) :- findall(C,perm(L,C),R).

%aranjamente din elem unei liste luate cate k
%aranjamente(L:lista,K:Intreg,R:lista)

aranj(L,K,R) :- comb(L,K,C), perm(C,R).

aranjp(L,K,R) :- findall(C,aranj(L,K,C),R).

%candidat
candidat([H|_],H).
candidat([_|T],R) :- candidat(T,R).

%aranjam(l,k,c,r)
aranjam(_,0,C,C).
aranjam(L,K,[E|C],R) :- candidat(L,E),K1 is K - 1, aranjam(L,K1,C,R).



ap(L,K,CL,R) :- findall(C,aranjam(L,K,CL,C),R).
