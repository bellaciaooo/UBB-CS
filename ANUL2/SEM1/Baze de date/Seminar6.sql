--1)Cream baza de date pentru gestiunea mersurilor trenurilor
CREATE DATABASE Gara;
GO
USE Gara;
GO

--cream tabelele bazei de date

CREATE TABLE TipTren
( id_tip_tren INT PRIMARY KEY IDENTITY,
  descriere VARCHAR(100)
);

CREATE TABLE Tren
( id_tren INT PRIMARY KEY IDENTITY,
  nume_tren VARCHAR(100),
  id_tip_tren INT FOREIGN KEY REFERENCES TipTren(id_tip_tren));

CREATE TABLE Statie
( id_statie INT PRIMARY KEY IDENTITY,
  nume VARCHAR(100));

CREATE TABLE Ruta
( id_ruta INT PRIMARY KEY IDENTITY,
  nume VARCHAR(100),
  id_tren INT FOREIGN KEY REFERENCES Tren(id_tren));

CREATE TABLE StatieRuta
( id_statie INT FOREIGN KEY REFERENCES Statie(id_statie),
  id_ruta INT FOREIGN KEY REFERENCES Ruta(id_ruta),
  ora_plecarii TIME,
  ora_sosirii TIME,
  CONSTRAINT pk_StatieRuta PRIMARY KEY (id_statie,id_ruta));

  
  --inseram date in tabele

  INSERT INTO TipTren(descriere)
  VALUES ('marfar'),('de calatori'),('trenurile soarelui'),('tren de jucarie')

  SELECT * FROM TipTren;

  INSERT INTO Tren(nume_tren,id_tip_tren)
  VALUES ('Thomas', 3), ('Alexandru',2) ,('Marius',2),('Emily',3),('Bella',4),('Danut',1)

  SELECT * FROM Ruta

  INSERT INTO Ruta(nume,id_tren)
  VALUES('Cluj - Dej',1), ('Constanta - Timisoara', 2), ('Bucuresti - Tg. Jiu', 3),
        ('Timisoara - Iasi', 4), ('Iasi - Chisinau', 4) , ('Paris - Oradea', 6),
		('Cluj - Viena', 5);

  INSERT INTO Statie(nume)
  VALUES ('Cluj'),('Dej'),('Constanta'),('Timisoara'),('Bucuresti'),('Tg. Jiu'),
         ('Iasi'),('Chisinau'),('Paris'),('Oradea'),('Viena');

  INSERT INTO StatieRuta(id_ruta,id_statie,ora_sosirii,ora_plecarii)
  VALUES (1, 1, '5:10:00', '5:40:00'), (1, 2, '6:10:00', '6:40:00'), (2, 3, '7:10:00', '7:40:00'),
    (2, 4, '8:10:00', '8:40:00'), (3, 5, '9:10:00', '9:40:00'), (3, 6, '10:10:00', '10:40:00'),
    (4, 4, '5:10:00', '5:40:00'), (4, 7, '6:10:00', '6:40:00'), (5, 7, '7:10:00', '7:40:00'),
    (5, 8, '8:10:00', '8:40:00'), (6, 9, '9:10:00', '9:40:00'), (6, 10, '10:10:00', '10:40:00'),
    (7, 1, '5:10:00', '5:40:00'), (7, 11, '6:10:00', '6:40:00');

  SELECT * FROM StatieRuta;

  --2) Creati o procedura stocata care primeste o ruta, o statie, ora sosirii, ora plecarii si adauga
  -- noua statie rutei. Daca statia exista deja ,se actualizeaza ora sosirii si ora plecarii.
  GO
  --"upsert" - daca nu exista se face insert, daca exista se face update
  CREATE OR ALTER PROCEDURE upsert_StatieRuta 
  @ruta VARCHAR(100),
  @statie VARCHAR(100),
  @ora_sosirii TIME,
  @ora_plecarii TIME
  AS
  BEGIN
     DECLARE @id_ruta INT;
	 SELECT TOP 1 @id_ruta = id_ruta FROM Ruta WHERE nume = @ruta;

	 DECLARE @id_statie INT;
	 SELECT TOP 1 @id_statie = id_statie FROM Statie WHERE nume = @statie;
	 
	 IF(EXISTS (SELECT * FROM StatieRuta WHERE id_ruta = @id_ruta AND id_statie = @id_statie))
	 BEGIN
	   UPDATE StatieRuta
	   SET ora_sosirii = @ora_sosirii, ora_plecarii = @ora_plecarii
	   WHERE id_ruta = @id_ruta AND id_statie = @id_statie; 
	 END;
	 ELSE 
	   INSERT INTO StatieRuta(id_ruta,id_statie,ora_sosirii,ora_plecarii)
	   VALUES (@id_ruta,@id_statie,@ora_sosirii,@ora_plecarii);
  END;
  GO

SELECT S.nume AS statie, R.nume AS ruta, SR.ora_plecarii, SR.ora_sosirii
FROM StatieRuta SR
INNER JOIN Statie S ON SR.id_statie = S.id_statie
INNER JOIN Ruta R ON SR.id_ruta = R.id_ruta;

GO
--trebuie adaugate toate statiile la o ruta
EXEC upsert_StatieRuta 'Paris - Oradea',  'Cluj', '00:00:00', '00:00:00';
EXEC upsert_StatieRuta 'Paris - Oradea',  'Dej', '00:00:00', '00:00:00';
EXEC upsert_StatieRuta 'Paris - Oradea',  'Constanta', '00:00:00', '00:00:00';
EXEC upsert_StatieRuta 'Paris - Oradea',  'Timisoara', '00:00:00', '00:00:00';
EXEC upsert_StatieRuta 'Paris - Oradea',  'Bucuresti', '00:00:00', '00:00:00';
EXEC upsert_StatieRuta 'Paris - Oradea',  'Tg. Jiu', '00:00:00', '00:00:00';
EXEC upsert_StatieRuta 'Paris - Oradea',  'Iasi', '00:00:00', '00:00:00';
EXEC upsert_StatieRuta 'Paris - Oradea',  'Chisinau', '00:00:00', '00:00:00';
EXEC upsert_StatieRuta 'Paris - Oradea',  'Paris', '00:00:00', '00:00:00';
EXEC upsert_StatieRuta 'Paris - Oradea',  'Oradea', '00:00:00', '00:00:00';
EXEC upsert_StatieRuta 'Paris - Oradea',  'Viena', '00:00:00', '00:00:00';

GO
  --3)Creati un view care afiseaza numele rutelor care contin toate statiile
  CREATE OR ALTER VIEW rute_pe_toate_statiile AS 
  SELECT R.nume 
  FROM Ruta R INNER JOIN StatieRuta SR ON R.id_ruta = SR.id_ruta
  GROUP BY R.id_ruta,R.nume
  HAVING  COUNT(*) = (SELECT COUNT(*) FROM Statie);
  GO

  SELECT * FROM rute_pe_toate_statiile

  GO
  --3)Creati o functie care afiseaza toate statiile care au mai mult de un tren la un anumit moment din zi.
  CREATE OR ALTER FUNCTION statii_multe_trenuri_anumit_moment()
  RETURNS TABLE AS
    --select distinct pt ca sa selecteze statiile diferite
    RETURN SELECT DISTINCT S.id_statie,S.nume
	FROM Statie S INNER JOIN StatieRuta SR1 ON SR1.id_statie = S.id_statie
	INNER JOIN StatieRuta SR2 ON
	  SR1.id_statie = SR2.id_statie AND SR1.id_ruta != SR2.id_ruta
	WHERE (SR1.ora_plecarii BETWEEN SR2.ora_sosirii AND SR2.ora_plecarii)
	  OR (SR1.ora_sosirii BETWEEN SR2.ora_sosirii AND SR2.ora_plecarii)
  GO

  SELECT * FROM statii_multe_trenuri_anumit_moment();