from Inchiriere_filme.service.film_service import *
from Inchiriere_filme.service.client_service import *
from Inchiriere_filme.service.inchiriere_service import *
from Inchiriere_filme.service.film_generator import *
from Inchiriere_filme.service.client_generator import *
from datetime import date
import math

class Console:
    def __init__(self, film_service: FilmService, client_service: ClientService, inchiriere_service: InchiriereService,
                 film_generator: FilmGenerator, client_generator: ClientGenerator):
        self.__film_service = film_service
        self.__client_service = client_service
        self.__inchiriere_service = inchiriere_service
        self.__film_generator = film_generator
        self.__client_generator = client_generator

    def add_film_to_list(self):
        """
            Adauga un film la lista de filme.
        """
        id_film = input("Id-ul filmului este: ")
        titlu = input("Titlul filmului este: ")
        descriere = input("Descrierea filmului este: ")
        gen = input("Genul filmului este: ")
        nr_filme_disponibile = input("Numarul de filme disponibile este: ")
        id_film = int(id_film)
        nr_filme_disponibile = int(nr_filme_disponibile)
        self.__film_service.addFilm(id_film, titlu, descriere, gen, nr_filme_disponibile)

    def print_films_list(self):
        """
            Afiseaza lista de filme curente.
        """
        films = self.__film_service.getFilms()
        if len(films) == 0:
            print("Nu exista filme in lista!")
        else:
            for film in films:
                print(film)

    def delete_film(self):
        """
            Sterge un film.
        """
        id_film = input("Id-ul filmului este:")
        id_film = int(id_film)
        self.__film_service.deleteFilm(id_film)

    def update_film(self):
        """
            Modifica un film.
        """
        id_film = input("Id-ul filmului este: ")
        titlu = input("Titlul filmului este: ")
        descriere = input("Descrierea filmului este: ")
        gen = input("Genul filmului este: ")
        nr_filme_disponibile = input("Numarul de filme disponibile este: ")
        id_film = int(id_film)
        nr_filme_disponibile = int(nr_filme_disponibile)
        self.__film_service.updateFilm(id_film, titlu, descriere, gen, nr_filme_disponibile)

    def add_client_to_list(self):
        """
            Adauga un client la lista de clienti.
        """
        id_client = input("Id-ul clientului este: ")
        nume = input("Numele clientului este: ")
        cnp = input("CNP-ul clientului este: ")
        id_client = int(id_client)
        cnp = int(cnp)
        self.__client_service.addClient(id_client, nume, cnp)

    def print_clients_list(self):
        """
            Afiseaza lista de clienti curenta.
        """
        clients = self.__client_service.getClients()
        if len(clients) == 0:
            print("Nu exista clienti in lista!")
        else:
            for client in clients:
                print(client)

    def delete_client(self):
        """
            Sterge un client.
        """
        id_client = input("Id-ul clientului este:")
        id_client = int(id_client)
        self.__client_service.deleteClient(id_client)

    def update_client(self):
        """
            Modifica un client.
        """
        id_client = input("Id-ul clientului este: ")
        nume = input("Numele clientului este: ")
        cnp = input("CNP-ul clientului este: ")
        id_client = int(id_client)
        cnp = int(cnp)
        self.__client_service.updateClient(id_client, nume, cnp)

    def filter_films_by_title(self):
        """
            Afiseaza toate filmele care contin cuvantul cheie introdus de la tastatura.
        """
        part_of_title = input("Introduceti cuvantul cheie din titlu: ")
        filtered_list = self.__film_service.filterByTitle(part_of_title)
        if len(filtered_list) == 0:
            print("Nu exista astfel de filme.")
        else:
            for film in filtered_list:
                print(film)

    def filter_clients_by_name(self):
        """
            Afiseaza toti clientii care contin cuvantul cheie introdus de la tastatura.
        """
        part_of_name = input("Introduceti cuvantul cheie din nume: ")
        filtered_list = self.__client_service.filterByName(part_of_name)
        if len(filtered_list) == 0:
            print("Nu exista clienti cu astfel de nume.")
        else:
            for client in filtered_list:
                print(client)

    def inchiriaza_film(self):
        """
            Se creeaza o noua inchiriere de la tastatura in functie de id-ul clientului si id-ul filmului dat.
        """
        id_client = input("Id-ul clientului este: ")
        id_film = input("Id-ul filmului este: ")
        data = date.today()
        try:
            id_client = int(id_client)
            id_film = int(id_film)
            try:
                self.__inchiriere_service.inchiriazaFilm(id_client, id_film, data)
            except ServiceException as ex:
                print(ex)
        except ValueError:
            print("Id-urile filmului si al clientului trebuie sa fie integer!")

    def returneaza_film(self):
        """
            Se sterge o inchiriere de la tastatura in functie de id-ul clientului si id-ul filmului dat.
        """
        id_client = input("Id-ul clientului este: ")
        id_film = input("Id-ul filmului este: ")
        id_client = int(id_client)
        id_film = int(id_film)
        try:
            self.__inchiriere_service.returneazaFilm(id_client, id_film)
        except ServiceException as ex:
            print(ex)

    def print_inchirieri(self):
        """
            Se afiseaza lista curenta de inchirieri.
        """
        inchirieri = self.__inchiriere_service.getInchirieri()
        if len(inchirieri) == 0:
            print("Nu exista inchirieri in lista!")
        else:
            for inchiriere in inchirieri:
                print(inchiriere)

    def generare_film(self):
        """
            Se genereaza un film random.
        """
        id_film = self.__film_generator.generateRandomID()
        titlu = self.__film_generator.generateRandomString()
        descriere = self.__film_generator.generateRandomString(20)
        gen = self.__film_generator.generateRandomString()
        nr_filme_disponibile = self.__film_generator.generateRandomNr_filme(2)
        try:
            id_film = int(id_film)
            nr_filme_disponibile = int(nr_filme_disponibile)
            try:
                self.__film_service.addFilm(id_film, titlu, descriere, gen, nr_filme_disponibile)
            except ServiceException as ex:
                pass
        except ValueError:
            pass


    def generare_client(self):
        """
            Se genereaza un client random.
        """
        id_client = self.__client_generator.generateRandomID()
        nume = self.__client_generator.generateRandomName()
        cnp = self.__client_generator.generateRandomCNP()
        try:
            id_client = int(id_client)
            cnp = int(cnp)
            try:
                self.__client_service.addClient(id_client, nume, cnp)
            except ServiceException as ex:
                pass
        except ValueError:
            pass

    def ordonareNumeClient(self):
        """
            Se afiseaza lista cu clientii cu filme inchiriate in functie de numele acestora, alfabetic.
        """
        clients = self.__client_service.getClientsOrdonatiDupaNume()
        for client in clients:
            if self.__inchiriere_service.numarFilmeInchiriate(client.getId_client()) != 0:
                print('Nume client: ' + client.getNume() + ', Numar filme inchiriate: ' + str(
                    self.__inchiriere_service.numarFilmeInchiriate(client.getId_client())))

    def ordonareNumarFilmeInchiriate(self):
        """
            Se afiseaza lista cu clientii cu filme inchiriate in functie de numarul de filme
            inchiriate, de la cel cu cele mai multe filme inchiriate la cel cu cele mai putine.
        """
        clients = self.__client_service.getClients()
        self.__inchiriere_service.quickSort(clients,0,len(clients)-1,lambda x:self.__inchiriere_service.numarFilmeInchiriate(x.getId_client()))
        for client in clients:
            if self.__inchiriere_service.numarFilmeInchiriate(client.getId_client()) != 0:
                print('Nume client: ' + client.getNume() + ', Numar filme inchiriate: ' + str(
                    self.__inchiriere_service.numarFilmeInchiriate(client.getId_client())))

    def celeMaiInchiriateFilme(self):
        """
            Se afiseaza cele mai inchiriate filme.
        """
        films = self.__film_service.getFilms()
        films = self.__inchiriere_service.gnomeSort(films, len(films), lambda x:self.__inchiriere_service.numarClientiPeFilm(x.getId_film()))
        if len(films) == 0:
            print("Nu exista filme inchiriate!")
        else:
            nrMaxClienti = self.__inchiriere_service.numarClientiPeFilm(films[0].getId_film())
            if nrMaxClienti == 0:
                print("Nu exista filme inchiriate!")
            else:
                for film in films:
                    if self.__inchiriere_service.numarClientiPeFilm(film.getId_film()) == nrMaxClienti:
                        print('Titlu film: ' + film.getTitlu() + ', Numar clienti: ' + str(nrMaxClienti))

    def primii30Clienti(self):
        """
            Se afiseaza lista cu primii 30% clientii cu filme inchiriate in functie de numarul de filme
        inchiriate, de la cel cu cele mai multe filme inchiriate la cel cu cele mai putine.

        ANALIZA COMPLEXITATII FUNCTIEI "primii30Clienti"
         Cazuri favorabile:
          - nu exista clienti in lista
          - nu exista clienti cu filme inchiriate in lista
          - exista un singur client cu un film inchiriat in lista
        => T(n) ∈ θ(1)
         Caz defavorabil:
          - lista contine un numar mare de clienti cu filme inchiriate
        => T(n) = n/3  ∈ θ(n)
         Caz mediu:
          - alterneaza cazurile favorabile si cazurile defavorabile, neavand certitudinea numarului de
          clienti cu filme inchiriate, avand aceasi probabilitate in functie de lungimea listei de clienti
          cu filme inchiriate
        => T(n) = (1 + 2 + 3 + ... + n)/(n * 3) = n(n + 1)/(2 * 3 * n) = (n + 1)/6
           T(n) ∈ O(n)

        Complexitate (Overall complexity) = O(n)

        """
        clients = self.__inchiriere_service.getClientsOrdonatiDupaFilmeInchiriate()
        if len(clients) == 0:
            print("Nu exista clienti!")
        else:
            if self.__inchiriere_service.nrClientiCuFilmeInchiriate(clients) == 0:
                print("Nu exista clienti cu filme inchiriate!")
            else:
                index = math.ceil(self.__inchiriere_service.nrClientiCuFilmeInchiriate(clients) * 0.3)
                for client in clients:
                    if index > 0:
                        print('Nume client: ' + client.getNume() + ', Numar filme inchiriate: ' + str(
                            self.__inchiriere_service.numarFilmeInchiriate(client.getId_client())))
                        index = index - 1

    def top3filme(self):
        """
            Se afiseaza top 3 cele mai inchiriate filme.

        ANALIZA COMPLEXITATII FUNCTIEI "top3filme"
         Cazuri favorabile:
          - nu exista filme in lista
          - nu exista minim 3 filme inchiriate in lista
        => T(n) ∈ θ(1)
         Caz defavorabil:
          - lista contine minim 3 filme inchiriate => se parcurge toata lista de filme
        => T(n) = n ∈ θ(n)
         Caz mediu:
          - alterneaza cazurile favorabile si cazurile defavorabile, neavand certitudinea numarului de filme
          inchiriate, avand aceasi probabilitate
          numarul de pasi = numarul mediu de iteratii
           => T(n) = (1 + 2 + 3 + ... + n)/n = n(n + 1)/(2 * n) = (n + 1)/2
              T(n)∈ O(n)

        Complexitate (Overall complexity) = O(n)

        """
        films = self.__inchiriere_service.getFilmeCeleMaiInchiriate()
        if len(films) == 0:
            print("Nu exista filme inchiriate!")
        else:
            if self.__inchiriere_service.nrFilmeInchiriate(films) < 3:
                print("Nu exista top 3 filme!")
            else:
                index = 3
                for film in films:
                    if index > 0:
                        print('Titlu film: ' + film.getTitlu() + ', Numar clienti: ' + str(self.__inchiriere_service.numarClientiPeFilm(film.getId_film())))
                        index = index - 1

    def menu(self):
        """
            Meniul aplicatiei.
        """
        print(
            "------------------------------------------------------------------------------------------------------------------")
        print("0. Iesirea din aplicatie. ")
        print("1. Adauga un film la lista de filme. ")
        print("2. Afiseaza lista de filme curenta. ")
        print("3. Sterge un film. ")
        print("4. Modifica un film. ")
        print("5. Adauga un client la lista de clienti. ")
        print("6. Afiseaza lista de clienti curenta. ")
        print("7. Sterge un client. ")
        print("8. Modifica un client. ")
        print("9. Cauta filme dupa titlu. ")
        print("10. Cauta client dupa nume. ")
        print("11. Inchiriaza film. ")
        print("12. Returneaza film. ")
        print("13. Afiseaza lista de inchirieri. ")
        print("14. Genereaza un film random. ")
        print("15. Genereaza un client random. ")
        print("16. Lista de clienți cu numarul de filme închiriate ordonata dupa nume. ")
        print("17. Lista de clienți cu numarul de filme închiriate ordonata dupa numarul de filme închiriate. ")
        print("18. Cele mai inchiriate filme.")
        print("19. Primi 30% clienti cu cele mai multe filme inchiriate. ")
        print("20. Top 3 filme inchiriate.")
        print(
            "------------------------------------------------------------------------------------------------------------------")


    def run(self):
        self.menu()
        dictionary_of_commands = {
            "1": self.add_film_to_list,
            "2": self.print_films_list,
            "3": self.delete_film,
            "4": self.update_film,
            "5": self.add_client_to_list,
            "6": self.print_clients_list,
            "7": self.delete_client,
            "8": self.update_client,
            "9": self.filter_films_by_title,
            "10": self.filter_clients_by_name,
            "11": self.inchiriaza_film,
            "12": self.returneaza_film,
            "13": self.print_inchirieri,
            "14": self.generare_film,
            "15": self.generare_client,
            "16": self.ordonareNumeClient,
            "17": self.ordonareNumarFilmeInchiriate,
            "18": self.celeMaiInchiriateFilme,
            "19": self.primii30Clienti,
            "20": self.top3filme
        }
        while True:
            command = input("Introduceti optiunea dorita: ")
            if command in dictionary_of_commands:
                try:
                    dictionary_of_commands[command]()
                except ServiceException as ex:
                    print(ex)
                except ValidatorException as ex:
                    print(ex)
                except RepoException as ex:
                    print(ex)
                except ValueError:
                    print("Valoarea introdusa trebuie sa fie de tip integer!")
                self.menu()
            elif command == "0":
                break
            else:
                print("Optiunea aleasa nu exista!")
