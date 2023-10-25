% 1. Realizati un program care genereaza N numere pseudo-aleatoare pentru
% variabila aleatoare discreta X, care are distributia de probabilitate
% X ~ ( x1 x2 ... xn)
%     ( p1 p2 ... pn) folosind functia rand.
% cu grupele de sange, apel mai jos

function out = generare_distributie_discreta(x, p, N)
  nrX(N) = [0];
  p = cumsum(p);
  for i = 1 : N
    persoana = rand;
    j = 1;
    while persoana > p(j)
      j = j + 1;
    endwhile
    nrX(i) = x(j);
  endfor
  for i = 1 : length(x)
    fprintf('Frecventa pentru X%d:\n',i);
    f = histc(nrX,x(i));
    frecv = f/N
  endfor

end

%apel: generare_distributie_discreta([1,2,3,4],[0.46,0.4,0.1,0.04],50)
