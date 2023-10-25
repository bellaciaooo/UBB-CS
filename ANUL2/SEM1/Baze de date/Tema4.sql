USE GestiuneTabere
GO

-- Adaugam tabelele de testare
INSERT INTO Tables(Name) 
VALUES ('Activitate'), -- un PK + un FK 
('TabaraCoordonator'), -- 2 campuri PK
('Coordonator'); -- un PK
GO

-- Creare view-urilor
CREATE OR ALTER VIEW View_1 AS
  SELECT * FROM CategorieVarsta;
GO

CREATE OR ALTER VIEW View_2 AS
  SELECT P.nume_participant, C.categorie FROM Participant P INNER JOIN CategorieVarsta C 
  ON P.cod_categorie = C.cod_categorie;
GO

CREATE OR ALTER VIEW View_3 AS
  SELECT C.categorie, COUNT(P.cod_categorie) as 'NrClienti' FROM Participant P INNER JOIN CategorieVarsta C 
  ON P.cod_categorie = C.cod_categorie WHERE P.cod_categorie = C.cod_categorie GROUP BY C.categorie;
GO

-- Adaugam view-urile de testare
INSERT INTO Views(Name)
VALUES('View_1'),
('View_2'),
('View_3');
GO

-- Adaugam inregistrarea testului
INSERT INTO Tests(Name)
VALUES ('test');
GO

-- Adaugam in TestView 
INSERT INTO TestViews(TestID,ViewID)
VALUES (6,1),
       (6,2),
	   (6,3);
GO

-- Adaugam in TestTables
INSERT INTO TestTables(TestID,TableID,NoOfRows,Position)
VALUES (6,1,100,1),
       (6,2,100,2),
	   (6,3,100,3);
GO

--Procedura pentru stergerea tabelelor
CREATE OR ALTER PROCEDURE StergereTabele
AS
BEGIN
    --selectam primul tabel de sters in ordinea data de position
    DECLARE @tableid INT;
	SELECT @tableid = TableID FROM TestTables 
	WHERE Position = 1;

    DECLARE @table NVARCHAR(50); 
	SELECT @table = Name FROM Tables
	WHERE TableID = @tableid;

	--stergem din primul tabel
	DECLARE @sql NVARCHAR(50);
    SET @sql = 'DELETE FROM '+ @table;
	EXECUTE(@sql);

	--selectam al doilea tabel
	SELECT @tableid = TableID FROM TestTables 
	WHERE Position = 2;

	SELECT @table = Name FROM Tables
	WHERE TableID = @tableid;

	--stergem din al doilea tabel
    SET @sql = 'DELETE FROM '+ @table;
	EXECUTE(@sql);

	--selectam al treilea tabel
	SELECT @tableid = TableID FROM TestTables 
	WHERE Position = 3;

	SELECT @table = Name FROM Tables
	WHERE TableID = @tableid;

	--stergem din al treilea tabel
    SET @sql = 'DELETE FROM '+ @table;
	EXECUTE(@sql)

END;
GO

--Procedura pentru inserarea in tabela Coordonator
CREATE OR ALTER PROCEDURE InserareCoordonator(@noOfRows INT)
AS 
BEGIN
    SET NOCOUNT ON;
    DECLARE @indexCurent INT;
    SET @indexCurent = 1;
	DECLARE @nume NVARCHAR(100),@email NVARCHAR(100),@telefon NVARCHAR(100);

	WHILE @indexCurent <= @noOfRows
	BEGIN
	   SET @nume = CONCAT('Nume', RAND());
	   SET @email = CONCAT('Email', RAND(),'@gmail.com');
	   SET @telefon = CONCAT('0770', FLOOR(100000 + RAND() * (120000-100000)));

	   INSERT INTO Coordonator(nume_coordonator,email_coordonator,telefon_coordonator) VALUES
	   (@nume,@email,@telefon);
	   SET @indexCurent = @indexCurent + 1;
	END;
END; 
GO

--Procedura pentru inserarea in tabela Activitate
CREATE OR ALTER PROCEDURE InserareActivitate(@noOfRows INT)
AS 
BEGIN
    SET NOCOUNT ON;
    DECLARE @indexCurent INT;
    SET @indexCurent = 1;
	DECLARE @nume NVARCHAR(100),@data DATETIME,@descriere NVARCHAR(200),@cod_tabara INT;

	WHILE @indexCurent <= @noOfRows
	BEGIN
	    SET @nume = CONCAT('NumeActivitate', RAND());
		SET @data = GETDATE();
		SET @descriere = CONCAT('Descriere',RAND());
	    SELECT @cod_tabara = MAX(cod_tabara) FROM Tabara;

		INSERT INTO Activitate(nume_activitate,descriere_activitate,data_activitate,cod_tabara) VALUES
		(@nume,@descriere,@data,@cod_tabara);	
		SET @indexCurent = @indexCurent + 1;
	END;	
END;
GO

--Procedura pentru inserare in tabela TabaraCoordonator
CREATE OR ALTER PROCEDURE InserareTabaraCoordonator(@noOfRows INT)
AS
BEGIN
	SET NOCOUNT ON;
    DECLARE @indexCurent INT;
    SET @indexCurent = 1;
	DECLARE @cod_tabara INT,@cod_coordonator INT;
	SELECT @cod_tabara = MAX(cod_tabara) FROM Tabara;

	DECLARE cursorCoordonator CURSOR FAST_FORWARD FOR
	SELECT cod_coordonator FROM Coordonator;
	OPEN cursorCoordonator;
	FETCH NEXT FROM cursorCoordonator INTO @cod_coordonator;
	WHILE @@FETCH_STATUS=0 AND @indexCurent <= @noOfRows
	BEGIN
		INSERT INTO TabaraCoordonator(cod_tabara,cod_coordonator) VALUES 
		(@cod_tabara,@cod_coordonator);

		FETCH NEXT FROM cursorCoordonator INTO @cod_coordonator;
		SET @indexCurent = @indexCurent + 1;
	END;
	CLOSE cursorCoordonator;
	DEALLOCATE cursorCoordonator;
END;
GO

CREATE OR ALTER PROCEDURE InserareTabele(@TestRunID INT)
AS 
BEGIN
    SET NOCOUNT ON;

    --declaram timpii pentru TestRunTables
	DECLARE @StartAt DATETIME, @EndAt DATETIME;
	DECLARE @sql NVARCHAR(100);

	--selectam primul tabel de sters in ordinea inversa data de position
    DECLARE @tableid INT;
	SELECT @tableid = TableID FROM TestTables 
	WHERE Position = 3;

    DECLARE @table NVARCHAR(50); 
	SELECT @table = Name FROM Tables
	WHERE TableID = @tableid;

	DECLARE @noOfRows INT;
	SELECT @noOfRows = NoOfRows FROM TestTables
	WHERE TableID = @tableid;

	--inseram in tabelul corespunzator
	SET @sql = CONCAT('EXEC Inserare',@table,' ',@noOfRows);
	SET @StartAt = GETDATE();
	EXECUTE(@sql);
	SET @EndAt = GETDATE();

	--inseram in tabelul TestRunTables datele testului pe tabelul respectiv
	INSERT INTO TestRunTables(TestRunID,TableID,StartAt,EndAt) VALUES 
	(@TestRunID,@tableid,@StartAt,@EndAt);


	--selectam al doilea tabel de sters in ordinea inversa data de position
	SELECT @tableid = TableID FROM TestTables 
	WHERE Position = 2;

	SELECT @table = Name FROM Tables
	WHERE TableID = @tableid;

	SELECT @noOfRows = NoOfRows FROM TestTables
	WHERE TableID = @tableid;
	
	--inseram in tabelul corespunzator
	SET @sql = CONCAT('EXEC Inserare',@table,' ',@noOfRows);
	SET @StartAt = GETDATE();
	EXECUTE(@sql);
	SET @EndAt = GETDATE();

	--inseram in tabelul TestRunTables datele testului pe tabelul respectiv
	INSERT INTO TestRunTables(TestRunID,TableID,StartAt,EndAt) VALUES 
	(@TestRunID,@tableid,@StartAt,@EndAt);

	--selectam al treilea tabel de sters in ordinea inversa data de position
	SELECT @tableid = TableID FROM TestTables 
	WHERE Position = 1;

	SELECT @table = Name FROM Tables
	WHERE TableID = @tableid;

	SELECT @noOfRows = NoOfRows FROM TestTables
	WHERE TableID = @tableid;
	
	--inseram in tabelul corespunzator
	SET @sql = CONCAT('EXEC Inserare',@table,' ',@noOfRows);
	SET @StartAt = GETDATE();
	EXECUTE(@sql);
	SET @EndAt = GETDATE();

	--inseram in tabelul TestRunTables datele testului pe tabelul respectiv
	INSERT INTO TestRunTables(TestRunID,TableID,StartAt,EndAt) VALUES 
	(@TestRunID,@tableid,@StartAt,@EndAt);

END; 
GO

CREATE OR ALTER PROCEDURE EvaluareViews(@TestRunID INT)
AS
BEGIN
    SET NOCOUNT ON;

	--declaram timpii pentru TestRunViews
	DECLARE @StartAt DATETIME, @EndAt DATETIME;
	DECLARE @view NVARCHAR(50);
	DECLARE @sql NVARCHAR(100);

	--pentru primul view
    SELECT @view = Name FROM Views V INNER JOIN TestViews TV ON V.ViewID = TV.ViewID
	WHERE TV.ViewID = 1;
	SET @sql = CONCAT('SELECT * FROM ',@view);

	SET @StartAt = GETDATE();
	EXECUTE(@sql);
	SET @EndAt = GETDATE();

	--inseram in tabelul TestRunViews datele testului pe view-ul respectiv
	INSERT INTO TestRunViews(TestRunID,ViewID,StartAt,EndAt) VALUES
	(@TestRunID,1,@StartAt,@EndAt);

	--pentru al doilea view
    SELECT @view = Name FROM Views V INNER JOIN TestViews TV ON V.ViewID = TV.ViewID
	WHERE TV.ViewID = 2;
	SET @sql = CONCAT('SELECT * FROM ',@view);

	SET @StartAt = GETDATE();
	EXECUTE(@sql);
	SET @EndAt = GETDATE();

	--inseram in tabelul TestRunViews datele testului pe view-ul respectiv
	INSERT INTO TestRunViews(TestRunID,ViewID,StartAt,EndAt) VALUES
	(@TestRunID,2,@StartAt,@EndAt);

	--pentru al treilea view
    SELECT @view = Name FROM Views V INNER JOIN TestViews TV ON V.ViewID = TV.ViewID
	WHERE TV.ViewID = 3;
	SET @sql = CONCAT('SELECT * FROM ',@view);

	SET @StartAt = GETDATE();
	EXECUTE(@sql);
	SET @EndAt = GETDATE();

	--inseram in tabelul TestRunViews datele testului pe view-ul respectiv
	INSERT INTO TestRunViews(TestRunID,ViewID,StartAt,EndAt) VALUES
	(@TestRunID,3,@StartAt,@EndAt);

END;
GO

CREATE OR ALTER PROCEDURE TestPrincipal
AS 
BEGIN
    SET NOCOUNT ON;

	--declaram timpii pentru TestRuns
	DECLARE @StartAt DATETIME, @EndAt DATETIME;
	SET @StartAt = GETDATE();

	--inseram inregistrarea testului
	INSERT INTO TestRuns(StartAt) VALUES (@StartAt);

	DECLARE @idTestCurent INT;
	SELECT @idTestCurent = MAX(TestRunID) FROM TestRuns;

	--stergerea datelor din tabelele asociate testului
	EXEC StergereTabele;
	
	--inserarea inregistrarilor in tabelele asociate testului
	EXEC InserareTabele @idTestCurent;

	--evaluarea timpului de executie a view-urilor
	EXEC EvaluareViews @idTestCurent;

	SET @EndAt = GETDATE();
	UPDATE TestRuns
	SET EndAt = @EndAt
	WHERE TestRunID = @idTestCurent;
END;
GO

EXEC TestPrincipal
GO

SELECT * FROM TestRuns
SELECT * FROM TestRunTables
SELECT * FROM TestRunViews

DELETE FROM TestRunTables
DELETE FROM TestRunViews
DELETE FROM TestRuns
