from unittest import TestCase
from Inchiriere_filme.domain.entities import *
from Inchiriere_filme.exceptions.exceptions import ValidatorException
from Inchiriere_filme.validators.validators import *


class TestFilmValidator(TestCase):
    def setUp(self) -> None:
        self.__validator = FilmValidator()

    def test_validate(self):
        film = Film(13, 'Spioanele', 'sdnkfnds', 'dsfkn', 34)
        self.__validator.validate(film)
        film2 = Film(13, '', 'sdnkfnds', 'dsfkn', 34)
        self.assertRaises(ValidatorException, self.__validator.validate, film2)
        film3 = Film(-213, 'fkjdfbf', 'sdnkfnds', 'dsfkn', 34)
        self.assertRaises(ValidatorException, self.__validator.validate, film3)
        film4 = Film(213, 'fkjdfbf', 'sdnkfnds', 'dsfkn', -34)
        self.assertRaises(ValidatorException, self.__validator.validate, film4)
        film5 = Film(213, 'fkjdfbf', '', '', 34)
        self.assertRaises(ValidatorException, self.__validator.validate, film5)


class TestClientValidator(TestCase):
    def setUp(self) -> None:
        self.__validator = ClientValidator()

    def test_validate(self):
        client = Client(12,'Grigorescu',6220102018298)
        self.__validator.validate(client)
        client1 = Client(-12, 'Grigorescu', 6220102018298)
        self.assertRaises(ValidatorException, self.__validator.validate, client1)
        client2 = Client(12, '', 6220102018298)
        self.assertRaises(ValidatorException, self.__validator.validate, client2)
        client3 = Client(12, 'Grigorescu', 622)
        self.assertRaises(ValidatorException, self.__validator.validate, client3)


class TestInchiriereValidator(TestCase):
    def setUp(self) -> None:
        self.__validator = InchiriereValidator()

    def test_validate(self):
        inchiriere = Inchiriere(123, 321, '2021-12-30')
        self.__validator.validate(inchiriere)
        inchiriere2 = Inchiriere(-123, 321, '2021-12-30')
        self.assertRaises(ValidatorException, self.__validator.validate, inchiriere2)
        inchiriere3 = Inchiriere(123, -321, '2021-12-30')
        self.assertRaises(ValidatorException, self.__validator.validate, inchiriere3)