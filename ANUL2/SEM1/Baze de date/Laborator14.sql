--Creare baza de date Florarie
CREATE DATABASE Floraria
GO

USE Floraria

--1)scriptul SQL pentru modelul relational

CREATE TABLE Florarie
(  cod_florarie INT PRIMARY KEY IDENTITY,
   nume VARCHAR(50) UNIQUE,
   telefon VARCHAR(15),
   adresa VARCHAR(30)
);

CREATE TABLE CategorieAranjamentFloral
(  cod_categorie INT PRIMARY KEY IDENTITY,
   nume VARCHAR(50)
);

CREATE TABLE AranjamentFloral
(  cod_aranjament INT PRIMARY KEY IDENTITY,
   nume VARCHAR(50),
   pret INT,
   descriere VARCHAR(100),
   inaltime VARCHAR(10),
   cod_categorie INT FOREIGN KEY REFERENCES CategorieAranjamentFloral(cod_categorie) ON UPDATE CASCADE ON DELETE CASCADE,
   cod_florarie INT FOREIGN KEY REFERENCES Florarie(cod_florarie) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Planta
( cod_planta INT PRIMARY KEY IDENTITY,
  nume VARCHAR(50),
  descriere VARCHAR(100)
);

CREATE TABLE PlantaAranjament
(  cod_planta INT FOREIGN KEY REFERENCES Planta(cod_planta) ON UPDATE CASCADE ON DELETE CASCADE,
   cod_aranjament INT FOREIGN KEY REFERENCES AranjamentFloral(cod_aranjament) ON UPDATE CASCADE ON DELETE CASCADE,
   nr_exemplare INT,
   CONSTRAINT pk_plantaranjament PRIMARY KEY (cod_planta,cod_aranjament)
);

INSERT INTO Florarie(nume,telefon,adresa) VALUES ('Masomie','028302138','strada curajului'),
('Mocos','028302138','strada '), ('Briza marii','028302138','strada')
select * from Florarie

INSERT INTO CategorieAranjamentFloral(nume) VALUES 
('de nunta'),('de majorat'),('de botez'),('de petrecere')
select * from CategorieAranjamentFloral

INSERT INTO AranjamentFloral VALUES
('Aranjament Spectacular2',100,'','10m',1,4),
('Aranjament Galbena Floare3',70,'','1m',2,5),('Aranjament de explozie',800,'','10m',4,3)
select * from AranjamentFloral

INSERT INTO Planta(nume,descriere) VALUES 
('Floarea Soarelui','deja se cunoaste'),('Trandafir','deja se cunoaste'),('Viorea','deja se cunoaste')

GO
--2)procedura de upsert

CREATE OR ALTER PROCEDURE UpsertPlantaAranjament @cod_planta INT,@cod_aranjament INT, @nr_exemplare INT
AS 
BEGIN
	IF (EXISTS (SELECT nr_exemplare FROM PlantaAranjament WHERE cod_aranjament = @cod_aranjament AND cod_planta = @cod_planta))
	--se va face update la nr de exemplare
	BEGIN
		UPDATE PlantaAranjament
		SET nr_exemplare = @nr_exemplare
		WHERE  cod_aranjament = @cod_aranjament AND cod_planta = @cod_planta
		PRINT ('S-a efectuat update');
	END
	ELSE
	BEGIN
		--	inseram
		INSERT INTO PlantaAranjament(cod_planta,cod_aranjament,nr_exemplare)
		VALUES (@cod_planta,@cod_aranjament,@nr_exemplare)
		PRINT('S-a efectuat insert.');
	END
END;
GO

select * from AranjamentFloral
select * from Planta
select * from PlantaAranjament

EXEC UpsertPlantaAranjament 1,1,5
EXEC UpsertPlantaAranjament 2,2,12

GO
--3)view cu nume florarie, nume aranjament ,pret aranjament, nr de exemplare si numele plantei pt toate 
--florariile al caror nume nu incepe cu litera M
CREATE OR ALTER VIEW ViewAranjament AS
SELECT F.nume as [florarie], AF.nume as [aranjament floral], AF.pret as [pret aranjament],
P.nume as [planta], PA.nr_exemplare [nr exemplare planta] FROM Florarie F 
INNER JOIN AranjamentFloral AF ON F.cod_florarie = AF.cod_florarie
INNER JOIN PlantaAranjament PA ON AF.cod_aranjament = PA.cod_aranjament 
INNER JOIN Planta P ON PA.cod_planta = P.cod_planta
WHERE F.nume NOT LIKE 'M%' OR F.nume NOT LIKE 'm%'

go
SELECT * FROM ViewAranjament

INSERT INTO Planta(descriere) VALUES ('b'),('a');

select Planta.nume from Planta