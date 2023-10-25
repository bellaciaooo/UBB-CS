from Gestiune_produs.repository.produs_repo import *

class ProdusService:
    def __init__(self, produs_repo : ProdusRepoFile):
        self.__produs_repo = produs_repo

    def addProdus(self, id_produs, denumire, pret):
        """
            Adaugare produs la lista de produse.
        """
        newProdus = Produs(id_produs, denumire, pret)
        try:
            self.__produs_repo.addProdus(newProdus)
        except RepoException as ex:
            raise ServiceException(ex)

    def deleteProdus(self, undo_list, cifra):
        """
            Stergere produs in functie de cristeriul stabilit, cifra data sa fie in pretul produsului.
        """
        try:
            return self.__produs_repo.deleteProdus(undo_list, cifra)
        except RepoException as ex:
            raise ServiceException(ex)

    def filtrareTextPret(self, text, pret):
        """
            Se realizeaza  filtrarea produselor in functie de text si pret(cele care contin textul dat si au
            pretul mai mic decat pretul dat).
        """
        produse = self.__produs_repo.getProduse()
        produse_filtrate = [produs for produs in produse if text in produs.getDenumire() and int(produs.getPret()) < int(pret)]
        return produse_filtrate

    def filtrareText(self, text):
        """
            Se realizeaza  filtrarea produselor in functie de text(cele care contin textul dat).
        """
        produse = self.__produs_repo.getProduse()
        produse_filtrate = [produs for produs in produse if text in produs.getDenumire()]
        return produse_filtrate

    def filtrarePret(self, pret):
        """
            Se realizeaza  filtrarea produselor in functie de pret(cele care au pretul mai mic decat pretul dat).
        """
        produse = self.__produs_repo.getProduse()
        produse_filtrate = [produs for produs in produse if int(produs.getPret())<pret]
        return produse_filtrate

    def undo(self, undo_list):
        """
            Se realizeaza operatia de undo.
        """
        self.__produs_repo.undo(undo_list)
