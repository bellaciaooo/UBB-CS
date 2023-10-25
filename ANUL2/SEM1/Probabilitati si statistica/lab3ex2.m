%Laboratorul 3 ex 2
% a)Pentru p ∈ (0, 1), n, m ∈ N*¸si o variabila aleatoare X ∼ Bino(n, p),
% sa se genereze un vector x de m valori ale lui X, folosind functia binornd.
% Comparati datele obtinute cu cele date de distributie, folosind functiile:
% bar, binopdf si hist, testand codul de mai jos:

% binornd(n, p, ...) genereaza valori aleatoare;
% binopdf(x, n, p) calculeaza P(X = x), daca X ∼ Bino(n, p)

% b) Folosind functia binornd in 5000 de simulari, estimati probabilitatea
% ca exact 2 zaruri din 5 zaruri aruncate sa arate numere divizibile cu 3.
% Comparati valoarea obtinuta cu probabilitatea teoretica corespunzatoare,
% folosind functia binopdf.


function out = lab3ex2()

  %a)
  clf; grid on; hold on;
  p= 0.1 ; n=10; m=4;
  x=binornd(n,p,1,m);
  N=hist(x,0:n);
  bar(0:n,N/m,'hist','FaceColor','b');
  bar(0:n,binopdf(0:n,n,p),'FaceColor','y');
  legend('probabilitatile estimate','probabilitatile teroretice');
  set(findobj('type','patch'),'facealpha',0.7);
  xlim([-1 n+1]);

  %b) nr = nr de simulari, P = probabilitatea de succes
  %am estimat probabilitatea prin calcule cu binornd
  nr = 5000;
  P = 2/6; %prob ca atunci cand arunci un zar ,nr sa fie divizibil cu 3
  caz_fav = 0;

  for i = 1:nr
    x = binornd(5,P);
    if x == 2
      caz_fav++;
    endif
  endfor

  fprintf("Prob. ca exact 2 din 5 zaruri sa arate nr divizibile cu 3 = %d\n",caz_fav/nr);

  %calculeaza probabilitatea teoretica corespunzatoare
  t =  binopdf(2,5,P);
  fprintf("Probabilitatea teoretica = %d\n",t);

end

