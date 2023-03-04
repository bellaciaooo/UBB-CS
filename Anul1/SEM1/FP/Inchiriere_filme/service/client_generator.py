import string
import random

class ClientGenerator:
    """
        Clasa pentru genererare de date de client random
    """
    def __init__(self):
        pass

    def generateRandomID(self, size=6, chars=string.digits):
        # Genereaza ID random
        return ''.join(random.choice(chars) for _ in range(size))

    def generateRandomName(self, size=6, chars=string.ascii_lowercase ):
        # Genereaza nume random
        return ''.join(random.choice(chars) for _ in range(size))

    def generateRandomCNP(self, size=13, chars=string.digits):
        # Genereaza CNP random
        return ''.join(random.choice(chars) for _ in range(size))

