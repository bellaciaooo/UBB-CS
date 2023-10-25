from Inchiriere_filme.repository.film_repo import *
from Inchiriere_filme.repository.client_repo import *
from Inchiriere_filme.repository.inchiriere_repo import *
from Inchiriere_filme.validators.validators import *
from datetime import date


class InchiriereService:
    def __init__(self, inchiriere_repo: InchiriereRepository, inchiriere_validator: InchiriereValidator,
                 film_repo: FilmRepository, film_validator: FilmValidator, client_repo: ClientRepository,
                 client_validator: ClientValidator):
        self.__inchiriere_repo = inchiriere_repo
        self.__inchiriere_validator = inchiriere_validator
        self.__film_repo = film_repo
        self.__film_validator = film_validator
        self.__client_repo = client_repo
        self.__client_validator = client_validator

    def getInchirieri(self):
        return self.__inchiriere_repo.getInchirieri()

    def addInchiriere(self, id_client, id_film, data_inchirierii):
        newInchiriere = Inchiriere(id_client, id_film, data_inchirierii)
        try:
            self.__inchiriere_validator.validate(newInchiriere)
            try:
                self.__inchiriere_repo.addInchiriere(newInchiriere)
            except RepoException as ex:
                raise ServiceException(ex)
        except ValidatorException as ex:
            raise ServiceException(ex)

    def deleteInchiriere(self, id_client, id_film):
        try:
            self.__inchiriere_repo.deleteInchiriere(id_film, id_client)
        except RepoException as ex:
            raise ServiceException(ex)

    def searchInchiriereById(self, id_film, id_client):
        return self.__inchiriere_repo.checkInchiriatByClient(id_film, id_client)

    def inchiriazaFilm(self, id_client, id_film, data):
        # verifica daca exista vreun client cu id-ul id_client si vreun film cu id-ul id_film
        client = self.__client_repo.searchClientById(id_client)
        film = self.__film_repo.searchFilmById(id_film)
        if film.getNr_filme_disponibile() == 0:
            raise ServiceException("Nu exista exemplare disponibile!")
        self.addInchiriere(id_client, id_film, data)
        film.decrease_nr_filme_disponibile()
        self.__film_repo.updateFilm(film)

    def returneazaFilm(self, id_client, id_film):
        # verifica daca exista vreun client cu id-ul id_client si vreun film cu id-ul id_film
        client = self.__client_repo.searchClientById(id_client)
        film = self.__film_repo.searchFilmById(id_film)
        self.deleteInchiriere(id_client, id_film)
        film.increase_nr_filme_disponibile()
        self.__film_repo.updateFilm(film)

    def numarFilmeInchiriate(self, id_client):
        """
            Returneaza numarul de filme inchiriate la momentul actual al unui client cu id-ul = id_client.
        """
        inchirieri = self.__inchiriere_repo.getInchirieri()
        numarFilmeInchiriate = 0
        for inchiriere in inchirieri:
            if inchiriere.getId_client() == id_client:
                numarFilmeInchiriate = numarFilmeInchiriate + 1
        return numarFilmeInchiriate

    def getClientsOrdonatiDupaFilmeInchiriate(self):
        """
            Ordoneaza clientii in functie de numarul de filme inchiriate.
        """
        clients = self.__client_repo.getClients()
        clients.sort(key=lambda x: self.numarFilmeInchiriate(x.getId_client()), reverse=True)
        return clients

    ##########################
    # A.Implementare QUICK SORT
    def partition(self, the_list, left, right, key=lambda x: x):
        """
            Realizeaza partitiile.
            Returneaza pozitia pivotului.
        """
        pivot = the_list[left]
        i = left
        j = right
        while i != j:
            while key(the_list[j]) <= key(pivot) and i < j:
                j = j - 1
            the_list[i] = the_list[j]
            while key(the_list[i]) >= key(pivot) and i < j:
                i = i + 1
            the_list[j] = the_list[i]
        the_list[i] = pivot
        return i

    def quickSort(self, the_list, left, right, key=lambda x: x):
        """
            QUICK SORT.
        """
        pos = self.partition(the_list, left, right, key)
        if left < pos - 1:
            self.quickSort(the_list, left, pos - 1, key)
        if pos + 1 < right:
            self.quickSort(the_list, pos + 1, right, key)

    ##########################

    def numarClientiPeFilm(self, id_film):
        """
            Returneaza numarul de clienti pe care il are la momentul actual un film cu un id-ul = id_film
        """
        inchirieri = self.__inchiriere_repo.getInchirieri()
        numarClienti = 0
        for inchiriere in inchirieri:
            if inchiriere.getId_film() == id_film:
                numarClienti = numarClienti + 1
        return numarClienti

    def getFilmeCeleMaiInchiriate(self):
        """
            Returneaza lista de filme in functie de cele mai inchiriate filme.
        """
        films = self.__film_repo.getFilms()
        films.sort(key=lambda x: self.numarClientiPeFilm(x.getId_film()), reverse=True)
        return films

    ##########################
    # B.Implementare GNOME SORT (also called Stupid Sort)
    def gnomeSort(self, the_list, n , key = lambda x:x):
        """
            GNOME SORT.
        """
        index = 0
        while index < n:
            if index == 0:
                index = index + 1
            if key(the_list[index]) <= key(the_list[index - 1]):
                index = index + 1
            else:
                the_list[index], the_list[index - 1] = the_list[index - 1], the_list[index]
                index = index - 1
        return the_list

    ##########################

    def nrFilmeInchiriate(self, films):
        """
            Returneaza numarul de filme inchiriate la momentul actual.
        """
        nrFilmeInchiriate = 0
        for film in films:
            if self.numarClientiPeFilm(film.getId_film()) != 0:
                nrFilmeInchiriate = nrFilmeInchiriate + 1
        return nrFilmeInchiriate

    def nrClientiCuFilmeInchiriate(self, clients):
        """
            Returneaza numarul de clienti cu filme inchiriate la momentul actual.
        """
        nrClienti = 0
        inchirieri = self.__inchiriere_repo.getInchirieri()
        for client in clients:
            ok = 0
            for inchiriere in inchirieri:
                if inchiriere.getId_client() == client.getId_client() and ok == 0:
                    nrClienti = nrClienti + 1
                    ok = 1
        return nrClienti
