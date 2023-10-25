from helicopter.exceptions.exceptions import *
from helicopter.domain.entities import *

class HelicopterRepo:
    def __init__(self):
        self.__helicopters = []

    def getHelicopters(self):
        """
            Returneaza lista de helicoptere.
        """
        return self.__helicopters

    def addHelicopter(self, helicopter):
        """
            Adauga helicopter-ul in lista
        """
        if helicopter in self.__helicopters:
            raise RepoException("ID-ul helicopter-ului este deja in lista")
        self.__helicopters.append(helicopter)

class HelicopterRepoFile(HelicopterRepo):
    def __init__(self, fileName):
        HelicopterRepo.__init__(self)
        self.__fileName = fileName
        #incarca helicopterele din fisier
        self.__loadFromFile()

    def __createHelicopterFromLine(self, line):
        """
            Proceseaza o linie din fisier si creaza un helicopter.
            Returneaza un helicopter.
        """
        fields = line.split(",")
        heli = Helicopter(int(fields[0]), fields[1], fields[2], int(fields[3]))
        return heli

    def __loadFromFile(self):
        """
            Proceseaza helicoptere din fisier, linie cu linie.
        """
        f = open(self.__fileName)
        for line in f :
            if line.strip() == "": #daca avem o linie goala, dam skip
                continue
            heli = self.__createHelicopterFromLine(line)
            HelicopterRepo.addHelicopter(self,heli)
        f.close()

    def addHelicopter(self, heli):
        HelicopterRepo.addHelicopter(self, heli)
        self.__appendToFile(heli)

    def __appendToFile(self, heli):
       """
            Adaugam un nou helicopter pe o noua linie.
       """
       f = open(self.__fileName,"a")
       line = heli.getId_helicopter() + ',' + heli.getNume() + ',' + heli.getSir_scopuri() + ',' + heli.getAn_fab()
       f.write("\n")
       f.write(line)
       f.close()