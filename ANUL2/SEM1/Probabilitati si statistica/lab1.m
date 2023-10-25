%Laboratorul 1
function out = lab1(v=[],k)
  %1)anagramele/permutarile cuvantului 'word'
  w = ['w','o','r','d'];
  perms(w)

  %2)toate perechile (neordonate) de cifre
  % din vectorul v=[2 3 5 7] (combinari)
  v2=[2 3 5 7];
  nchoosek(v2,2)

  %3)functie care afiseaza toate aranjamentele de n luate
  % cate k ale unui vector cu n elemente
  matrice_combinari = nchoosek(v,k);
  n = rows(matrice_combinari);
  m = columns(matrice_combinari);
  for i = 1:n
    vector = [];
    for j = 1:m
      vector = [vector matrice_combinari(i,j)];
    endfor
    disp(perms(vector))
  endfor

  end
