from Inchiriere_filme.exceptions.exceptions import *
from Inchiriere_filme.domain.entities import Client

class ClientRepository:
    def __init__(self):
        self.__clients = []

    def getClients(self):
        return self.__clients

    def addClient(self, client):
        """
            Adauga client in lista de clienti, daca id-ul clientului dorit spre adaugare exista, se ridica exceptie
        """
        if client in self.__clients:
            raise RepoException("Id-ul clientului este deja in lista!")
        self.__clients.append(client)

    def searchClientById(self, id_client) -> Client:
        """
            Cauta in lista clientul avand id-ul = id_client
            Returneaza * clientul, daca acesta exista in lista
                       * ridica exceptie, in caz contrar
        """
        for client in self.__clients:
            if client.getId_client() == id_client:
                return client
        raise RepoException("Id-ul clientului nu exista!")

    def deleteClient(self, id_client):
        """
            Sterge clientul in functie de id = id_client
        """
        for i in range(len(self.__clients)):
            if self.__clients[i].getId_client() == id_client:
                self.__clients.pop(i)
                return
        raise RepoException("Delete error: Nu exista clientul cu id-ul dat!")

    def updateClient(self, newClient):
        """
            Modifica clientul avand id-ul egal id-ul clientului newClient, setandu-i campurile cu noile date.
        """
        for i in range(len(self.__clients)):
            if self.__clients[i].getId_client() == newClient.getId_client():
                self.__clients[i] = newClient
                return
        raise RepoException("Update error: Nu exista clientul cu id-ul dat!")


class ClientRepoFile:
    def __init__(self, fileName):
        self.__fileName = fileName

    def __load_from_file(self):
        try:
            f = open(self.__fileName,'r')
        except IOError:
            raise CorruptedFileException("File Error: Nu exista fisierul cu numele dat!")

        clients = []
        lines = f.readlines()
        for line in lines:
            id_client, nume, cnp = [token.strip() for token in line.split(',')]
            client = Client(int(id_client), nume, int(cnp))
            clients.append(client)

        f.close()
        return clients

    def __save_to_file(self, clients):
        with open(self.__fileName,'w') as f:
            for client in clients:
                client_string = str(client.getId_client()) + ',' + str(client.getNume()) + ',' + str(client.getCnp()) + '\n'
                f.write(client_string)

    def searchClientById(self, id_client):
        """
            Cauta in lista clientul avand id-ul = id_client
            Returneaza * clientul, daca acesta exista in lista
                       * ridica exceptie, in caz contrar
        """
        all_clients = self.__load_from_file()
        for client in all_clients:
            if client.getId_client() == id_client:
                return client
        raise RepoException("Id-ul clientului nu exista!")

    def addClient(self, client):
        """
            Adauga client in lista de clienti, daca id-ul clientului dorit spre adaugare exista, se ridica exceptie
        """
        all_clients = self.__load_from_file()
        if client in all_clients:
            raise RepoException("Id-ul clientului este deja in lista!")
        all_clients.append(client)
        self.__save_to_file(all_clients)

    def updateClient(self, newClient):
        """
            Modifica clientul avand id-ul egal id-ul clientului newClient, setandu-i campurile cu noile date.
        """
        all_clients = self.__load_from_file()
        for i in range(len(all_clients)):
            if all_clients[i].getId_client() == newClient.getId_client():
                all_clients[i] = newClient
                self.__save_to_file(all_clients)
                return
        raise RepoException("Update Error: Nu exista clientul cu id-ul dat!")

    def deleteClient(self, id_client):
        """
            Sterge clientul in functie de id = id_client
        """
        all_clients = self.__load_from_file()
        for i in range(len(all_clients)):
            if all_clients[i].getId_client() == id_client:
                all_clients.pop(i)
                self.__save_to_file(all_clients)
                return
        raise RepoException("Delete Error: Nu exista clientul cu id-ul dat!")

    def getClients(self):
        return self.__load_from_file()