from unittest import TestCase
from Inchiriere_filme.domain.entities import *
from Inchiriere_filme.repository.film_repo import *
from Inchiriere_filme.service.film_service import *

class TestFilmService(TestCase):
    def setUp(self) -> None:
        repo = FilmRepository()
        vali = FilmValidator()
        self.__film_service = FilmService(repo, vali)

    def test_get_films(self):
        self.__film_service.addFilm(3,'Cucaracha','shbfbsdhkfd','actiune',17)
        films = self.__film_service.getFilms()
        self.assertEqual(len(films),1)
        self.assertIsInstance(films, list)
        filmul = Film(3,'Cucaracha','shbfbsdhkfd','actiune',17)
        self.assertEqual(films[0],filmul)

    def test_add_film(self):
        self.__film_service.addFilm(1,'Dama cu camelii','sdbjhfksjf','romantic',32)
        self.assertEqual(len(self.__film_service.getFilms()),1)
        self.__film_service.addFilm(2,'Aventurile necunoscute','dsjbfdshksd','animatie',15)
        self.assertEqual(len(self.__film_service.getFilms()),2)

        self.assertRaises(ServiceException,self.__film_service.addFilm, -11,'Pokemon Go','sdnfkdnsfd','science-fiction',14)
        self.assertRaises(ServiceException,self.__film_service.addFilm,1, 'Pokemon Go', 'sdn', 'science-fiction', 14)
        self.assertRaises(ServiceException,self.__film_service.addFilm, 4, '', 'sdnfkdnsfd', 'science-fiction', 14)

    def test_delete_film(self):
        self.__film_service.addFilm(1, 'Aventurile necunoscute', 'dsjbfdshksd', 'animatie', 15)
        self.__film_service.addFilm(2, 'Dama cu camelii', 'sdbjhfksjf', 'romantic', 32)
        self.__film_service.addFilm(3, 'Godzilla', 'dsjbfdshksd', 'horror', 9)
        self.__film_service.addFilm(4, 'Nemo', 'dsjbfdshksd', 'animatie', 25)

        self.__film_service.deleteFilm(3)
        self.assertEqual(len(self.__film_service.getFilms()),3)
        self.__film_service.deleteFilm(1)
        self.assertEqual(len(self.__film_service.getFilms()),2)
        self.assertRaises(ServiceException, self.__film_service.deleteFilm,11)

    def test_update_film(self):
        self.__film_service.addFilm(1, 'Aventurile necunoscute', 'dsjbfdshksd', 'animatie', 15)
        self.__film_service.addFilm(2, 'Dama cu camelii', 'sdbjhfksjf', 'romantic', 32)
        self.__film_service.addFilm(3, 'Godzilla', 'dsjbfdshksd', 'horror', 9)

        self.__film_service.updateFilm(3, 'Spiderman', 'dsbjbfskkfd','actiune',12)
        films = self.__film_service.getFilms()
        filmul = Film(3, 'Spiderman', 'dsbjbfskkfd','actiune',12)
        self.assertEqual(films[2],filmul)
        self.assertRaises(ServiceException, self.__film_service.updateFilm, 4, 'Spiderman', 'dsbjbfskkfd','actiune',12)
        self.assertRaises(ServiceException, self.__film_service.updateFilm, 4, '', 'dsbbfskkfd', 'actiune',12)
        self.assertRaises(ServiceException, self.__film_service.updateFilm, 4, 'Spiderman', '', '',12)

    def test_filter_by_title(self):
        self.__film_service.addFilm(1, 'Aventurile necunoscute', 'dsjbfdshksd', 'animatie', 15)
        self.__film_service.addFilm(2, 'Dama cu camelii', 'sdbjhfksjf', 'romantic', 32)
        self.__film_service.addFilm(3, 'Godzilla', 'dsjbfdshksd', 'horror', 9)
        self.__film_service.addFilm(4, 'Avatar', 'dsjbfdshksd', 'animatie', 25)

        filtered = self.__film_service.filterByTitle('Av')
        self.assertEqual(len(filtered),2)
        self.assertEqual(filtered[0].getTitlu(),'Aventurile necunoscute')
        self.assertEqual(filtered[1].getTitlu(),'Avatar')
        filtered = self.__film_service.filterByTitle('rggt')
        self.assertEqual(filtered,[])