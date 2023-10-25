%Model practic ex 1
% 1)Considerăm următorul experiment: Într-o urnă sunt 10 bile roșii, 5 bile
% negre și 5 bile albe. Se extrag aleator fără returnare 3 bile din urnă.
%
% a) Estimați, folosind comenzi Octave, probabilitatea evenimentelor P(A),
% P(B), P(A|C), unde
% A: bilele au aceeași culoare
% B: cele 3 bile sunt de trei culori distincte
% not(A): bilele nu au aceeași culoare
% C: printre bilele extrase există cel puţin o bilă neagră.
%
% b) Afișați probabilitatea teoretică pentru P(A), P(B), P(C).

function out = model1ex()
  urna = ['R','R','R','R','R','R','R','R','R','R','N','N','N','N','N','A','A','A','A','A'];
  evA = 0;
  evB = 0;
  evC = 0;
  evAC = 0;

  %simulam extragerea celor 3 bile din urna
  for i = 1:5000
    extrag = randsample(urna,3);
    %a)bilele sa aiba aceasi culoare (ev A)
    if(length(unique(extrag)) == 1)
       evA++;
       %a)bilele sa fie toate negre (ev A ∩ C)
       if(extrag(1) == 'N')
          evAC++;
       endif
    endif
    %a)bilele sa fie de culoari diferite (ev B)
    if(length(unique(extrag)) == 3)
       evB++;
    endif
    %a)cel putin o bila sa fie neagra(ev C)
    if(extrag(1)== 'N' || extrag(2)== 'N' || extrag(3)== 'N')
       evC++;
    endif
  endfor

  %Probabilitatile prin estimare
  fprintf("Probabilitatile prin estimare:\n");
  fprintf("P(A) = %d\n",evA/5000);
  fprintf("P(B) = %d\n",evB/5000);
  fprintf("P(C) = %d\n",evC/5000);
  fprintf("P(A|C) = %d\n",evAC/evC);
  % P(A|C) = P(C ∩ A)/P(C)

  %b)Pentru probabilitatile teoretice
  %N=nr de extrageri posibile = aranjamente de 20 luate cate 3 = 6840
  N = 6840;
  %Pentru evenimentul A: bilele au aceasi culoare
  % bilele rosii => aranjamente de 10 luate cate 3 = 720
  % bilele negre => aranjamente de 5 luate cate 3 = 60
  % bilele albe => aranjamente de 5 luate cate 3 = 60
  % => 840 cazuri favorabile pt evenimentul A
  evtA = 840;

  %Pentru evenimentul B: cele 3 bile sunt de trei culori distincte
  % => bile rosii , bile negre, bile albe
  % nr de cazuri favorabile = 10(r) * 5(n) * 5(a) +
  %                           10(r) * 5(a) * 5(n) +
  %                           5(n) * 10(r) * 5(a) +
  %                           5(n) * 5(a) * 10(r) +
  %                           5(a) * 5(n) * 10(r) +
  %                           5(a) * 5(r) * 10(n)
  % (permutari de {rosii,negre,albe} mai apoi)
  % => 250*6 = 1500 cazuri favorabile pt evenimentul B
  evtB = 1500;

  %Pentru evenimentul C: cel putin o bila sa fie neagra
  % Luam not(C) = nicio bila sa fie neagra =>A de 15 luate cate 3 =2730
  % P(notC) =2730/N => P(C) = 1 - P(notC)

  fprintf("Probabilitatile teoretice:\n");
  fprintf("P(A) = %d\n",evtA/N);
  fprintf("P(B) = %d\n",evtB/N);



end

