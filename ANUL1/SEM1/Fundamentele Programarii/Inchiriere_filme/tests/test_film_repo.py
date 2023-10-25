from unittest import TestCase
from Inchiriere_filme.exceptions.exceptions import *
from Inchiriere_filme.domain.entities import Film
from Inchiriere_filme.repository.film_repo import *


class TestFilmRepository(TestCase):
    def setUp(self) -> None:
        self.__repo = FilmRepository()

    def test_add_film(self):
        film1 = Film(1, 'Nanny McPhee', 'ewknewnrkwe', 'Comedie', 12)
        film2 = Film(2, 'A star was born', 'ekbewkbrewe', 'Drama', 23)
        self.__repo.addFilm(film1)
        self.assertEqual(len(self.__repo.getFilms()), 1)
        self.__repo.addFilm(film2)
        self.assertEqual(len(self.__repo.getFilms()), 2)

        film2 = Film(2, 'A star was born', 'ekbewkbrewe', 'Drama', 23)
        self.assertRaises(RepoException, self.__repo.addFilm, film2)

    def test_get_films(self):
        film1 = Film(1, 'Nanny McPhee', 'ewknewnrkwe', 'Comedie', 12)
        self.__repo.addFilm(film1)

        films = self.__repo.getFilms()
        self.assertEqual(films[0], film1)
        self.assertEqual(len(films), 1)
        self.assertIsInstance(films, list)

    def test_search_film_by_id(self):
        film1 = Film(1, 'Nanny McPhee', 'ewknewnrkwe', 'Comedie', 12)
        film2 = Film(2, 'A star was born', 'ekbewkbrewe', 'Drama', 23)
        film3 = Film(3, 'Jelly Bean', 'errewknewnrkwe', 'Familie', 6)
        film4 = Film(4, 'Alchemist', 'egregrkbewkbrewe', 'Actiune', 78)
        self.__repo.addFilm(film1)
        self.__repo.addFilm(film2)
        self.__repo.addFilm(film3)
        self.__repo.addFilm(film4)

        fl = self.__repo.searchFilmById(3)
        self.assertEqual(fl.getTitlu(), 'Jelly Bean')
        self.assertEqual(fl.getGen(), 'Familie')
        self.assertEqual(fl.getNr_filme_disponibile(), 6)

        self.assertRaises(RepoException, self.__repo.searchFilmById, 1231)

    def test_delete_film(self):
        film1 = Film(1, 'Nanny McPhee', 'ewknewnrkwe', 'Comedie', 12)
        film2 = Film(2, 'A star was born', 'ekbewkbrewe', 'Drama', 23)
        film3 = Film(3, 'Jelly Bean', 'errewknewnrkwe', 'Familie', 6)
        film4 = Film(4, 'Alchemist', 'egregrkbewkbrewe', 'Actiune', 78)
        self.__repo.addFilm(film1)
        self.__repo.addFilm(film2)
        self.__repo.addFilm(film3)
        self.__repo.addFilm(film4)

        self.__repo.deleteFilm(1)
        self.__repo.deleteFilm(2)
        self.assertEqual(len(self.__repo.getFilms()), 2)
        self.assertRaises(RepoException, self.__repo.deleteFilm, 324)

    def test_update_film(self):
        film1 = Film(1, 'Nanny McPhee', 'ewknewnrkwe', 'Comedie', 12)
        film2 = Film(2, 'A star was born', 'ekbewkbrewe', 'Drama', 23)
        film3 = Film(3, 'Jelly Bean', 'errewknewnrkwe', 'Familie', 6)
        self.__repo.addFilm(film1)
        self.__repo.addFilm(film2)
        self.__repo.addFilm(film3)

        newFilm = Film(2, 'A star in the sky', 'ekbewkbrewe', 'Comedie', 32)
        fakeFilm = Film(4, 'Alchemist', 'egregrkbewkbrewe', 'Actiune', 78)
        self.__repo.updateFilm(newFilm)
        films = self.__repo.getFilms()
        self.assertEqual(films[1], newFilm)
        self.assertRaises(RepoException, self.__repo.updateFilm, fakeFilm)


class TestFilmRepoFile(TestCase):
    def setUp(self) -> None:
        self.__repo = FilmRepoFile('test_filme.txt')

    def test_search_film_by_id(self):
        newFilm = Film(23,'Dragostea din tei','sdkbfbdksf','Romantic',54)
        self.__repo.addFilm(newFilm)

        filmul = self.__repo.searchFilmById(23)
        self.assertEqual(filmul.getTitlu(),'Dragostea din tei')
        self.assertEqual(filmul.getGen(),'Romantic')
        self.assertEqual(filmul.getNr_filme_disponibile(),54)
        self.assertRaises(RepoException,self.__repo.searchFilmById,65)
        self.__repo.deleteFilm(23)

    def test_add_film(self):
        newFilm = Film(14,'Amicii','sdkbfbdksf','Familie',34)
        fakeFilm = Film(14,'Comoara din adancuri','sdkbfbdksf','Romantic',45)

        self.__repo.addFilm(newFilm)
        films = self.__repo.getFilms()
        self.assertEqual(len(films),1)
        self.assertEqual(films[0],newFilm)
        self.assertRaises(RepoException,self.__repo.addFilm,fakeFilm)
        self.__repo.deleteFilm(14)

    def test_update_film(self):
        filmul = Film(14, 'Nostalgia by Kaufland', 'sdkbfbdksf', 'Familie', 34)
        newFilm = Film(14, 'Alchemist', 'sdkbfbdksf', 'Aventura', 34)
        fakeFilm = Film(343, 'Comoara din adancuri', 'sdkbfbdksf', 'Romantic', 45)
        self.__repo.addFilm(filmul)

        self.__repo.updateFilm(newFilm)
        films = self.__repo.getFilms()
        self.assertEqual(films[0],newFilm)
        self.assertRaises(RepoException,self.__repo.updateFilm,fakeFilm)
        self.__repo.deleteFilm(14)

    def test_delete_film(self):
        film1 = Film(14, 'Alchemist', 'sdkbfbdksf', 'Aventura', 34)
        film2 = Film(43, 'Comoara din adancuri', 'sdkbfbdksf', 'Romantic', 45)
        self.__repo.addFilm(film1)
        self.__repo.addFilm(film2)

        self.assertEqual(len(self.__repo.getFilms()), 2)
        self.__repo.deleteFilm(14)
        self.assertEqual(len(self.__repo.getFilms()), 1)
        self.__repo.deleteFilm(43)
        self.assertEqual(len(self.__repo.getFilms()), 0)

    def test_get_films(self):
        filmul = Film(14, 'Nostalgia by Kaufland', 'sdkbfbdksf', 'Familie', 34)
        self.__repo.addFilm(filmul)

        films = self.__repo.getFilms()
        self.assertEqual(films[0],filmul)
        self.assertEqual(len(films),1)
        self.assertIsInstance(films,list)
        self.__repo.deleteFilm(14)