% 1. Consideram variabila aleatoare X ~ N(100,20), care reprezinta valoarea pulsului
% inregistrata de un smartwatch pentru un alergator la un maraton. Generati aleator
% si independent 1000 de valori pentru X, apoi:
% a)Estimati probabilitatea evenimentului A:"80<X<140"
% b)Folosind comenzi Octave afisati valoarea probabilitatii teoretice a ev A
% c)Repr. in aceasi figura histograma frecventelor relative cu 13 bare/clase aleatoare
% valorilor generate si graficul functiei de densitate a lui X.

function out = practic()
  clf; hold on;
  %nr de valori de generat pentru X
  N = 1000;
  vm = 100;
  s = 20;
  evA = 0;

  %generam aleator val pentru X
  X = normrnd(vm,s,1,N);

  for i = 1:N
    if(X(i) > 80 && X(i) < 140)
       evA++;
    endif
  endfor

  fprintf("a)P(A) = %d\n",evA/N);

  %Probabilitatea teoretica a evenimentului A:80<X<140 => NU e bun
  %cazuri favorabile = [81,139] => 59
  %cazuri posibile = valMax-valMin+1
  ta = 59;
  pos = max(X)-min(X)+1;
  fprintf("b)P(A) teoretic = %d\n",ta/pos);

  %histograma frecventelor relative cu 13 bare(trebuia sa se imbine cu graficul
  % functiei de densitate)
  hist(X,13)

  %Graficul functiei de densitate
  % f = @(t) normpdf(t, medie, sigma)
  f = @(t)normpdf(t,vm,s);
  fplot(f,[min(X), max(X)],'-r','LineWidth',4)

  end
