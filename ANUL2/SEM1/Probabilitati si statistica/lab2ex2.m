%Laboratorul 2 ex 2
%  a) Generati N ∈ {500, 1000, 2000} puncte uniform aleatoare
% intr-un patrat. Afisati frecventa relativa a punctelor care:
%(colorate cu rosu fara vreun criteriu special)

function out = lab2ex2(N)
  clf;
  axis square;
  hold on;
  rectangle('Position',[0 0 1 1])
  %punctul din centrul patratului (cercului)
  %raza cercului = 0.5
  O = [0.5 0.5];
  caz_fav1 = 0;
  caz_fav2 = 0;
  caz_fav3 = 0;

  for i = 1:N
    x = rand();
    y = rand();
    P = [x y];
    %1) sunt in interiorul cercului tangent patratului =>
    % daca distanta dintre punct si centrul patratului < 0.5 (verde)
    if pdist([O;P]) < 0.5
      caz_fav1 = caz_fav1 + 1;
      plot(x,y,'*g');
    else
      plot(x,y,'*r');
    endif

    %2) sunt mai apropiate de centrul patratului decat
    % de varfurile patratului. (albastru)
    %Coordonatele varfurilor patratului
    vf1 = [0 0];
    vf2 = [0 1];
    vf3 = [1 0];
    vf4 = [1 1];

    %Calculam daca distanta punctului P fata de centru este mai mica
    % fata de varfurile patratului
    if (pdist([O;P]) < pdist([P;vf1]) &&
        pdist([O;P]) < pdist([P;vf2]) &&
        pdist([O;P]) < pdist([P;vf3]) &&
        pdist([O;P]) < pdist([P;vf4]))
        caz_fav2 = caz_fav2 + 1;
        plot(x,y,'*b');
    endif

    % 3) formeaza cu varfurile patratului doua triunghiuri
    % ascutitunghice si doua triunghiuri obtuzunghice.(negru)
    % => 4 cercuri suprapuse pe jumatatatile patratului

    %Calculam coordonatele centrelor celor 4 cercuri pe laturile patratului
    centru1 = [0.5 1];
    centru2 = [1 0.5];
    centru3 = [0.5 0];
    centru4 = [0 0.5];

    %Calculam distantele de la punctul P la centrul fiecarui cerc din jurul
    %patratului
    dist1 = pdist([centru1;P]);
    dist2 = pdist([centru2;P]);
    dist3 = pdist([centru3;P]);
    dist4 = pdist([centru4;P]);

    %Luam distantele grupate 2 cate 2 pentru cercurile alaturate, daca
    % ambele distante celor doua cercuri alaturate sunt mai mici de 0.5
    % (raza fiecarui cerc) => punctul apartine reuniunii celor 2 cercuri
    % => acolo se formeaza 2 triunghiuri ascutite si 2 obtuze
    if ((dist1 < 0.5 && dist2 < 0.5) ||
        (dist2 < 0.5 && dist3 < 0.5) ||
        (dist3 < 0.5 && dist4 < 0.5) ||
        (dist4 < 0.5 && dist1 < 0.5))
        plot(x,y,'*black');
        caz_fav3 = caz_fav3 + 1;
    endif

  endfor

  fprintf('1)Frecv. relativa punctelor care sunt in interiorul cercului= %d\n',caz_fav1/N);
  fprintf('2)Frecv. relativa punctelor care sunt mai aproape de centrul patratului decat de varfuri= %d\n',caz_fav2/N);
  fprintf('2)Frecv. relativa punctelor care formeaza 2 triunghiuri ascutite si 2 obtuze= %d\n',caz_fav3/N);

  end
