%Laboratorul 3 ex 3
% Consideram experimentul: se arunca 4 zaruri, apoi se calculeaza suma numerelor
% obtinute. Rezolvati in Octave urmatoarele cerinte:

% i) Simulati de 1000 de ori aruncarea a 4 zaruri, folosind functia randi.
% Afisati, sub forma unei matrice, toate sumele aparute cu frecventele lor
% absolute.

% ii) Reprezentati grafic frecventele relative ale sumelor obtinute, folosind
% functiile hist si bar. Care sunt cele mai frecvente sume?

% iii) Afisati, sub forma unei matrice, toate sumele posibile cu frecventele
% lor absolute teoretice. Reprezentati grafic frecventele relative
% corespunzatoare. Care sunt cele mai frecvente sume?

% iv) Estimati probabilitatea ca suma numerelor celor 4 zaruri este cel
% putin 10, stiind ca suma este cel mult 20. Afisati probabilitatea teoretica
% corespunzatoare.

function out = lab3ex3()

  %i)prin ESTIMARE(SIMULARE)
  %setam numarul de simulari si numarul de zaruri de aruncat
  n = 1000;
  m = 4;

  %generam un vector/o matrice de n elemente aleatoare intre 1 si 6(nr de pe zar)
  v = randi([1 6],n,m);

  %calculam suma elementelor de pe fiecare linie
  sume = sum(v,2);

  %calculam frecventa absoluta pentru fiecare suma
  [frequencies, values] = hist(sume, unique(sume));

  fprintf("i)");
  %afisam rezultatele sub forma unei matrici
  rez = [values' frequencies']

  %ii)calculam frecventa relativa pt fiecare suma
  frecv_relativa = frequencies/n;

  %reprezentam grafic frecventele relative a valorilor
  bar(values,frecv_relativa);

  %iii) calculam frecventele TEORETICE
  m=4;
  %calculam toate sumele posibile (toate nr de la 4 la 24) pt cele 4 zaruri
  sume2 = 4:24;

  %calculam frecventele absolute teoretice pt fiecare suma
  frequencies_teoretic = nchoosek(6,m)*(1/6).^m;

  fprintf("iii)");
  %afisam rezultatele sub forma unei matrici
  rez = [sume2' frequencies_teoretic']

  %reprezentam grafic frecv relativa teoretica a valorilor
  bar(sume2, frequencies_teoretic/sum(frequencies_teoretic));

  end
