from unittest import TestCase
from Inchiriere_filme.exceptions.exceptions import *
from Inchiriere_filme.domain.entities import Client
from Inchiriere_filme.repository.client_repo import *

class TestClientRepository(TestCase):
    def setUp(self) -> None:
        self.__repo = ClientRepository()

    def test_add_client(self):
        client1 = Client(12, 'Radu', 6220101018690)
        client2 = Client(43, 'Stefan', 6220101018692)
        self.__repo.addClient(client1)
        self.assertEqual(len(self.__repo.getClients()), 1)
        self.__repo.addClient(client2)
        self.assertEqual(len(self.__repo.getClients()), 2)

        client1 = Client(12, 'Radu', 6220101018690)
        self.assertRaises(RepoException, self.__repo.addClient, client1)

    def test_get_clients(self):
        client = Client(3, 'Grigorescu', 6220101015935)
        self.__repo.addClient(client)

        clients = self.__repo.getClients()
        self.assertIsInstance(clients, list)
        self.assertEqual(len(clients), 1)
        self.assertEqual(clients[0], client)

    def test_search_client_by_id(self):
        client1 = Client(12, 'Radu', 6220101018690)
        client2 = Client(43, 'Stefan', 6220101018692)
        client3 = Client(35, 'Sofronel', 6220101018697)
        self.__repo.addClient(client2)
        self.__repo.addClient(client1)
        self.__repo.addClient(client3)

        cl = self.__repo.searchClientById(35)
        self.assertEqual(cl.getNume(), 'Sofronel')
        self.assertEqual(cl.getCnp(), 6220101018697)

        self.assertRaises(RepoException, self.__repo.searchClientById, 1234)

    def test_delete_client(self):
        client1 = Client(12, 'Radu', 6220101018690)
        client2 = Client(43, 'Stefan', 6220101018692)
        client3 = Client(35, 'Sofronel', 6220101018697)
        self.__repo.addClient(client2)
        self.__repo.addClient(client1)
        self.__repo.addClient(client3)

        self.__repo.deleteClient(35)
        self.assertEqual(len(self.__repo.getClients()), 2)
        self.assertRaises(RepoException, self.__repo.deleteClient, 324)

    def test_update_client(self):
        client1 = Client(12, 'Veronica', 6220101018690)
        client2 = Client(43, 'Simona', 6220101018692)
        client3 = Client(35, 'Sofronel', 6220101018697)
        self.__repo.addClient(client1)
        self.__repo.addClient(client2)
        self.__repo.addClient(client3)

        newClient = Client(43, 'Corina', 6320101018692)
        fakeClient = Client(2321, 'Rorc', 6320101018692)
        self.__repo.updateClient(newClient)
        clients = self.__repo.getClients()
        self.assertEqual(clients[1], newClient)
        self.assertRaises(RepoException, self.__repo.updateClient, fakeClient)


class TestClientRepoFile(TestCase):
    def setUp(self) -> None:
        self.__repo = ClientRepoFile("test_clienti.txt")

    def test_search_client_by_id(self):
        newClient = Client(12,'Carmen',6211215017739)
        self.__repo.addClient(newClient)

        client = self.__repo.searchClientById(12)
        self.assertEqual(client.getNume(),'Carmen')
        self.assertEqual(client.getCnp(),6211215017739)
        self.assertRaises(RepoException,self.__repo.searchClientById,34134)
        self.__repo.deleteClient(12)

    def test_add_client(self):
        newClient = Client(53, 'Zorel', 6220102016673)
        fakeClient = Client(53, 'Anastasia', 6220102016673)

        self.__repo.addClient(newClient)
        clients = self.__repo.getClients()
        self.assertEqual(len(clients),1)
        self.assertEqual(clients[0],newClient)
        self.assertRaises(RepoException,self.__repo.addClient,fakeClient)
        self.__repo.deleteClient(53)

    def test_update_client(self):
        clientul = Client(53, 'Zorel', 6220102016673)
        newClient = Client(53, 'Zorro', 6222102016673)
        fakeClient = Client(31, 'Anastasia', 622010201667)
        self.__repo.addClient(clientul)

        self.__repo.updateClient(newClient)
        clients = self.__repo.getClients()
        self.assertEqual(clients[0],newClient)
        self.assertRaises(RepoException, self.__repo.updateClient,fakeClient)
        self.__repo.deleteClient(53)

    def test_delete_client(self):
        client1 = Client(11,'Anastastia',622010201667)
        client2 = Client(67,'Santiago',622010201669)
        self.__repo.addClient(client1)
        self.__repo.addClient(client2)

        self.assertEqual(len(self.__repo.getClients()),2)
        self.__repo.deleteClient(11)
        self.assertEqual(len(self.__repo.getClients()), 1)
        self.__repo.deleteClient(67)
        self.assertEqual(len(self.__repo.getClients()), 0)
        self.assertRaises(RepoException,self.__repo.deleteClient,2143)

    def test_get_clients(self):
        client = Client(654, 'Sev', 622010201669)
        self.__repo.addClient(client)

        clients = self.__repo.getClients()
        self.assertEqual(len(clients),1)
        self.assertEqual(clients[0],client)
        self.assertIsInstance(clients,list)
        self.__repo.deleteClient(654)
