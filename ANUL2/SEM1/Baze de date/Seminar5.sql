CREATE DATABASE Seminar5
GO
USE Seminar5

CREATE TABLE Flori
(cod_f INT NOT NULL,
nume VARCHAR(100),
pret FLOAT,
culoare VARCHAR(100),
perioada VARCHAR(100),
producator VARCHAR(100)
)

INSERT INTO Flori(cod_f,nume,pret,culoare,perioada,producator) VALUES
(1,'trandafir',12,'rosu','all season','Ferma cu trandafiri'),
(-3,'trandafir',15,'galben','all season','Hushi SRL'),
(20,'lalea',9,'roz','primavara','Olanda'),
(-50,'zambila',8,'alb','primavara','Din piata'),
(6,'trandafir japonez',20,'rosu','vara','China'),
(100,'crizantema',20,'purpuriu','toamna','Din piata');

SELECT * FROM Flori;
SELECT * FROM Flori WHERE nume = 'crizantema';

ALTER TABLE Flori
ADD CONSTRAINT pk_flori PRIMARY KEY (cod_f);

SELECT * FROM Flori;

INSERT INTO Flori(cod_f,nume,pret,culoare,perioada,producator) VALUES 
(10, 'orhidee',25,'albastra','all season','Auchan');

SELECT * FROM Flori;
SELECT * FROM Flori WHERE cod_f = 10; --> index seek (inainte era table scan), pt ca e ordonat dupa cod

SELECT * FROM Flori WHERE nume = 'trandafir' --> index scan , pt ca nu aveam index pe nume, nu era 
--ordonat dupa numa, era ordonat dupa cheia primara

--1)creem un index nonclustered by default
CREATE INDEX ix_flori_nume_asc ON Flori(nume ASC);
go

SELECT nume FROM Flori WHERE nume IN ('trandafir','crizantema'); -->index seek

SELECT * FROM Flori WHERE nume = 'trandafir'  -->scaneaza tot tabelul, nu se foloseste de index-ul nostru
-- pt ca considera ca avem prea putine info in el

SELECT * FROM Flori;
--NU putem crea index pe nume pt ca avem nume duplicate in tabel 

--2)index unique :pe nume si culoare
CREATE UNIQUE INDEX IX_Flori_nume_asc_culoare_desc
ON Flori (nume ASC , culoare DESC);

INSERT INTO Flori (cod_f,nume,pret,culoare,perioada,producator) VALUES
(123, 'narcisa',7,'alb','primavara','Auchan'),
(567, 'trandafir',12,'galben','primavara','Din piata'),
(345, 'hortensie',50,'mov','vara','Din gradina');

--NU s-a inserat nimic, a dat fail de la dublura
SELECT * FROM Flori;

--il stergem indexul ca sa il adaugam cu optiunea de ignorare dubluri la inserare
DROP INDEX IX_Flori_nume_asc_culoare_desc ON Flori;

--adaugam indexul nou
CREATE UNIQUE INDEX IX_Flori_nume_asc_culoare_desc
ON Flori (nume ASC , culoare DESC) WITH (IGNORE_DUP_KEY = ON);

--acum putem face adaugarea cu ignorarea duplicatelor, se adauga cele care respecta conditia indexului
INSERT INTO Flori (cod_f,nume,pret,culoare,perioada,producator) VALUES
(123, 'narcisa',7,'alb','primavara','Auchan'),
(567, 'trandafir',12,'galben','primavara','Din piata'),
(345, 'hortensie',50,'mov','vara','Din gradina');

-->doar trandafiul galben nu s-a adaugat
SELECT * FROM Flori;

--SORTARI cu ajutorul indexului
SELECT nume,culoare FROM Flori ORDER BY nume ASC , culoare DESC -->INDEX SCAN, NU fac sortare in memorie

SELECT nume,culoare FROM Flori ORDER BY nume DESC , culoare DESC -->Index scan(22%) + sortare in memorie (78%)

--3)index filtered
CREATE INDEX IX_Flori_producator_asc_filtered ON Flori
(producator ASC) WHERE producator > 'D';

SELECT producator FROM Flori WHERE producator > 'D'; --> INDEX SCAN 
