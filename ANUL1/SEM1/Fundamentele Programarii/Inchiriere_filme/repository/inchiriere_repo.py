from Inchiriere_filme.exceptions.exceptions import *
from Inchiriere_filme.domain.entities import *

class InchiriereRepository:
    def __init__(self):
        self.__inchirieri= []

    def getInchirieri(self):
        return self.__inchirieri

    def checkInchiriatByClient(self, id_film, id_client):
        """
            Cauta in lista inchirierea avand id-ul clientului egal cu id_client si id-ul filmului egal cu id_film
            Returneaza * inchirierea, daca acesta exista in lista
                       * ridica exceptie, in caz contrar
        """
        for i in range (len(self.__inchirieri)):
            if self.__inchirieri[i].getId_film() == id_film and self.__inchirieri[i].getId_client() == id_client:
                return self.__inchirieri[i]
        raise RepoException("Inchirierea cu id-ul dat nu exista!")

    def addInchiriere(self, inchiriere):
        """
            Adaugam o inchiriere la lista de inchirieri.
        """
        if inchiriere in self.__inchirieri:
            raise RepoException("Id-ul inchirierii este deja in lista!")
        self.__inchirieri.append(inchiriere)

    def deleteInchiriere(self, id_film, id_client):
        """
            Sterge inchirierea in functie de id film si id client.
        """
        for i in range(len(self.__inchirieri)):
            if self.__inchirieri[i].getId_film() == id_film and self.__inchirieri[i].getId_client() == id_client:
                self.__inchirieri.pop(i)
                return
        raise RepoException("Delete error: Nu exista inchiriere cu id-urile specificate!")

    def updateInchiriere(self, newInchiriere):
        """
            Modifica data inchirierii in functie de id film si id client aflate deja in corelatie.
        """
        for i in range(len(self.__inchirieri)):
            if self.__inchirieri[i] == newInchiriere:
                self.__inchirieri[i] = newInchiriere
                return
        raise RepoException("Update error: Nu exista inchiriere cu id-urile specificate!")


class InchiriereRepoFile:
    def __init__(self, fileName):
        self.__fileName = fileName

    def __load_from_file(self):
        try:
            f = open(self.__fileName, 'r')
        except IOError:
            raise CorruptedFileException("File Error: Nu exista fisierul cu numele dat!")

        inchirieri = []
        lines = f.readlines()
        for line in lines:
            id_client, id_film, data_inchirierii = [token.strip() for token in line.split(',')]
            inchiriere = Inchiriere(int(id_client), int(id_film), data_inchirierii)
            inchirieri.append(inchiriere)

        f.close()
        return inchirieri

    def __save_to_file(self, inchirieri):
        with open(self.__fileName, 'w') as f:
            for inchiriere in inchirieri :
                inchiriere_string = str(inchiriere.getId_client()) + ',' + str(inchiriere.getId_film()) + ',' + str(inchiriere.getData_inchirierii()) + '\n'
                f.write(inchiriere_string)

    def getInchirieri(self):
        return self.__load_from_file()

    def checkInchiriatByClient(self, id_film, id_client):
        """
            Cauta in lista inchirierea avand id-ul clientului egal cu id_client si id-ul filmului egal cu id_film
            Returneaza * inchirierea, daca acesta exista in lista
                       * ridica exceptie, in caz contrar
        """
        all_inchirieri = self.__load_from_file()
        for i in range(len(all_inchirieri)):
            if all_inchirieri[i].getId_client() == id_client and all_inchirieri[i].getId_film() == id_film:
                return all_inchirieri[i]
        raise RepoException("Inchirierea cu id-ul dat nu exista!")

    def addInchiriere(self, inchiriere):
        """
            Adaugam o inchiriere la lista de inchirieri
        """
        all_inchirieri = self.__load_from_file()
        if inchiriere in all_inchirieri:
            raise RepoException("Id-ul inchirierii exista deja in lista!")
        all_inchirieri.append(inchiriere)
        self.__save_to_file(all_inchirieri)

    def deleteInchiriere(self, id_film, id_client):
        """
            Sterge inchirierea in functie de id_film si id_client
        """
        all_inchirieri = self.__load_from_file()
        for i in range(len(all_inchirieri)):
            if all_inchirieri[i].getId_film() == id_film and all_inchirieri[i].getId_client() == id_client:
                all_inchirieri.pop(i)
                self.__save_to_file(all_inchirieri)
                return
        raise RepoException("Delete Error: Nu exista inchiriere cu id-urile specificate!")

    def updateInchiriere(self, newInchiriere):
        """
            Modifica data inchirierii in functie de id film si id client aflate deja in corelatie.
        """
        all_inchirieri = self.__load_from_file()
        for i in range(len(all_inchirieri)):
            if all_inchirieri[i] == newInchiriere:
                all_inchirieri[i] = newInchiriere
                self.__save_to_file(all_inchirieri)
                return
        raise RepoException("Update Error: Nu exista inchiriere cu id-urile specificate!")