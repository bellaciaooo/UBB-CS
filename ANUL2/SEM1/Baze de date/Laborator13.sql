-- Creare baza de date pentru gestionarea notelor date de un utilizator restaurantelor. 
CREATE DATABASE NoteRestaurant;
GO

USE NoteRestaurant;

--1.)Creare model relational pentru a reprezenta datele
CREATE TABLE TipRestaurant
( cod_tip INT PRIMARY KEY IDENTITY,
  nume VARCHAR(50),
  descriere VARCHAR(100)
);

CREATE TABLE Oras
( cod_oras INT PRIMARY KEY IDENTITY,
  nume VARCHAR(50)
)

CREATE TABLE Utilizator
( cod_utilizator INT PRIMARY KEY IDENTITY,
  nume VARCHAR(50),
  email VARCHAR(30),
  parola VARCHAR(20)
);

CREATE TABLE Restaurant
( cod_restaurant INT PRIMARY KEY IDENTITY,
  nume VARCHAR(50),
  adresa VARCHAR(70),
  telefon VARCHAR(15),
  cod_tip INT FOREIGN KEY REFERENCES TipRestaurant(cod_tip) ON UPDATE CASCADE ON DELETE CASCADE,
  cod_oras INT FOREIGN KEY REFERENCES Oras(cod_oras) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Nota
( cod_utilizator INT FOREIGN KEY REFERENCES Utilizator(cod_utilizator) ON UPDATE CASCADE ON DELETE CASCADE,
  cod_restaurant INT FOREIGN KEY REFERENCES Restaurant(cod_restaurant) ON UPDATE CASCADE ON DELETE CASCADE,
  nota FLOAT,
  CONSTRAINT pk_Nota PRIMARY KEY (cod_utilizator,cod_restaurant)
);

--punem niste date
INSERT INTO TipRestaurant(nume,descriere) VALUES ('cultural','cu obiective'),
('turistic','cu obiective'),('de relaxare','cu hamace'),('modern','cu picturi');

INSERT INTO Oras(nume) VALUES ('Cluj-Napoca'),('Fagaras'),('Sibiu'),('Oradea'),('Bucuresti');

INSERT INTO Utilizator(nume,email,parola) VALUES ('Bella Salcedo','bella@gmail.com','flamingo'),
('Sasu Iulian','iulian@yahoo.com','cocos'),('Reghini Stefan','pisi@gmail.com','kitty');

INSERT INTO Restaurant(nume,adresa,telefon,cod_tip,cod_oras) VALUES
('Sucre','Eroilor nr 12','0712345621',4,3),
('Simfonia','Florilor nr 89','0770890996',1,1),
('Lemnul Verde','Crizantemelor nr 77','0265123489',3,1),
('Luccaffe','Anasonului nr 14','0765145633',3,2)

INSERT INTO Nota(cod_utilizator,cod_restaurant,nota) VALUES
(1,1,8.7),(1,3,6.5),(2,3,5),(2,4,7),(3,2,9);


SELECT * FROM TipRestaurant;
SELECT * FROM Oras;
SELECT * FROM Utilizator;
SELECT * FROM Restaurant;
SELECT * FROM Nota
GO

--2.)Creati o procedura stocata care primeste un restaurant, un utilizator si o nota si adauga nota
-- data de catre utilizator restaurantului. Daca utilizatorul a dat deja o nota acelui restaurant, valoarea
-- notei va fi actualizata. 

CREATE OR ALTER FUNCTION Validate(@cod_utilizator INT,@cod_restaurant INT)
RETURNS VARCHAR(50)
AS
BEGIN
   IF(NOT(EXISTS(SELECT cod_utilizator FROM Utilizator WHERE cod_utilizator = @cod_utilizator)))
     RETURN 'invalid';
   IF(NOT(EXISTS(SELECT cod_restaurant FROM Restaurant WHERE cod_restaurant = @cod_restaurant)))
     RETURN 'invalid';
   RETURN 'valid';
END;
GO

CREATE OR ALTER FUNCTION ExistsNota(@cod_utilizator INT,@cod_restaurant INT)
RETURNS VARCHAR(50)
AS
BEGIN
   IF(EXISTS(SELECT nota FROM Nota WHERE cod_utilizator = @cod_utilizator AND cod_restaurant = @cod_restaurant))
     RETURN 'exista';
   RETURN 'nu exista';
END;
GO


CREATE OR ALTER PROCEDURE UpsertNota @cod_utilizator INT,@cod_restaurant INT, @nota FLOAT
AS
BEGIN
     SET NOCOUNT ON
     IF(dbo.Validate(@cod_utilizator,@cod_restaurant) = 'valid')
	   IF(dbo.ExistsNota(@cod_utilizator,@cod_restaurant) = 'exista') --updatam
	   BEGIN
	      UPDATE Nota
		  SET nota = @nota
		  WHERE cod_utilizator = @cod_utilizator AND cod_restaurant = @cod_restaurant
		  PRINT('S-a efectuat update.');
	   END
	   ELSE --inseram
	      BEGIN
	      INSERT INTO Nota(cod_utilizator,cod_restaurant,nota) VALUES
		  (@cod_utilizator,@cod_restaurant,@nota);
		  PRINT('S-a efectuat insert.');
		  END
	 ELSE
	   PRINT('Datele introduse nu sunt valide.');
END;
GO

SELECT * FROM Utilizator;
SELECT * FROM Restaurant;
SELECT * FROM Nota

EXEC UpsertNota 1,2,7.3;

GO
--3.)Creati un view care afiseaza numele restaurantului si media aritmetica a notelor pentru fiecare
-- restaurant care are media aritmetica a notelor strict mai mare decat 5. 
CREATE OR ALTER VIEW ViewRestaurantMedie AS
SELECT R.nume,SUM(N.nota)/COUNT(N.nota) as [media aritmetica] FROM Restaurant R INNER JOIN Nota N
ON R.cod_restaurant = N.cod_restaurant WHERE R.cod_restaurant = N.cod_restaurant
GROUP BY R.nume
HAVING SUM(N.nota)/COUNT(N.nota)>5
GO

SELECT * FROM ViewRestaurantMedie

--AVEM SI FUNCTIA DE AVG() pentru a calcula media si ar fi trebuit grupat pe R.cod dupa pe nume
--daca nu avem nume unique