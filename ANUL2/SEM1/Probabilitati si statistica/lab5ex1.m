%Laboratorul 5 ex 1
% 1.Realizati un program care genereaza N numere pseudo-aleatoare pentru
% variabila aleatoare discreta X, care are distributia de probabilitate
% X ~ ( x1 x2 ... xn)
%     ( p1 p2 ... pn) folosind functia rand.
%
% Conform statisticilor medicale, 46% din oameni au grupa sanguina 0, 40% au
% grupa sanguina A, 10% au grupa sanguina B ¸si 4% au grupa sanguina AB.
% Simulati de N ori observarea grupei sanguine a unei persoane alese aleator
% si afisati frecventa relativa de aparitie a fiecarei grupe sanguine.
% Afisati histograma datelor obtinute. aici cu randsample

% generare_distributie_discreta scrisa de mine

function X = lab5ex1(x=[0,1,2,3],p=[0.46,0.4,0.1,0.04],N=1000)
  for j=1:N
    rnd = rand;
    range = 0;
    suma = 0;
    while(rnd>suma)
      suma=suma+p(range+1);
      range++;
    endwhile
    result(j)=range-1;
  endfor
  clf;hold on;
  X=result;
  fa=hist(X,x);
  fr=fa/N;
  bar(x,fr,'facecolor','b');
  Y=randsample(x,N,replacement=true,p);
  fay=hist(Y,x);
  fry=fay/N;
  bar(x,fry,'facecolor','y');
  set(findobj('type','patch'),'facealpha',0.7);
end

%function X = lab5ex1(x=[1,2],p=[0.5,0.5],N=10)
%  for j=1:N
%    rnd = rand;
%    range = 0;
%    suma = 0;
%    while(rnd>suma)
%      suma=suma+p(range+1);
%      range++;
%    endwhile
%    result(j)=range-1;
%  endfor
%  X=result;
%end

