from unittest import TestCase
from Inchiriere_filme.domain.entities import *
from Inchiriere_filme.repository.inchiriere_repo import *
from Inchiriere_filme.service.inchiriere_service import *
from Inchiriere_filme.service.film_service import *
from Inchiriere_filme.service.client_service import *

class TestInchiriereService(TestCase):
    def setUp(self) -> None:
        repo = InchiriereRepository()
        vali = InchiriereValidator()
        film_repo = FilmRepository()
        film_vali = FilmValidator()
        client_repo = ClientRepository()
        client_vali = ClientValidator()
        self.__inchiriere_service = InchiriereService(repo,vali,film_repo,film_vali,client_repo,client_vali)
        self.__client_service = ClientService(client_repo,client_vali)
        self.__film_service = FilmService(film_repo,film_vali)

    def test_get_inchirieri(self):
        self.__inchiriere_service.addInchiriere(2,4,'2021-12-30')
        inchirieri = self.__inchiriere_service.getInchirieri()
        self.assertEqual(len(inchirieri),1)
        self.assertIsInstance(inchirieri, list)
        inchirierea = Inchiriere(2,4,'2021-12-30')
        self.assertEqual(inchirieri[0],inchirierea)

    def test_add_inchiriere(self):
        self.__inchiriere_service.addInchiriere(2, 4, '2021-12-30')
        self.assertEqual(len(self.__inchiriere_service.getInchirieri()),1)
        self.__inchiriere_service.addInchiriere(3, 6, '2021-12-11')
        self.assertEqual(len(self.__inchiriere_service.getInchirieri()), 2)

        self.assertRaises(ServiceException, self.__inchiriere_service.addInchiriere, 2, 4, '2021-12-13')
        self.assertRaises(ServiceException, self.__inchiriere_service.addInchiriere, -1, 4, '2021-12-13')
        self.assertRaises(ServiceException, self.__inchiriere_service.addInchiriere, 2, -4, '2021-12-13')

    def test_delete_inchiriere(self):
        self.__inchiriere_service.addInchiriere(1, 4, '2021-12-30')
        self.__inchiriere_service.addInchiriere(2, 3, '2021-12-11')
        self.__inchiriere_service.addInchiriere(7, 23, '2021-12-10')
        self.__inchiriere_service.addInchiriere(22, 15, '2021-12-05')

        self.__inchiriere_service.deleteInchiriere(2,3)
        self.assertEqual(len(self.__inchiriere_service.getInchirieri()),3)
        self.__inchiriere_service.deleteInchiriere(22,15)
        self.assertEqual(len(self.__inchiriere_service.getInchirieri()),2)
        self.assertRaises(ServiceException,self.__inchiriere_service.deleteInchiriere,12,23)

    def test_search_inchiriere_by_id(self):
        self.__inchiriere_service.addInchiriere(1, 4, '2021-12-30')
        self.__inchiriere_service.addInchiriere(2, 3, '2021-12-11')
        self.__inchiriere_service.addInchiriere(7, 23, '2021-12-10')
        self.__inchiriere_service.addInchiriere(22, 15, '2021-12-05')

        inchirierea = self.__inchiriere_service.searchInchiriereById(23,7)
        self.assertEqual(inchirierea.getData_inchirierii(),'2021-12-10')
        self.assertRaises(RepoException,self.__inchiriere_service.searchInchiriereById,133,314)

    def test_inchiriaza_film(self):
        self.__client_service.addClient(1,'Grigore',6220102018490)
        self.__film_service.addFilm(4,'Spiderman','skjddsbjfb','action',7)
        self.__client_service.addClient(2,'Constantin',6220102018490)
        self.__film_service.addFilm(6, 'Spiderman 2', 'skjddsbjfb', 'action', 1)

        self.__inchiriere_service.inchiriazaFilm(2,6,'2021-12-30')
        self.__inchiriere_service.inchiriazaFilm(1,4,'2021-12-30')
        self.assertEqual(len(self.__inchiriere_service.getInchirieri()),2)
        self.assertRaises(ServiceException,self.__inchiriere_service.inchiriazaFilm,2,6,'2021-12-30')
        self.assertRaises(ServiceException,self.__inchiriere_service.inchiriazaFilm,1,4,'2021-12-30')

    def test_returneaza_film(self):
        self.__client_service.addClient(1, 'Grigore', 6220102018490)
        self.__film_service.addFilm(4, 'Spiderman', 'skjddsbjfb', 'action', 7)
        self.__client_service.addClient(2, 'Constantin', 6220102018490)
        self.__film_service.addFilm(6, 'Spiderman 2', 'skjddsbjfb', 'action', 1)
        self.__inchiriere_service.inchiriazaFilm(2, 6, '2021-12-30')
        self.__inchiriere_service.inchiriazaFilm(1, 4, '2021-12-30')

        self.__inchiriere_service.returneazaFilm(1,4)
        self.assertEqual(len(self.__inchiriere_service.getInchirieri()),1)
        self.__inchiriere_service.returneazaFilm(2,6)
        self.assertEqual(len(self.__inchiriere_service.getInchirieri()),0)
        self.assertRaises(RepoException, self.__inchiriere_service.returneazaFilm, 4, 6)
        self.assertRaises(RepoException, self.__inchiriere_service.returneazaFilm, 3, 6)

    def test_numar_filme_inchiriate(self):
        self.__client_service.addClient(1, 'Grigore', 6220102018490)
        self.__film_service.addFilm(4, 'Spiderman', 'skjddsbjfb', 'action', 7)
        self.__client_service.addClient(2, 'Constantin', 6220102018490)
        self.__film_service.addFilm(6, 'Spiderman 2', 'skjddsbjfb', 'action', 1)
        self.__inchiriere_service.inchiriazaFilm(1, 4, '2021-12-30')

        self.assertEqual(self.__inchiriere_service.numarFilmeInchiriate(2),0)
        self.assertEqual(self.__inchiriere_service.numarFilmeInchiriate(1), 1)
        self.__inchiriere_service.inchiriazaFilm(1, 6, '2021-12-30')
        self.assertEqual(self.__inchiriere_service.numarFilmeInchiriate(1), 2)

    def test_get_clients_ordonati_dupa_filme_inchiriate(self):
        self.__client_service.addClient(1, 'Grigore', 6220102018490)
        self.__film_service.addFilm(4, 'Spiderman', 'skjddsbjfb', 'action', 7)
        self.__client_service.addClient(2, 'Constantin', 6220102018490)
        self.__film_service.addFilm(6, 'Spiderman 2', 'skjddsbjfb', 'action', 1)
        self.__client_service.addClient(3, 'Florentina', 6220102018490)
        self.__inchiriere_service.inchiriazaFilm(3, 4, '2021-12-30')
        self.__inchiriere_service.inchiriazaFilm(1, 4, '2021-12-30')
        self.__inchiriere_service.inchiriazaFilm(3, 6, '2021-12-30')

        ordonati = self.__inchiriere_service.getClientsOrdonatiDupaFilmeInchiriate()
        self.assertEqual(ordonati[0].getNume(),'Florentina')
        self.assertEqual(ordonati[1].getNume(),'Grigore')
        self.assertEqual(ordonati[2].getNume(),'Constantin')

    def test_numar_clienti_pe_film(self):
        self.__client_service.addClient(1, 'Grigore', 6220102018490)
        self.__film_service.addFilm(4, 'Spiderman', 'skjddsbjfb', 'action', 7)
        self.__client_service.addClient(2, 'Constantin', 6220102018490)
        self.__film_service.addFilm(6, 'Spiderman 2', 'skjddsbjfb', 'action', 4)
        self.__client_service.addClient(3, 'Florentina', 6220102018490)
        self.__film_service.addFilm(8, 'Spiderman 3', 'skjddsbjfb', 'action', 14)
        self.__inchiriere_service.inchiriazaFilm(3, 4, '2021-12-30')
        self.__inchiriere_service.inchiriazaFilm(1, 4, '2021-12-30')
        self.__inchiriere_service.inchiriazaFilm(3, 6, '2021-12-30')

        self.assertEqual(self.__inchiriere_service.numarClientiPeFilm(4),2)
        self.assertEqual(self.__inchiriere_service.numarClientiPeFilm(6), 1)
        self.assertEqual(self.__inchiriere_service.numarClientiPeFilm(8), 0)

    def test_get_filme_cele_mai_inchiriate(self):
        self.__client_service.addClient(1, 'Grigore', 6220102018490)
        self.__film_service.addFilm(4, 'Spiderman', 'skjddsbjfb', 'action', 7)
        self.__client_service.addClient(2, 'Constantin', 6220102018490)
        self.__film_service.addFilm(6, 'Spiderman 2', 'skjddsbjfb', 'action', 4)
        self.__client_service.addClient(3, 'Florentina', 6220102018490)
        self.__film_service.addFilm(8, 'Spiderman 3', 'skjddsbjfb', 'action', 14)
        self.__inchiriere_service.inchiriazaFilm(3, 8, '2021-12-30')
        self.__inchiriere_service.inchiriazaFilm(1, 8, '2021-12-30')
        self.__inchiriere_service.inchiriazaFilm(3, 4, '2021-12-30')

        ordonate  = self.__inchiriere_service.getFilmeCeleMaiInchiriate()
        self.assertEqual(ordonate[0].getTitlu(),'Spiderman 3')
        self.assertEqual(ordonate[1].getTitlu(),'Spiderman')
        self.assertEqual(ordonate[2].getTitlu(),'Spiderman 2')

    def test_nr_filme_inchiriate(self):
        self.__client_service.addClient(1, 'Grigore', 6220102018490)
        self.__film_service.addFilm(4, 'Spiderman', 'skjddsbjfb', 'action', 7)
        self.__client_service.addClient(2, 'Constantin', 6220102018490)
        self.__film_service.addFilm(6, 'Spiderman 2', 'skjddsbjfb', 'action', 4)
        self.__client_service.addClient(3, 'Florentina', 6220102018490)
        self.__film_service.addFilm(8, 'Spiderman 3', 'skjddsbjfb', 'action', 14)

        self.assertEqual(self.__inchiriere_service.nrFilmeInchiriate(self.__film_service.getFilms()),0)
        self.__inchiriere_service.inchiriazaFilm(3, 8, '2021-12-30')
        self.assertEqual(self.__inchiriere_service.nrFilmeInchiriate(self.__film_service.getFilms()), 1)
        self.__inchiriere_service.inchiriazaFilm(1, 4, '2021-12-30')
        self.assertEqual(self.__inchiriere_service.nrFilmeInchiriate(self.__film_service.getFilms()), 2)
        self.__inchiriere_service.inchiriazaFilm(2, 6, '2021-12-30')
        self.assertEqual(self.__inchiriere_service.nrFilmeInchiriate(self.__film_service.getFilms()), 3)

    def test_nr_clienti_cu_filme_inchiriate(self):
        self.__client_service.addClient(1, 'Grigore', 6220102018490)
        self.__film_service.addFilm(4, 'Spiderman', 'skjddsbjfb', 'action', 7)
        self.__client_service.addClient(2, 'Constantin', 6220102018490)
        self.__film_service.addFilm(6, 'Spiderman 2', 'skjddsbjfb', 'action', 4)
        self.__client_service.addClient(3, 'Florentina', 6220102018490)
        self.__film_service.addFilm(8, 'Spiderman 3', 'skjddsbjfb', 'action', 14)

        self.assertEqual(self.__inchiriere_service.nrClientiCuFilmeInchiriate(self.__client_service.getClients()),0)
        self.__inchiriere_service.inchiriazaFilm(3, 8, '2021-12-30')
        self.assertEqual(self.__inchiriere_service.nrClientiCuFilmeInchiriate(self.__client_service.getClients()), 1)
        self.__inchiriere_service.inchiriazaFilm(1, 8, '2021-12-30')
        self.assertEqual(self.__inchiriere_service.nrClientiCuFilmeInchiriate(self.__client_service.getClients()), 2)
        self.__inchiriere_service.inchiriazaFilm(2, 8, '2021-12-30')
        self.assertEqual(self.__inchiriere_service.nrClientiCuFilmeInchiriate(self.__client_service.getClients()), 3)
