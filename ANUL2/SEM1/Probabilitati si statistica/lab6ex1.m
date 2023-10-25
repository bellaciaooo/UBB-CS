%Laboratorul 6 ex 1
% 1. Simulati de n ∈ {500, 1000, 2000} ori valoarea inaltimii unei persoane
% alese aleator folosind distributia normala cu parametrii m = 165 (cm) si
% σ = 10 (cm).
% i) Afisati histograma frecventelor absolute cu 10 bare pentru vectorul X dat
% de cele n simulari.
%
% ii) Afisati histograma frecventelor relative cu 10 bare pentru vectorul X dat
% de cele n simulari astfel incat suma ariilor barelor sa fie 1. Comparati
% aceasta histograma cu graficul functiei de densitate corespunzatoare.
%
% iii) Afisati valoarea medie, deviatia standard si proportia de valori in
% intervalul [160, 170] pentru cele n simulari. Comparati rezultatele obtinute
% cu rezultatele corespunzatoare exacte.
% --Folositi functiile: hist, normrnd, normpdf, normcdf.

n=100;
clf; hold on;
# x = normrnd(media_inaltimii, sigma=variatia, nr_linii, nr_coloane)
x = normrnd(165,10,1,1000);
# hist(x,10)
# [nn,xx] = hist(x, mijl_bare, norm)
# nn-frecv absolute
# xx - mijl barelor
# norm = suma inaltimilor barelor)
# norm ul nostru ar trebui sa reprezinte suma ariilor barelor si sa fie = 1
# suma ariilor barelor = suma inaltimilor barelor * latimea unei bare = 1
# => norm = 1/L
[~,mijl_bare] = hist(x,10);
# latimea unei bare este (max(x)-min(x))/10
l = (max(x)-min(x))/10;
norm = 1/l;
hist(x,mijl_bare,norm);

# lambda function
# f = @(t) normpdf(t, medie, sigma)
f = @(t)normpdf(t,165,10)
fplot(f,[min(x), max(x)],'-r','LineWidth',4)
mean(x)
std(x)
# proportia de valori din intervalul [160,170]
mean(160<x & x<170)
# P(x<a) = normcdf(a medie, sigma)
normcdf(170,165,10)-normcdf(160,165,10)


