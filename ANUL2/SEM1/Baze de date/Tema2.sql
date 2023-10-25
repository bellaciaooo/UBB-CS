USE GestiuneTabere;

/*1) Nr de persoane din fiecare categorie de varsta care se duc in tabere
    - 1 where, 1 group by, 1 extrag info din mai mult de 2 tabele
*/
SELECT C.categorie, COUNT(P.cod_categorie) AS [nr persoane] FROM CategorieVarsta C INNER JOIN Participant P 
ON C.cod_categorie=P.cod_categorie INNER JOIN TabaraParticipant TP ON P.cod_participant=TP.cod_participant
WHERE P.cod_participant = TP.cod_participant GROUP BY C.categorie;


/*2) Coordonatorii impreuna cu taberele pe care le coordoneaza in ordinea alfabetica numelor lor
    - 1 extrag info din mai mult de 2 tabele, 1 pe tabele in relatie many to many
*/
SELECT C.nume_coordonator, T.nume_tabara FROM Coordonator C INNER JOIN TabaraCoordonator TC ON C.cod_coordonator =
TC.cod_coordonator INNER JOIN Tabara T ON TC.cod_tabara = T.cod_tabara ORDER BY C.nume_coordonator;


/*3) Locatiile de tabere existente (cu descrierea lor) pentru care avem tabere disponibile
    - 1 distinct
*/
SELECT DISTINCT L.nume_locatie, L.descriere_locatie FROM Locatie L INNER JOIN Tabara T ON L.cod_locatie =
T.cod_locatie;


/*4) Fiecare tabara care are participanti minori impreuna cu numele acestora si categoria de varsta din care fac parte
    - 1 where, 1 extrag info din mai mult de 2 tabele, 1 pe tabele in relatie many to many
*/
SELECT T.nume_tabara, P.nume_participant, C.categorie FROM Tabara T INNER JOIN TabaraParticipant TP ON  T.cod_tabara = 
TP.cod_tabara INNER JOIN Participant P ON TP.cod_participant = P.cod_participant INNER JOIN CategorieVarsta C ON 
P.cod_categorie = C.cod_categorie WHERE C.cod_categorie < 4 ORDER BY T.nume_tabara;


/*5) Taberele care au mai multi coordonator (mai mult de un coordonator) impreuna cu locatia acestora de desfasurare
    - 1 group by, 1 having, 1 extrag info din mai mult de 2 tabele
*/
SELECT T.nume_tabara, COUNT(TC.cod_coordonator) AS [nr coordonatori], L.nume_locatie FROM Tabara T INNER JOIN TabaraCoordonator TC
ON T.cod_tabara = TC.cod_tabara INNER JOIN Locatie L ON T.cod_locatie=L.cod_locatie GROUP BY T.nume_tabara, L.nume_locatie
HAVING COUNT(TC.cod_coordonator) > 1;


/*6) Fiecare tabara impreuna cu categoriile de varsta care sunt inscrise in tabara respectiva la momentul actual
    - 1 group by, 1 extrag info din mai mult de 2 tabele
*/
SELECT T.nume_tabara, C.categorie FROM Tabara T INNER JOIN TabaraParticipant TP ON  T.cod_tabara = 
TP.cod_tabara INNER JOIN Participant P ON TP.cod_participant = P.cod_participant INNER JOIN CategorieVarsta C ON 
P.cod_categorie = C.cod_categorie GROUP BY T.nume_tabara,C.categorie ORDER BY T.nume_tabara;


/*7) Sponsorii care organizeaza tabere de relaxare sau aventura la momentul actual si nr la care pot fi contactati
    - 1 distinct , 1 where
*/
SELECT DISTINCT S.nume_sponsor,S.telefon_sponsor FROM Sponsor S INNER JOIN Tabara T ON T.cod_sponsor = S.cod_sponsor
WHERE T.cod_tip = 1 OR t.cod_tip = 4;


/*8) Taberele care au mai multe activitati (mai mult de o activitate) impreuna cu sponsorii acestora.
    - 1 group by, 1 having , 1 extrag info din mai mult de 2 tabele
*/
SELECT T.nume_tabara , COUNT(A.nume_activitate) AS [nr activitati], S.nume_sponsor FROM Tabara T INNER JOIN Activitate A ON
A.cod_tabara = T.cod_tabara INNER JOIN Sponsor S ON T.cod_sponsor = S.cod_sponsor GROUP BY T.nume_tabara, S.nume_sponsor 
HAVING COUNT(A.cod_activitate) > 1;


/*9) Taberele culturale care se desfasoara la momentul actual impreuna cu perioada, locatia si sponsorul acestora
    - 1 where, 1 extrag info din mai mult de 2 tabele
*/
SELECT T.nume_tabara ,T.data_inceput, T.data_sfarsit, L.nume_locatie, S.nume_sponsor FROM Tabara T INNER JOIN Locatie L ON L.cod_locatie = T.cod_locatie 
INNER JOIN Sponsor S ON S.cod_sponsor = T.cod_sponsor WHERE T.cod_tip = 3;


/*10) Taberele care se desfasoara pe perioada verii si perioada acestora de desfasurare impreuna cu locatia lor
     - 1 where
*/
SELECT T.nume_tabara,T.data_inceput,T.data_sfarsit,L.nume_locatie FROM Tabara T INNER JOIN Locatie L ON T.cod_locatie = 
L.cod_locatie WHERE T.data_inceput >= '2023-06-01' AND data_sfarsit <= '2023-08-31';