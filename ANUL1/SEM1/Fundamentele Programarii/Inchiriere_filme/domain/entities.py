from dataclasses import dataclass

@dataclass
class Film:
    def __init__(self, id_film, titlu, descriere, gen, nr_filme_disponibile):
        self.__id_film = id_film
        self.__titlu = titlu
        self.__descriere = descriere
        self.__gen = gen
        self.__nr_filme_disponibile = nr_filme_disponibile

    def getId_film(self):
        return self.__id_film

    def getTitlu(self):
        return self.__titlu

    def getDescriere(self):
        return self.__descriere

    def getGen(self):
        return self.__gen

    def getNr_filme_disponibile(self):
        return self.__nr_filme_disponibile

    def setId_film(self, value):
        self.__id_film = value

    def setTitlu(self, value):
        self.__titlu = value

    def setDescriere(self, value):
        self.__descriere = value

    def setGen(self, value):
        self.__gen = value

    def setNr_filme_disponibile(self, value):
        self.__nr_filme_disponibile = value

    def increase_nr_filme_disponibile(self):
        currentNr = self.getNr_filme_disponibile()
        self.setNr_filme_disponibile(currentNr + 1)

    def decrease_nr_filme_disponibile(self):
        currentNr = self.getNr_filme_disponibile()
        self.setNr_filme_disponibile(currentNr - 1)

    def __eq__(self, other):
        return self.getId_film() == other.getId_film()

    def __str__(self):
        return f"ID: {self.__id_film}, Titlu: {self.__titlu}, Descriere: {self.__descriere}, Gen: {self.__gen}, Numar filme disponibile: {self.__nr_filme_disponibile}"

class Client:
    def __init__(self, id_client, nume, cnp):
        self.__id_client = id_client
        self.__nume = nume
        self.__cnp = cnp

    def getId_client(self):
        return self.__id_client

    def getNume(self):
        return self.__nume

    def getCnp(self):
        return self.__cnp

    def setId_client(self, value):
        self.__id_client = value

    def setNume(self, value):
        self.__nume = value

    def setCnp(self, value):
        self.__cnp = value

    def __eq__(self, other):
        return self.getId_client() == other.getId_client()

    def __str__(self):
        return f"ID: {self.__id_client}, Nume: {self.__nume}, CNP: {self.__cnp}"

class Inchiriere:
    def __init__(self, id_client, id_film, data_inchirierii):
        self.__id_client = id_client
        self.__id_film = id_film
        self.__data_inchirierii = data_inchirierii

    def getId_client(self):
        return self.__id_client

    def getId_film(self):
        return self.__id_film

    def getData_inchirierii(self):
        return self.__data_inchirierii

    def setId_client(self, value):
        self.__id_client = value

    def setId_film(self, value):
        self.__id_film = value

    def setData_inchirierii(self, value):
        self.__data_inchirierii = value

    def __eq__(self, other):
        return self.getId_client() == other.getId_client() and self.getId_film() == other.getId_film()

    def __str__(self):
        return f"ID Client: {self.__id_client}, ID Film: {self.__id_film}, Data inchirierii: {self.__data_inchirierii}"