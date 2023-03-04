from Inchiriere_filme.repository.client_repo import *
from Inchiriere_filme.validators.validators import *
from Inchiriere_filme.exceptions.exceptions import ServiceException

class ClientService:
    def __init__(self, client_repo: ClientRepository, client_validator: ClientValidator):
        self.__client_repo = client_repo
        self.__client_validator = client_validator

    def getClients(self):
        return self.__client_repo.getClients()

    def getClientsOrdonatiDupaNume(self):
        clients = self.getClients()
        clients.sort(key=lambda x: x.getNume())
        return clients

    def addClient(self, id_client, nume, cnp):
        newClient = Client(id_client, nume, cnp)
        try:
            self.__client_validator.validate(newClient)
            try:
                self.__client_repo.addClient(newClient)
            except RepoException as ex:
                raise ServiceException(ex)
        except ValidatorException as ex:
            raise ServiceException(ex)

    def deleteClient(self, id_client):
        try:
            self.__client_repo.deleteClient(id_client)
        except RepoException as ex:
            raise ServiceException(ex)

    def updateClient(self, id_client, nume, cnp):
        newClient = Client(id_client, nume, cnp)
        try:
            self.__client_validator.validate(newClient)
            try:
                self.__client_repo.updateClient(newClient)
            except RepoException as ex:
                raise ServiceException(ex)
        except ValidatorException as ex:
            raise ServiceException(ex)

    def filterByName(self, part_of_name):
        """
            Selecteaza filmele care contin part_of_title in titlu
        """
        all_clients = self.getClients()
        filtered_list = []
        for client in all_clients:
            if part_of_name in client.getNume():
                filtered_list.append(client)
        return filtered_list

    def searchClientById(self,id_client):
        return self.__client_repo.searchClientById(id_client)