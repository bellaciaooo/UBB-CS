%Laboratorul 3 ex 1
% Intr-o urna sunt 5 bile rosii, 3 bile albastre, 2 bile verzi. Se extrag aleator,
% pe rand, 3 bile din urna, fara repunerea bilei extrase inapoi in urna inaintea
% urmatoarei extrageri. Se considera urmatoarele evenimente asociate:
% A: "cel putin o bila este rosie"
% B: "toate bilele extrase au aceasi culoare"
%
% i) Folosind functia randsample, scrieti o functie care simuleaza
% de 5000 de ori experimentul de mai sus si returneaza proportia de
% simulari in care a avut loc evenimentul A.
%
% ii) Scrieti o functie care simuleaza de 5000 de ori experimentul de mai
% sus si returneaza proportia de simulari in care a avut loc evenimentul A ∩ B.
%
% iii) Folosind rezultatele obtinute la i) si ii), estimati probabilitatea
% P(B|A). Comparati aceasta estimare cu valoarea exacta a probabilitatii.
% => pe foaie
%
% iv) Scrieti o functie care simuleaza de 5000 de ori experimentul de mai sus¸
% si returneaza proportia de simulari in care a avut loc evenimentul B dupa ce
% s-a observat anterior aparitia evenimentului A, relativa la numarul de
% aparitii ale evenimentului A. Comparati valoarea obtinuta cu valorile
% obtinute la iii). => P(B|A)


function out = lab3ex1()
  urna = ['R','R','R','R','R','A','A','A','V','V'];
  evA = 0;
  evAB = 0;

  for i = 1:5000
    extrag = randsample(urna,3);
    %i)cel putin o bila sa fie rosie (eveniment A)
    if(extrag(1)== 'R' || extrag(2)== 'R' || extrag(3)== 'R')
       evA++;
    endif
    %ii)toate bilele sunt rosii (evenimentul A ∩ B)
    if(unique(extrag) == 'R')
       evAB++;
    endif

  endfor

  fprintf("i)Proportie eveniment A = %d\n",evA/5000);
  fprintf("i)Proportie eveniment A ∩ B = %d\n",evAB/5000);
  fprintf("iv)P(B|A) = %d\n",evAB/evA);

end


% TEORIA
% Daca A si B sunt doua evenimente astfel icat P(A) > 0, atunci
% probabilitatea conditionata a evenimentului B conditionat de
% evenimentul A este P(B|A) = P(A ∩ B)/P(A)

% P(A|C) = P(C ∩ A)/P(C)


