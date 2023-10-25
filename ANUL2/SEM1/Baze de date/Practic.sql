--Nota: 10
--Creare baza de date gestiune candelabre pt sali nunti
CREATE DATABASE GestiuneCandelabre
GO

USE GestiuneCandelabre

--1)Script SQL ce creeaza model relational
CREATE TABLE Stil
( cod_stil INT PRIMARY KEY IDENTITY,
  denumire VARCHAR(30)
);

CREATE TABLE Firma
( cod_firma INT PRIMARY KEY IDENTITY,
  nume VARCHAR(30),
  an_infiintare INT,
  website VARCHAR(15)
);

CREATE TABLE Candelabru
( cod_candelabru INT PRIMARY KEY IDENTITY,
  model VARCHAR(30),
  descriere VARCHAR(50),
  pret FLOAT,
  nr_becuri INT,
  cod_stil INT FOREIGN KEY REFERENCES Stil(cod_stil) ON UPDATE CASCADE ON DELETE CASCADE,
  cod_firma INT FOREIGN KEY REFERENCES Firma(cod_firma) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE SalaNunta
( cod_sala INT PRIMARY KEY IDENTITY,
  nume VARCHAR(30),
  descriere VARCHAR(50),
  adresa VARCHAR(50),
  localitate VARCHAR(15)
);


CREATE TABLE CandelabruSala
( cod_candelabru INT FOREIGN KEY REFERENCES Candelabru(cod_candelabru) ON UPDATE CASCADE ON DELETE CASCADE,
  cod_sala INT FOREIGN KEY REFERENCES SalaNunta(cod_sala) ON UPDATE CASCADE ON DELETE CASCADE,
  cantitate INT NOT NULL,
  CONSTRAINT pk_candelabrusala PRIMARY KEY (cod_candelabru, cod_sala),
  CONSTRAINT cons_cantitate CHECK (cantitate > 0)
);

-- populare cu date
INSERT INTO Stil(denumire) VALUES ('gotic'),('modern'),('artistic'),('neomatic')

INSERT INTO Firma(nume,an_infiintare,website) VALUES 
('Coco',2020,'coco.com'), ('Maia',2021,'maia.com'), ('Chanel',2008,'chanel.com')

INSERT INTO SalaNunta(nume,descriere,adresa,localitate) VALUES
('Sala Gold','nu e necesar','strada Vii','Cluj'), ('Sala Platinum','nu e necesar','strada copacului','Sibiu'),
('Sala Silver','nu e necesar','strada Florii','Dej'), ('Sala Cupru','nu e necesar','strada zori','Oradea')

INSERT INTO Candelabru(model,descriere,pret,nr_becuri,cod_stil,cod_firma)
VALUES ('Crizanteme','in curs de pregatire',123.4,3,1,2),
 ('Model Artistic','in curs de pregatire',150.4,7,2,1),
 ('Model Lut','in curs de pregatire',120,5,3,3),
 ('Model Rosu','in curs de pregatire',303.5,1,2,2)

select * from Stil
select * from Firma
select * from Candelabru
select * from SalaNunta
select * from CandelabruSala

GO
--2)procedura stocata care primeste candelabru,o sala de nunti, si o cantitate 
-- si adauga candelabrul salii de nuntii ,daca exista se va actualiza cu noua cantitate

CREATE OR ALTER PROCEDURE UpsertCandelabruSala @cod_candelabru INT, @cod_sala INT, @cantitate INT
AS
BEGIN
	SET NOCOUNT ON
	IF(EXISTS(SELECT cantitate FROM CandelabruSala WHERE cod_candelabru = @cod_candelabru AND cod_sala = @cod_sala))
	BEGIN
		--se va face update daca exista o astfel de asociere a candelabrului la sala de nunti
		UPDATE CandelabruSala
		SET cantitate = @cantitate
		WHERE cod_candelabru = @cod_candelabru AND cod_sala = @cod_sala
		PRINT ('S-a efectuat update');
	END;
	ELSE
	BEGIN
		--se va face insert 
		INSERT INTO CandelabruSala(cod_candelabru,cod_sala,cantitate) VALUES
		(@cod_candelabru,@cod_sala,@cantitate)
		PRINT('S-a efectuat insert.');
	END;

END;
GO

select * from Stil
select * from Firma
select * from Candelabru
select * from SalaNunta
select * from CandelabruSala

EXEC UpsertCandelabruSala 5,3,11

GO
--3)Creati o functie care afiseaza numele salii si numarul total de candelabre 
-- care apartin stilului cu denumire 'modern' pt toate salile de nunti care au cel putin un
-- candelabru cu acest stil

CREATE OR ALTER VIEW CandelabruModern AS
SELECT S.nume,SUM(CS.cantitate) as [nr candelabre moderne ]FROM SalaNunta S 
INNER JOIN CandelabruSala CS ON S.cod_sala = CS.cod_sala
INNER JOIN Candelabru C ON CS.cod_candelabru = C.cod_candelabru
INNER JOIN Stil ST ON C.cod_stil = ST.cod_stil
WHERE ST.denumire = 'modern'
GROUP BY S.cod_sala, S.nume
HAVING SUM(CS.cantitate) > 0 
GO

SELECT * FROM CandelabruModern

GO

CREATE OR ALTER FUNCTION AfisareSaliCandelabruModern()
RETURNS TABLE
AS
    RETURN (SELECT S.nume,SUM(CS.cantitate) as [nr candelabre moderne ]FROM SalaNunta S 
	INNER JOIN CandelabruSala CS ON S.cod_sala = CS.cod_sala
	INNER JOIN Candelabru C ON CS.cod_candelabru = C.cod_candelabru
	INNER JOIN Stil ST ON C.cod_stil = ST.cod_stil
	WHERE ST.denumire = 'modern'
	GROUP BY S.cod_sala, S.nume
	HAVING SUM(CS.cantitate) > 0)
GO

SELECT * FROM dbo.AfisareSaliCandelabruModern()