from unittest import TestCase
from Inchiriere_filme.domain.entities import *


class TestFilm(TestCase):
    def setUp(self):
        self.film = Film(2, 'asasd', 'sdad', 'asda', 3)

    def test_get_id_film(self):
        self.assertEqual(self.film.getId_film(), 2)

    def test_get_titlu(self):
        self.assertEqual(self.film.getTitlu(), 'asasd')

    def test_get_descriere(self):
        self.assertEqual(self.film.getDescriere(), 'sdad')

    def test_get_gen(self):
        self.assertEqual(self.film.getGen(), 'asda')

    def test_get_nr_filme_disponibile(self):
        self.assertEqual(self.film.getNr_filme_disponibile(), 3)

    def test_set_id_film(self):
        self.film.setId_film(1)
        self.assertEqual(self.film.getId_film(), 1)

    def test_set_titlu(self):
        self.film.setTitlu('Spider')
        self.assertEqual(self.film.getTitlu(), 'Spider')

    def test_set_descriere(self):
        self.film.setDescriere('exista')
        self.assertEqual(self.film.getDescriere(), 'exista')

    def test_set_gen(self):
        self.film.setGen('drama')
        self.assertEqual(self.film.getGen(), 'drama')

    def test_set_nr_filme_disponibile(self):
        self.film.setNr_filme_disponibile(7)
        self.assertEqual(self.film.getNr_filme_disponibile(), 7)

    def test_increase_nr_filme_disponibile(self):
        self.film.increase_nr_filme_disponibile()
        self.assertEqual(self.film.getNr_filme_disponibile(), 4)

    def test_decrease_nr_filme_disponibile(self):
        self.film.decrease_nr_filme_disponibile()
        self.film.decrease_nr_filme_disponibile()
        self.assertEqual(self.film.getNr_filme_disponibile(), 1)


class TestClient(TestCase):
    def setUp(self):
        self.client = Client(12, 'Silvester', 6220101018762)

    def test_get_id_client(self):
        self.assertEqual(self.client.getId_client(), 12)

    def test_get_nume(self):
        self.assertEqual(self.client.getNume(), 'Silvester')

    def test_get_cnp(self):
        self.assertEqual(self.client.getCnp(), 6220101018762)

    def test_set_id_client(self):
        self.client.setId_client(43)
        self.assertEqual(self.client.getId_client(), 43)

    def test_set_nume(self):
        self.client.setNume('Cristofer')
        self.assertEqual(self.client.getNume(), 'Cristofer')

    def test_set_cnp(self):
        self.client.setCnp(6220101019537)
        self.assertEqual(self.client.getCnp(), 6220101019537)


class TestInchiriere(TestCase):
    def setUp(self):
        self.inchiriere = Inchiriere(21,75,'2021-12-30')

    def test_get_id_client(self):
        self.assertEqual(self.inchiriere.getId_client(),21)

    def test_get_id_film(self):
        self.assertEqual(self.inchiriere.getId_film(),75)

    def test_get_data_inchirierii(self):
        self.assertEqual(self.inchiriere.getData_inchirierii(),'2021-12-30')

    def test_set_id_client(self):
        self.inchiriere.setId_client(43)
        self.assertEqual(self.inchiriere.getId_client(),43)

    def test_set_id_film(self):
        self.inchiriere.setId_film(89)
        self.assertEqual(self.inchiriere.getId_film(),89)

    def test_set_data_inchirierii(self):
        self.inchiriere.setData_inchirierii('2021-12-11')
        self.assertEqual(self.inchiriere.getData_inchirierii(),'2021-12-11')
