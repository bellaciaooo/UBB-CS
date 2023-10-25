from Inchiriere_filme.domain.entities import *
from Inchiriere_filme.exceptions.exceptions import ValidatorException
class FilmValidator:
    """
        Clasa pentru incapsularea algoritmului de validare pentru film
    """
    def validate(self, film):
        errors = []
        if film.getId_film() < 0:
            errors.append("Id-ul trebuie sa fie un numar mai mare sau egal decat 0.")
        if film.getTitlu() == '':
            errors.append("Titlul filmului nu poate fi vid.")
        if film.getGen() == '':
            errors.append("Genul filmului nu poate fi vid.")
        if film.getDescriere() == '':
            errors.append("Descrierea filmului nu poate fi vida.")
        if film.getNr_filme_disponibile() <= 0:
            errors.append("Numarul de filme disponibile trebuie sa fie un numar mai mare decat 0.")

        if len(errors) > 0:
            error_string = '\n'.join(errors)
            raise ValidatorException(error_string)

class ClientValidator:
    """
        Clasa pentru incapsularea algoritmului de validare
    """
    def validate(self, client):
        errors = []
        if client.getId_client() < 0:
            errors.append("Id-ul trebuie sa fie un numar mai mare sau egal decat 0.")
        if client.getNume() == '':
            errors.append("Numele clientului nu poate fi vid.")
        if len(str(client.getCnp())) != 13:
            errors.append("CNP-ul clientului trebuie sa aiba exact 13 cifre!")

        if len(errors) > 0:
            error_string = '\n'.join(errors)
            raise ValidatorException(error_string)

class InchiriereValidator:
    """
         Clasa pentru incapsularea algoritmului de validare
    """
    def validate(self,inchiriere):
        errors = []
        if inchiriere.getId_client() < 0:
            errors.append("Id-ul clientului trebuie sa fie un numar mai mare sau egal decat 0.")
        if inchiriere.getId_film() < 0:
            errors.append("Id-ul filmului trebuie sa fie un numar mai mare sau egal decat 0.")

        if len(errors) > 0:
            error_string = '\n'.join(errors)
            raise ValidatorException(error_string)