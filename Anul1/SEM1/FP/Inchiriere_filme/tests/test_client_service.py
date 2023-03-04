from unittest import TestCase
from Inchiriere_filme.domain.entities import *
from Inchiriere_filme.repository.client_repo import *
from Inchiriere_filme.service.client_service import *

class TestClientService(TestCase):
    def setUp(self) -> None:
        repo = ClientRepository()
        vali = ClientValidator()
        self.__client_service = ClientService(repo,vali)

    def test_get_clients(self):
        self.__client_service.addClient(12,'Florin',6220101015992)
        clients = self.__client_service.getClients()
        self.assertEqual(len(clients),1)
        self.assertIsInstance(clients,list)
        clientul = Client(12,'Florin',6220101015992)
        self.assertEqual(clients[0],clientul)

    def test_get_clients_ordonati_dupa_nume(self):
        self.__client_service.addClient(4, 'Florian', 6220101015993)
        self.__client_service.addClient(1, 'Alexandra', 6220101015994)
        self.__client_service.addClient(3, 'Cristina', 6220101015995)
        self.__client_service.addClient(2, 'Grigore', 6220101015994)
        clients = self.__client_service.getClientsOrdonatiDupaNume()
        self.assertEqual(clients[0].getNume(),'Alexandra')
        self.assertEqual(clients[1].getNume(),'Cristina')
        self.assertEqual(clients[2].getNume(),'Florian')
        self.assertEqual(clients[3].getNume(),'Grigore')

    def test_add_client(self):
        self.__client_service.addClient(2,'Grigore',6220101015994)
        self.assertEqual(len(self.__client_service.getClients()), 1)
        self.__client_service.addClient(1,'Alexandra',6220101015994)
        self.assertEqual(len(self.__client_service.getClients()), 2)

        self.assertRaises(ServiceException,self.__client_service.addClient,3,'',6220101015993)
        self.assertRaises(ServiceException, self.__client_service.addClient, 1, 'Elena', 6220101015993)
        self.assertRaises(ServiceException, self.__client_service.addClient, 5, 'Cosmina', 63)

    def test_delete_client(self):
        self.__client_service.addClient(4,'Florian',6220101015993)
        self.__client_service.addClient(1, 'Alexandra', 6220101015994)
        self.__client_service.addClient(3,'Anastasia',6220101015995)
        self.__client_service.addClient(2, 'Grigore', 6220101015994)

        self.__client_service.deleteClient(3)
        self.assertEqual(len(self.__client_service.getClients()),3)
        self.__client_service.deleteClient(4)
        self.assertEqual(len(self.__client_service.getClients()),2)
        self.assertRaises(ServiceException,self.__client_service.deleteClient,7)

    def test_update_client(self):
        self.__client_service.addClient(4, 'Florian', 6220101015993)
        self.__client_service.addClient(1, 'Alexandra', 6220101015994)
        self.__client_service.addClient(3, 'Anastasia', 6220101015995)

        self.__client_service.updateClient(1,'Puiu Coco Rico',6220101015995)
        clients = self.__client_service.getClients()
        clientul = Client(1,'Puiu Coco Rico',6220101015995)
        self.assertEqual(clients[1], clientul)
        self.assertRaises(ServiceException,self.__client_service.updateClient,9,'Puiu Coco Rico',6220101015995)
        self.assertRaises(ServiceException, self.__client_service.updateClient, 1, '', 6220101015995)
        self.assertRaises(ServiceException, self.__client_service.updateClient, 2, 'Coco', 625)

    def test_filter_by_name(self):
        self.__client_service.addClient(54, 'Florian', 6220101015993)
        self.__client_service.addClient(12, 'Alexandra', 6220101015994)
        self.__client_service.addClient(36, 'Florentina', 6220101015995)
        self.__client_service.addClient(45,'Anamaria',6220101015990)

        filtered = self.__client_service.filterByName('Flo')
        self.assertEqual(filtered[0].getNume(),'Florian')
        self.assertEqual(filtered[1].getNume(),'Florentina')
        self.assertEqual(len(filtered),2)
        filtered = self.__client_service.filterByName('Cd')
        self.assertEqual(filtered,[])

    def test_search_client_by_id(self):
        self.__client_service.addClient(54, 'Florian', 6220101015993)
        self.__client_service.addClient(12, 'Alexandra', 6220101015994)
        self.__client_service.addClient(36, 'Anastasia', 6220101015995)

        cl = self.__client_service.searchClientById(12)
        self.assertEqual(cl.getNume(),'Alexandra')
        self.assertEqual(cl.getCnp(),6220101015994)
        self.assertRaises(RepoException, self.__client_service.searchClientById,32)
