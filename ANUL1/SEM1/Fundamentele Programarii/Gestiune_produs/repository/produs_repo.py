from Gestiune_produs.domain.entities import *
from Gestiune_produs.exceptions.exceptions import *

class ProdusRepoFile:
    def __init__(self, fileName):
        self.__fileName = fileName
        self.__load_from_file()

    def __load_from_file(self):
        """
            Incarcarea din fisier a produselor curente.
        """
        try:
            f = open(self.__fileName, 'r')
        except IOError:
            raise CorruptedFileException("File Error: Nu exista fisierul cu numele dat!")

        produse = []
        lines = f.readlines()
        for line in lines:
            id_produs, denumire, pret = [token.strip() for token in line.split(',')]
            produs = Produs(int(id_produs), denumire, pret)
            produse.append(produs)

        f.close()
        return produse

    def __save_to_file(self, produse):
        """
            Salvare in fisier lista de produse curenta.
        """
        with open(self.__fileName, 'w') as f:
            for produs in produse:
                produs_string = str(produs.getId_produs()) + ',' + str(produs.getDenumire()) + ',' + str(produs.getPret()) + '\n'
                f.write(produs_string)

    def addProdus(self, produs):
        """
            Se realizeaza adaugarea unui produs la lista de produse din fisier
        :param produs: produsul de adaugat
        """
        all_produse = self.__load_from_file()
        if produs in all_produse:
            raise RepoException("Id-ul produsului se afla deja in lista de produse!")
        all_produse.append(produs)
        self.__save_to_file(all_produse)

    def deleteProdus(self, undo_list, cifra):
        """
            Sterge produsele din lista in functie de cele care au in pretul sau cifra data
        :param cifra: criteriul de stergere
        :return: numarul de produse sterse din lista
        """
        all_produse = self.__load_from_file()
        nr_produse_sterse = 0
        produse_de_sters = [produs for produs in all_produse if cifra in produs.getPret()]
        #salvam pentru undo
        cpy = all_produse[:]
        self.save_for_undo(undo_list, cpy)
        for produs in produse_de_sters:
            all_produse.remove(produs)
            nr_produse_sterse = nr_produse_sterse + 1
        self.__save_to_file(all_produse)
        if nr_produse_sterse == 0:
            raise RepoException("Nu exista produse care sa contina in pret cifra data! Nu s-a sters niciun produs!")
        return nr_produse_sterse

    def getProduse(self):
        return self.__load_from_file()

    def save_for_undo(self, undo_list, produse):
        """
            Se salveaza starea precedenta operatiei de stergere.
        """
        undo_list.append(produse)

    def undo(self, undo_list):
        """
            Se restabilesc elementele din fisier la starea lor precedenta
        """
        produse_vechi = undo_list.pop()
        self.__save_to_file(produse_vechi)

