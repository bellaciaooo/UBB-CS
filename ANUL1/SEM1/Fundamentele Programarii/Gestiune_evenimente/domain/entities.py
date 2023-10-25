from dataclasses import dataclass

@dataclass
class Eveniment:
    def __init__(self, data, ora, descriere):
        self.__data = data
        self.__ora = ora
        self.__descriere = descriere

    def getData(self):
        return self.__data

    def getOra(self):
        return self.__ora

    def getDescriere(self):
        return self.__descriere
