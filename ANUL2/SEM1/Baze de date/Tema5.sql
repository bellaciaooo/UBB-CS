-- Operatii CRUD pentru 3 tabele: Tabara, TabaraParticipant, Participant

USE GestiuneTabere;
GO

-- Functie pentru validare Participant
CREATE OR ALTER FUNCTION ValidateParticipant(@nume NVARCHAR(100),@email NVARCHAR(100),
@telefon NVARCHAR(100), @cod_categorie INT)
RETURNS VARCHAR(50)
AS
BEGIN
   IF (@nume = '' OR @email = '' OR @telefon = '' OR 
   NOT(EXISTS(SELECT cod_categorie FROM CategorieVarsta WHERE cod_categorie = @cod_categorie)))
      RETURN 'invalid';
   RETURN 'valid';
END;

GO

-- Functie pentru verificare existenta Participant cu codul respectiv in tabel
CREATE OR ALTER FUNCTION existParticipant(@cod INT)
RETURNS VARCHAR(50)
AS
BEGIN
   IF (EXISTS(SELECT cod_participant FROM Participant WHERE cod_participant = @cod))
      RETURN 'da';
   RETURN 'nu';
END;
GO

-- Operatii CRUD pentru Participant
-- CREATE Participant
CREATE OR ALTER PROCEDURE CreateParticipant 
@nume NVARCHAR(100), @email NVARCHAR(100), @telefon NVARCHAR(100), @cod_categorie INT
AS
BEGIN
   IF (dbo.ValidateParticipant(@nume,@email,@telefon,@cod_categorie) = 'valid')
      INSERT INTO Participant(nume_participant,email_participant,telefon_participant,cod_categorie)
	  VALUES (@nume,@email,@telefon,@cod_categorie);
   ELSE
      PRINT 'Nu s-a efectuat crearea produsului datorita datelor necorespunzatoare.';
END;
GO

-- READ Participant
CREATE OR ALTER PROCEDURE ReadParticipant
@cod INT
AS
BEGIN
   IF (dbo.existParticipant(@cod) = 'da')
      SELECT * FROM Participant WHERE cod_participant = @cod
   ELSE
      PRINT 'Nu exista participant cu codul introdus.';
END;
GO

-- UPDATE Participant
CREATE OR ALTER PROCEDURE UpdateParticipant
@cod INT, @nume NVARCHAR(100), @email NVARCHAR(100), @telefon NVARCHAR(100), @cod_categorie INT
AS
BEGIN
   IF (dbo.existParticipant(@cod) = 'nu')
      PRINT 'Nu exista participant cu codul introdus.';
   ELSE IF (dbo.ValidateParticipant(@nume,@email,@telefon,@cod_categorie) = 'invalid')
      PRINT 'Datele introduse pentru update nu sunt valide.';
   ELSE
      BEGIN
	     UPDATE Participant
		 SET nume_participant = @nume, email_participant = @email,
		 telefon_participant = @telefon, cod_categorie = @cod_categorie
		 WHERE cod_participant = @cod;
	  END
END;
GO

-- DELETE Participant
CREATE OR ALTER PROCEDURE DeleteParticipant
@cod INT
AS
BEGIN
   IF (dbo.existParticipant(@cod) = 'nu')
      PRINT 'Nu exista participant cu codul introdus.';
   ELSE
      DELETE FROM Participant WHERE cod_participant = @cod;
END;
GO

-- Functie pentru validare Tabara
CREATE OR ALTER FUNCTION ValidateTabara(@data_inceput NVARCHAR(20), @data_sfarsit NVARCHAR(20), @nume NVARCHAR(100),
@cod_tip INT, @cod_locatie INT, @cod_sponsor INT)
RETURNS VARCHAR(50)
AS
BEGIN
   IF (@nume = '' 
       OR NOT(@data_inceput LIKE '[0-9][0-9][0-9][0-9]-[0-9][0-9]-[0-9][0-9]')
       OR NOT(@data_sfarsit LIKE '[0-9][0-9][0-9][0-9]-[0-9][0-9]-[0-9][0-9]')
	   OR @data_inceput > @data_sfarsit 
       OR NOT(EXISTS(SELECT cod_tip FROM TipTabara WHERE cod_tip = @cod_tip))
	   OR NOT(EXISTS(SELECT cod_locatie FROM Locatie WHERE cod_locatie = @cod_locatie))
	   OR NOT(EXISTS(SELECT cod_sponsor FROM Sponsor WHERE cod_sponsor = @cod_sponsor)))
	      RETURN 'invalid';
   RETURN 'valid';
END;
GO

-- Functie pentru verificare existenta Tabara cu codul respectiv in tabel
CREATE OR ALTER FUNCTION existTabara(@cod INT)
RETURNS VARCHAR(50)
AS
BEGIN
   IF (EXISTS(SELECT cod_tabara FROM Tabara WHERE cod_tabara = @cod))
      RETURN 'da';
   RETURN 'nu';
END;
GO

-- Operatii CRUD pentru Tabara
-- CREATE Tabara
CREATE OR ALTER PROCEDURE CreateTabara 
@data_inceput NVARCHAR(20), @data_sfarsit NVARCHAR(20), @nume NVARCHAR(100),
@cod_tip INT, @cod_locatie INT, @cod_sponsor INT
AS 
BEGIN
   IF (dbo.ValidateTabara(@data_inceput,@data_sfarsit,@nume,@cod_tip,@cod_locatie,@cod_sponsor) = 'valid')
      INSERT INTO Tabara(data_inceput,data_sfarsit,nume_tabara,cod_tip,cod_locatie,cod_sponsor)
	  VALUES (@data_inceput,@data_sfarsit,@nume,@cod_tip,@cod_locatie,@cod_sponsor);
   ELSE
      PRINT 'Nu s-a efectuat crearea taberei datorita datelor necorespunzatoare.';
END;
GO 

--READ Tabara
CREATE OR ALTER PROCEDURE ReadTabara
@cod INT
AS
BEGIN
   IF (dbo.existTabara(@cod) = 'da')
      SELECT * FROM Tabara WHERE cod_tabara = @cod
   ELSE
      PRINT 'Nu exista tabara cu codul introdus.';
END;
GO

--UPDATE Tabara
CREATE OR ALTER PROCEDURE UpdateTabara
@cod INT,@data_inceput NVARCHAR(20), @data_sfarsit NVARCHAR(20), @nume NVARCHAR(100),
@cod_tip INT, @cod_locatie INT, @cod_sponsor INT
AS
BEGIN
   IF (dbo.existTabara(@cod) = 'nu')
      PRINT 'Nu exista tabara cu codul introdus.';
   ELSE IF (dbo.ValidateTabara(@data_inceput,@data_sfarsit,@nume,@cod_tip,@cod_locatie,@cod_sponsor) = 'invalid')
      PRINT 'Datele introduse pentru update nu sunt valide.';
   ELSE
      BEGIN
	     UPDATE Tabara
		 SET data_inceput=@data_inceput, data_sfarsit=@data_sfarsit, nume_tabara = @nume,
		 cod_tip = @cod_tip, cod_locatie = @cod_locatie, cod_sponsor = @cod_sponsor
		 WHERE cod_tabara = @cod;
	  END
END;
GO

--DELETE Tabara
CREATE OR ALTER PROCEDURE DeleteTabara
@cod INT
AS
BEGIN
   IF (dbo.existTabara(@cod) = 'nu')
      PRINT 'Nu exista tabara cu codul introdus.';
   ELSE
      DELETE FROM Tabara WHERE cod_tabara = @cod;
END;
GO

-- Functie pentru validare TabaraParticipant
CREATE OR ALTER FUNCTION ValidateTabaraParticipant (@cod_tabara INT, @cod_participant INT, @data_inscrierii NVARCHAR(20))
RETURNS VARCHAR(50)
AS
BEGIN
   IF (dbo.existParticipant(@cod_participant) = 'nu' OR
       dbo.existTabara(@cod_tabara) = 'nu' OR
	   NOT(@data_inscrierii LIKE '[0-9][0-9][0-9][0-9]-[0-9][0-9]-[0-9][0-9]'))
	   RETURN 'invalid';
   RETURN 'valid';
END;
GO

-- Functie pentru verificare existenta TabaraParticipant cu codul respectiv in tabel
CREATE OR ALTER FUNCTION existTabaraParticipant(@cod_tabara INT,@cod_participant INT)
RETURNS VARCHAR(50)
AS
BEGIN
   IF (EXISTS(SELECT * FROM TabaraParticipant WHERE cod_tabara = @cod_tabara AND cod_participant = @cod_participant))
      RETURN 'da';
   RETURN 'nu';
END;
GO

-- Operatii CRUD pentru TabaraParticipant
-- CREATE TabaraParticipant
CREATE OR ALTER PROCEDURE CreateTabaraParticipant 
@cod_tabara INT, @cod_participant INT, @data_inscrierii NVARCHAR(20) 
AS 
BEGIN
   IF (dbo.ValidateTabaraParticipant(@cod_tabara,@cod_participant,@data_inscrierii) = 'invalid')
      PRINT 'Nu s-a efectuat crearea inscrierii TabaraParticipant datorita datelor necorespunzatoare.';
   ELSE IF (dbo.existTabaraParticipant(@cod_tabara,@cod_participant) = 'da')
      PRINT 'Exista deja o inscriere TabaraParticipant cu aceste coduri.'
   ELSE
      INSERT INTO TabaraParticipant(cod_tabara,cod_participant,data_inscrierii)
	  VALUES (@cod_tabara,@cod_participant,@data_inscrierii);
END;
GO 

-- READ TabaraParticipant
CREATE OR ALTER PROCEDURE ReadTabaraParticipant
@cod_tabara INT,@cod_participant INT
AS
BEGIN
   IF (dbo.existTabaraParticipant(@cod_tabara,@cod_participant) = 'da')
      SELECT * FROM TabaraParticipant WHERE cod_tabara = @cod_tabara AND cod_participant = @cod_participant
   ELSE
      PRINT 'Nu exista inscriere TabaraParticipant cu codul introdus.';
END;
GO

-- UPDATE TabaraParticipant
CREATE OR ALTER PROCEDURE UpdateTabaraParticipant
@cod_tabara INT, @cod_participant INT, @data_inscrierii NVARCHAR(20)
AS
BEGIN
   IF (dbo.existTabaraParticipant(@cod_tabara,@cod_participant) = 'nu')
      PRINT 'Nu exista inscriere TabaraParticipant cu codul introdus.';
   ELSE IF (dbo.ValidateTabaraParticipant(@cod_tabara,@cod_participant,@data_inscrierii) = 'invalid')
      PRINT 'Datele introduse pentru update nu sunt valide.';
   ELSE
      BEGIN
	     UPDATE TabaraParticipant
		 SET data_inscrierii = @data_inscrierii
		 WHERE cod_tabara = @cod_tabara AND cod_participant = @cod_participant;
	  END
END;
GO

--DELETE TabaraParticipant
CREATE OR ALTER PROCEDURE DeleteTabaraParticipant
@cod_tabara INT, @cod_participant INT
AS
BEGIN
   IF (dbo.existTabaraParticipant(@cod_tabara,@cod_participant) = 'nu')
      PRINT 'Nu exista inscriere TabaraParticipant cu codul introdus.';
   ELSE
      DELETE FROM TabaraParticipant WHERE cod_tabara = @cod_tabara AND cod_participant = @cod_participant;
END;
GO

-- CREARE DE VIEW-URI
-- View pentru participantii al caror nume incep cu 'S' sau 'M' impreuna cu taberele la care participa
CREATE OR ALTER VIEW ViewTabaraParticipant1 AS
SELECT P.nume_participant, T.nume_tabara FROM Participant P INNER JOIN TabaraParticipant TP
       ON P.cod_participant = TP.cod_participant INNER JOIN Tabara T
	   ON T.cod_tabara = TP.cod_tabara
	   WHERE (P.nume_participant LIKE 'S%' or P.nume_participant LIKE 'M%')	   
GO

SELECT * FROM ViewTabaraParticipant1 

GO
-- View pentru email-urile participantilor la care se va trimite data cand isi incep tabara
--(email + data incepere tabara)
CREATE OR ALTER VIEW ViewTabaraParticipant2 AS
SELECT P.email_participant, T.data_inceput FROM Participant P INNER JOIN TabaraParticipant TP
       ON P.cod_participant = TP.cod_participant INNER JOIN Tabara T
	   ON T.cod_tabara = TP.cod_tabara
GO

SELECT * FROM ViewTabaraParticipant2

GO

--CREARE DE INDECSI nonclustered
--PENTRU PRIMUL VIEW

--NU  pe nume participant =>CREATE INDEX ix_nume_participant_asc ON Participant(nume_participant ASC);

-- nume tabara
CREATE INDEX ix_nume_tabara_asc ON Tabara(nume_tabara ASC); --bun

-- NU pe cod participant =>CREATE INDEX ix_cod_participant_asc ON Participant(cod_participant ASC);

-- cod tabaraparticipant
CREATE INDEX ix_cod_tabaraparticipant_asc ON TabaraParticipant(cod_tabara ASC,cod_participant ASC); --bun

IF EXISTS (SELECT NAME FROM sys.indexes WHERE NAME = 'ix_cod_participant_asc')
   DROP INDEX ix_cod_participant_asc ON Participant;

GO

IF EXISTS (SELECT NAME FROM sys.indexes WHERE NAME = 'ix_nume_participant_asc')
   DROP INDEX ix_nume_participant_asc ON Participant;

GO

IF EXISTS (SELECT NAME FROM sys.indexes WHERE NAME = 'ix_nume_tabara_asc')
   DROP INDEX ix_nume_tabara_asc ON Tabara;

GO

--PENTRU AL DOILEA VIEW
--pe data inceput tabara
CREATE INDEX ix_data_inceput_tabara ON Tabara(data_inceput ASC) --bun

SELECT * FROM Tabara;
SELECT * FROM Participant;
SELECT * FROM TabaraParticipant;

--Apeluri:
EXEC CreateParticipant 'Mariana Colentina','mariana@yahoo.com','',2;
EXEC ReadParticipant 190;
EXEC UpdateParticipant 2,'Sasu Iulian','chanel@yahoo.com','0756213213',321983;
EXEC DeleteParticipant 23;
EXEC CreateTabara '2022-12-11','2022-12-16','Tabara Leilor',2,8,4;
EXEC ReadTabara 3
EXEC UpdateTabara 7,'2022wdewef','2022-11-16','Tabara Focului',1,5,3;
EXEC DeleteTabara 19
EXEC CreateTabaraParticipant 6,18,'2022-07-11'
EXEC ReadTabaraParticipant 6, 18
EXEC UpdateTabaraParticipant 6,18,'2022-05-13'
EXEC DeleteTabaraParticipant 6, 20