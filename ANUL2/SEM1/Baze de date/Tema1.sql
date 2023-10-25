/*CREATE DATABASE GestiuneTabere;

GO*/

USE GestiuneTabere;

CREATE TABLE TipTabara
( cod_tip INT PRIMARY KEY IDENTITY,
  tip_tabara NVARCHAR(100) NOT NULL,
  descriere_tip NVARCHAR(200)
  );

CREATE TABLE Locatie
( cod_locatie INT PRIMARY KEY IDENTITY,
  nume_locatie NVARCHAR(100) NOT NULL,
  descriere_locatie NVARCHAR(200) 
);

CREATE TABLE Coordonator
( cod_coordonator INT PRIMARY KEY IDENTITY,
  nume_coordonator NVARCHAR(100) NOT NULL,
  email_coordonator NVARCHAR(100) UNIQUE,
  telefon_coordonator NVARCHAR(100)
);

CREATE TABLE Sponsor
( cod_sponsor INT PRIMARY KEY IDENTITY,
  nume_sponsor NVARCHAR(100) NOT NULL,
  email_sponsor NVARCHAR(100) UNIQUE,
  telefon_sponsor NVARCHAR(100)
);

CREATE TABLE CategorieVarsta
( cod_categorie INT PRIMARY KEY IDENTITY,
  categorie NVARCHAR(100) NOT NULL,
  contraindicatii NVARCHAR(200)
);

CREATE TABLE Participant
( cod_participant INT PRIMARY KEY IDENTITY,
  nume_participant NVARCHAR(100) NOT NULL,
  email_participant NVARCHAR(100) UNIQUE,
  telefon_participant NVARCHAR(100),
  cod_categorie INT FOREIGN KEY REFERENCES CategorieVarsta(cod_categorie) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE Tabara
( cod_tabara INT PRIMARY KEY IDENTITY,
  data_inceput DATE,
  data_sfarsit DATE,
  nume_tabara NVARCHAR(100) NOT NULL,
  cod_tip INT FOREIGN KEY REFERENCES TipTabara(cod_tip) ON UPDATE CASCADE ON DELETE CASCADE,
  cod_locatie INT FOREIGN KEY REFERENCES Locatie(cod_locatie) ON UPDATE CASCADE ON DELETE CASCADE,
  cod_sponsor INT FOREIGN KEY REFERENCES Sponsor(cod_sponsor) ON UPDATE CASCADE ON DELETE CASCADE,
  CONSTRAINT ck_data CHECK (data_inceput <= data_sfarsit)
);

CREATE TABLE Activitate
( cod_activitate INT PRIMARY KEY IDENTITY,
  nume_activitate NVARCHAR(100) NOT NULL,
  data_activitate DATE,
  descriere_activitate NVARCHAR(200),
  cod_tabara INT FOREIGN KEY REFERENCES Tabara(cod_tabara) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE TabaraCoordonator
( cod_tabara INT FOREIGN KEY REFERENCES Tabara(cod_tabara) ON UPDATE CASCADE ON DELETE CASCADE,
  cod_coordonator INT FOREIGN KEY REFERENCES Coordonator(cod_coordonator) ON UPDATE CASCADE ON DELETE CASCADE, 
  CONSTRAINT pk_TabaraCoordonator PRIMARY KEY (cod_tabara, cod_coordonator) 
);

CREATE TABLE TabaraParticipant 
( cod_tabara INT FOREIGN KEY REFERENCES Tabara(cod_tabara) ON UPDATE CASCADE ON DELETE CASCADE,
  cod_participant INT FOREIGN KEY REFERENCES Participant(cod_participant) ON UPDATE CASCADE ON DELETE CASCADE,
  CONSTRAINT pk_TabaraParticipant PRIMARY KEY (cod_tabara, cod_participant)
);