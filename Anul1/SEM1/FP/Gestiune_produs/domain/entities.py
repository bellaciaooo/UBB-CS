from dataclasses import dataclass

@dataclass
class Produs:
    def __init__(self, id_produs, denumire, pret):
        self.__id_produs = id_produs
        self.__denumire = denumire
        self.__pret = pret

    def getId_produs(self):
        return self.__id_produs

    def getDenumire(self):
        return self.__denumire

    def getPret(self):
        return self.__pret

    def setId_produs(self, value):
        self.__id_produs = value

    def setDenumire(self, value):
        self.__denumire = value

    def setPret(self, value):
        self.__pret = value

    def __eq__(self, other):
        return self.getId_produs() == other.getId_produs()

    def __str__(self):
        return f"Id produs: {self.__id_produs}, Denumire: {self.__denumire}, Pret: {self.__pret} "