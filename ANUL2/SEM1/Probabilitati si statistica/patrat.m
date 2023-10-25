% Problema patrat - frecventa puncte

function out=patrat(nr)
  %hold on- sa tina pe ecran sa se afiseze toate instructiunile
  axis square, hold on
  rectangle('Position',[0 0 1 1], 'Facecolor', 'y')
  for i = 1:nr
      x = rand;
      y = rand;
      plot([x],[y],'*r','MarkerSize',5)

      % frecventa punctelor care sunt mai apropiate de centrul
      % patratului decat de varfurile patratului

  endfor
  end
