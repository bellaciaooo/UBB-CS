from Inchiriere_filme.repository.film_repo import *
from Inchiriere_filme.validators.validators import *
from Inchiriere_filme.exceptions.exceptions import ServiceException


class FilmService:
    def __init__(self, film_repo: FilmRepository, film_validator: FilmValidator):
        self.__film_repo = film_repo
        self.__film_validator = film_validator

    def getFilms(self):
        return self.__film_repo.getFilms()

    def addFilm(self, id_film, titlu, descriere, gen, nr_filme_disponibile):
        newFilm = Film(id_film, titlu, descriere, gen, nr_filme_disponibile)
        try:
            self.__film_validator.validate(newFilm)
            try:
                self.__film_repo.addFilm(newFilm)
            except RepoException as ex:
                raise ServiceException(ex)
        except ValidatorException as ex:
            raise ServiceException(ex)

    def deleteFilm(self, id_film):
        try:
            self.__film_repo.deleteFilm(id_film)
        except RepoException as ex:
            raise ServiceException(ex)

    def updateFilm(self, id_film, titlu, descriere, gen, nr_filme_disponibile):
        newFilm = Film(id_film, titlu, descriere, gen, nr_filme_disponibile)
        try:
            self.__film_validator.validate(newFilm)
            try:
                self.__film_repo.updateFilm(newFilm)
            except RepoException as ex:
                raise ServiceException(ex)
        except ValidatorException as ex:
            raise ServiceException(ex)

    def filterByTitle(self, part_of_title):
        """
            Selecteaza filmele care contin part_of_title in titlu
        """
        all_films = self.getFilms()
        filtered_list = []
        for film in all_films:
            if part_of_title in film.getTitlu():
                filtered_list.append(film)
        return filtered_list

