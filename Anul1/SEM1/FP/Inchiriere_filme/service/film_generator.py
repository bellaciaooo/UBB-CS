import string
import random

class FilmGenerator:
    """
        Clasa pentru genererare de date de film random
    """
    def generateRandomID(self, size=6, chars=string.digits):
        # Genereaza ID random
        return ''.join(random.choice(chars) for _ in range(size))

    def generateRandomString(self, size=6, chars=string.ascii_lowercase ):
        # Genereaza string random pentru titlu, descriere, gen
        return ''.join(random.choice(chars) for _ in range(size))

    def generateRandomNr_filme(self, size=2, chars=string.digits):
        # Genereaza nr de filme random
        return ''.join(random.choice(chars) for _ in range(size))


