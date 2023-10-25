
class Helicopter:
    """
        Clasa pentru incapsularea formatului unui helicopter.
    """
    def __init__(self, id_helicopter, nume , sir_scopuri , an_fab):
        self.__id_helicopter = id_helicopter
        self.__nume = nume
        self.__sir_scopuri = sir_scopuri
        self.__an_fab = an_fab

    def getId_helicopter(self):
        return self.__id_helicopter

    def getNume(self):
        return self.__nume

    def getSir_scopuri(self):
        return self.__sir_scopuri

    def getAn_fab(self):
        return self.__an_fab

    def setId_helicopter(self, value):
        self.__id_helicopter = value

    def setNume(self, value):
        self.__nume = value

    def setSir_scopuri(self, value):
        self.__sir_scopuri = value

    def setAn_fab(self, value):
        self.__an_fab = value

    def __eq__(self, other):
        return self.getId_helicopter() == other.getId_helicopter()

    def __str__(self):
        return f"ID helicopter: {self.__id_helicopter}, Nume: {self.__nume}, Scopuri: {self.__sir_scopuri}, Anul fabricatiei: {self.__an_fab}"

class Grupare:
    """
       Clasa pentru reprezentarea gruparilor dupa scopuri.
    """
    def __init__(self, nume_scop):
        self.__nume_scop = nume_scop
        self.__ani = set()

    def addAn(self, an):
        self.__ani.add(an)

    def getNume_scop(self):
        return self.__nume_scop

    def __str__(self):
        return f"Numele scopului: {self.__nume_scop} , anii: {self.__ani}"
