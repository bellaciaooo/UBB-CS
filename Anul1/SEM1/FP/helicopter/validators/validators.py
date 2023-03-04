from helicopter.domain.entities import *
from helicopter.exceptions.exceptions import *

class HelicopterValidator:
    """
        Clasa pentru incapsularea algoritmului de validare pentru helicopter.
    """
    def validate(self, helicopter):
        errors = []
        if helicopter.getId_helicopter() < 0:
            errors.append("ID-ul trebuie sa fie un numar mai mare sau egal cu 0!")
        if helicopter.getNume() == "":
            errors.append("Numele helicopterului nu poate fi vid!")
        if helicopter.getSir_scopuri() == "":
            errors.append("Sirul de scopuri al helicopterului nu poate fi vid!")
        if helicopter.getAn_fab() <= 0:
            errors.append("Anul fabricatiei nu poate fi mai mic decat 0!")

        if len(errors) > 0:
            error_string = '\n'.join(errors)
            raise ValidatorException(error_string)
