% Estimati prin simulari repetate probabilitatea ca intr-un grup de
% 23 persoane cel putin doua sa aiba aceea si zi de nastere.

function out=generare_zi(nr)
  cazuri_favorabile = 0;
  for i = 1:nr
    r = randi(365, 23, 1);
    lungime = length(r);
    r = unique(r);
    if lungime ~= length(r)
      cazuri_favorabile = cazuri_favorabile + 1;
    endif
  endfor
  disp('Probabilitatea este: ');
  disp(cazuri_favorabile/nr);

  end
