from Lab_studenti.domain.entities import *
from Lab_studenti.exceptions.exceptions import *

class LabValidator:
    """
        Clasa pentru incapsularea algoritmului de validare pentru lab
    """
    def validate(self, lab):
        errors = []
        if lab.getId_student() < 0:
            errors.append("Id-ul studentului trebuie sa fie un numar mai mare sau egal decat 0.")
        if lab.getNr_lab() < 0:
            errors.append("Nr-ul laboratorului trebuie sa fie un numar mai mare sau egal decat 0.")
        if lab.getId_student() == '':
            errors.append("Id-ul studentului nu poate fi vid.")
        if lab.getNr_lab() == '':
            errors.append("Nr-ul laboratorului nu poate fi vid. ")

        if len(errors) > 0:
            error_string = '\n'.join(errors)
            raise ValidatorException(error_string)