USE GestiuneTabere;
GO

-- 0) Creati o noua tabela care sa memoreze versiunea structurii bazei de date (in tabela va fi o singura inregistrare)
CREATE TABLE Versiune
( cod_versiune INT PRIMARY KEY IDENTITY,
  versiune INT
);
INSERT INTO Versiune(versiune) VALUES (0);

GO

-- 1) MODIFICA tipul unei coloane (pt coloana data_activitate tranformam din date in datetime) 
CREATE PROCEDURE DateToDatetimeActivitate
AS
BEGIN
ALTER TABLE Activitate
ALTER COLUMN data_activitate datetime;
UPDATE Versiune
SET versiune=1
END;

GO

-- UNDO MODIFICA tipul unei coloane (pt coloana data_activitate tranformam din datetime in date)
CREATE PROCEDURE DatetimeToDateActivitate
AS
BEGIN
ALTER TABLE Activitate
ALTER COLUMN data_activitate date;
UPDATE Versiune
SET versiune=0
END;

GO

-- 2) ADAUGA o costrangere de "valoare implicita" pentru un camp (CategorieVarsta - contraindicatii)
CREATE PROCEDURE AdaugaDefaultContraindicatii
AS 
BEGIN
ALTER TABLE CategorieVarsta
ADD CONSTRAINT df_contraindicatii DEFAULT N'Nu au contraindicatii' FOR contraindicatii;
UPDATE Versiune
SET versiune=2
END;

GO 

-- STERGE o costrangere de "valoare implicita" pentru un camp (CategorieVarsta - contraindicatii) 
CREATE PROCEDURE StergeDefaultContraindicatii
AS 
BEGIN
ALTER TABLE CategorieVarsta
DROP CONSTRAINT df_contraindicatii;
END;
UPDATE Versiune
SET versiune=1
GO 

-- 3) CREEA o tabelă (Asistent - Tabara) 
CREATE PROCEDURE CreeazaTabelaAsistent
AS
BEGIN
CREATE TABLE Asistent
( cod_asistent INT PRIMARY KEY IDENTITY,
  nume_asistent NVARCHAR(100),
  telefon_asistent NVARCHAR(100)
);
UPDATE Versiune
SET versiune=3
END;

GO

-- STERGE o tabela (Asistent - Tabara) 
CREATE PROCEDURE StergeTabelaAsistent
AS
BEGIN
DROP TABLE Asistent;
UPDATE Versiune
SET versiune=2
END;

GO

-- 4) ADAUGA un camp nou (Asistent - cod_tabara) 
CREATE PROCEDURE AdaugaCodTabara
AS
BEGIN
ALTER TABLE Asistent
ADD cod_tabara INT;
UPDATE Versiune
SET versiune=4
END;

GO

-- STERGE un camp nou (Asistent - cod_tabara) 
CREATE PROCEDURE StergeCodTabara
AS
BEGIN
ALTER TABLE Asistent
DROP COLUMN cod_tabara;
UPDATE Versiune
SET versiune=3
END;

GO

-- 5) CREEA o constrângere de cheie straina (Asistent - cod_tabara)
CREATE PROCEDURE CreeazaForeignKey
AS
BEGIN
ALTER TABLE Asistent
ADD CONSTRAINT fk_cod_tabara FOREIGN KEY (cod_tabara) REFERENCES Tabara(cod_tabara) ON UPDATE CASCADE ON DELETE CASCADE
UPDATE Versiune
SET versiune=5
END;

GO

-- STERGE o constrangere de cheie straina (Asistent - cod_tabara) : Versiunea 9
CREATE PROCEDURE StergeForeignKey
AS
BEGIN
ALTER TABLE Asistent
DROP CONSTRAINT fk_cod_tabara
UPDATE Versiune
SET versiune=4
END;

GO

-- 6) Scrieti o alta procedura stocata ce primeste ca parametru un numar de versiune si aduce baza de date la 
-- versiunea respectiva
CREATE PROCEDURE UpdateVersiune @versiune INT
AS
BEGIN
DECLARE @versiuneCurenta AS INT

DECLARE @proceduri TABLE (id INT, nume VARCHAR(100))
INSERT INTO @proceduri VALUES (0,'DateToDatetimeActivitate'),(1,'AdaugaDefaultContraindicatii'),
(2,'CreeazaTabelaAsistent'),(3,'AdaugaCodTabara'),(4,'CreeazaForeignKey');

DECLARE @undo TABLE (id INT,nume VARCHAR(100))
INSERT INTO @undo VALUES (1,'DatetimeToDateActivitate'),(2,'StergeDefaultContraindicatii'),(3,'StergeTabelaAsistent'),
(4,'StergeCodTabara'),(5,'StergeForeignKey');

SELECT @versiuneCurenta = versiune FROM Versiune WHERE cod_versiune=1

IF(@versiune > 5 OR @versiune < 0)
   PRINT 'Nu exista versiunea introdusa';
ELSE
BEGIN
WHILE(@versiuneCurenta < @versiune)
BEGIN
  DECLARE @procedura AS VARCHAR(100)
  SELECT @procedura = nume FROM @proceduri WHERE id=@versiuneCurenta
  EXEC @procedura
  SELECT @versiuneCurenta = versiune FROM Versiune WHERE cod_versiune=1
END
WHILE(@versiuneCurenta > @versiune)
BEGIN
  DECLARE @op_undo AS VARCHAR(100)
  SELECT @op_undo = nume FROM @undo WHERE id=@versiuneCurenta
  EXEC @op_undo
  SELECT @versiuneCurenta = versiune FROM Versiune WHERE cod_versiune=1
END
END
END;

SELECT * FROM Versiune
EXEC UpdateVersiune 0;