from Inchiriere_filme.exceptions.exceptions import *
from Inchiriere_filme.domain.entities import Film

class FilmRepository:
    def __init__(self):
        self.__films = []

    def getFilms(self):
        return self.__films

    def addFilm(self, film):
        if film in self.__films:
            raise RepoException("Id-ul filmului este deja in lista!")
        self.__films.append(film)

    def searchFilmById(self, id_film):
        """
            Cauta in lista filmul avand id-ul = id_film
            Returneaza * filmul, daca acesta exista in lista
                       * ridica exceptie, in caz contrar
        """
        for film in self.__films:
            if film.getId_film() == id_film:
                return film
        raise RepoException("Nu exista filmul cu id-ul dat!")

    ##########RECURSIVITATE################
    def searchRecursivFilmById(self, i, films, id_film):
        """
            Cauta recursiv in lista de filme filmul avand id-ul = id_film
            Returneaza * filmul, daca acesta exista in lista
                       * ridica exceptie, in caz contrar
        """
        if i >= 0 and  i < len(films):
            if films[i].getId_film() == id_film:
                return films[i]
            else:
                return self.searchRecursivFilmById(i+1, films, id_film)
        else:
            raise RepoException("Nu exista filmul cu id-ul dat!")

    def deleteRecursivFilm(self, i, films, id_film):
        """
            Sterge cautand recursiv filmul in functie de id = id_film
        """
        if i >= 0 and  i < len(films):
            if films[i].getId_film() == id_film:
                films.pop(i)
                return
            else:
                return self.deleteRecursivFilm(i+1, films, id_film)
        else:
            raise RepoException("Delete error: Nu exista id-ul filmului specificat in lista!")

    #######################################

    def deleteFilm(self, id_film):
        """
            Sterge filmul in functie de id = id_film
        """
        for i in range(len(self.__films)):
            if self.__films[i].getId_film() == id_film:
                self.__films.pop(i)
                return
        raise RepoException("Delete error: Nu exista id-ul filmului specificat in lista!")

    def updateFilm(self, newFilm):
        """
            Modifica filmul avand id-ul egal id-ul filmului newFilm, setandu-i campurile cu noile date
        """
        for i in range(len(self.__films)):
            if self.__films[i].getId_film() == newFilm.getId_film():
                self.__films[i]=newFilm
                return
        raise RepoException("Update error: Nu exista id-ul specificat in lista!")

class FilmRepoFile:
    def __init__(self, fileName):
        self.__fileName = fileName

    def __load_from_file(self):
        try:
            f = open(self.__fileName, 'r')
        except IOError:
            raise CorruptedFileException("File Error: Nu exista fisierul cu numele dat!")

        films = []
        lines = f.readlines()
        for line in lines:
            id_film, titlu, descriere, gen, nr_filme_disponibile = [token.strip() for token in line.split(',')]
            film = Film(int(id_film), titlu, descriere, gen, int(nr_filme_disponibile))
            films.append(film)

        f.close()
        return films

    def __save_to_file(self, films):
        with open(self.__fileName, 'w') as f:
            for film in films:
                film_string = str(film.getId_film()) + ',' + str(film.getTitlu()) + ',' + str(film.getDescriere()) + ',' + str(film.getGen()) + ',' + str(film.getNr_filme_disponibile()) + '\n'
                f.write(film_string)

    def searchFilmById(self, id_film):
        """
            Cauta in lista filmul avand id-ul = id_film
            Returneaza * filmul, daca acesta exista in lista
                       * ridica exceptie, in caz contrar
        """
        all_films = self.__load_from_file()
        for film in all_films:
            if film.getId_film() == id_film:
                return film
        raise RepoException("Nu exista filmul cu id-ul dat!")

    def addFilm(self, film):
        """
            Adaugam un film la lista de filme.
        """
        all_films = self.__load_from_file()
        if film in all_films:
            raise RepoException("Id-ul filmului este deja in lista!")
        all_films.append(film)
        self.__save_to_file(all_films)

    def updateFilm(self, newFilm):
        """
            Modifica filmul avand id-ul egal id-ul filmului newFilm, setandu-i campurile cu noile date
        """
        all_films = self.__load_from_file()
        for i in range(len(all_films)):
            if all_films[i].getId_film() == newFilm.getId_film():
                all_films[i] = newFilm
                self.__save_to_file(all_films)
                return
        raise RepoException("Update error: Nu exista id-ul filmului specificat in lista!")

    def deleteFilm(self, id_film):
        """
            Sterge filmul in functie de id = id_film
        """
        all_films = self.__load_from_file()
        for i in range(len(all_films)):
            if all_films[i].getId_film() == id_film:
                all_films.pop(i)
                self.__save_to_file(all_films)
                return
        raise RepoException("Delete error: Nu exista id-ul filmului specificat in lista!")

    def getFilms(self):
        return self.__load_from_file()