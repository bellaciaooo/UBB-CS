from unittest import TestCase
from Inchiriere_filme.repository.inchiriere_repo import *


class TestInchiriereRepository(TestCase):
    def setUp(self) -> None:
        self.__repo = InchiriereRepository()

    def test_add_inchiriere(self):
        inchiriere1 = Inchiriere(1, 3, '2021-12-30')
        inchiriere2 = Inchiriere(2, 4, '2021-12-11')
        self.__repo.addInchiriere(inchiriere1)
        self.assertEqual(len(self.__repo.getInchirieri()), 1)
        self.__repo.addInchiriere(inchiriere2)
        self.assertEqual(len(self.__repo.getInchirieri()), 2)

        inchiriere1 = Inchiriere(1, 3, '2021-12-30')
        self.assertRaises(RepoException, self.__repo.addInchiriere, inchiriere1)

    def test_get_inchirieri(self):
        inchiriere = Inchiriere(11, 32, '2021-12-20')
        self.__repo.addInchiriere(inchiriere)

        inchirieri = self.__repo.getInchirieri()
        self.assertEqual(inchirieri[0], inchiriere)
        self.assertIsInstance(inchirieri, list)
        self.assertEqual(len(inchirieri), 1)

    def test_check_inchiriat_by_client(self):
        inchiriere1 = Inchiriere(1, 3, '2021-12-30')
        inchiriere2 = Inchiriere(2, 4, '2021-12-11')
        inchiriere3 = Inchiriere(5, 7, '2021-12-24')
        inchiriere4 = Inchiriere(9, 11, '2021-11-14')
        self.__repo.addInchiriere(inchiriere1)
        self.__repo.addInchiriere(inchiriere2)
        self.__repo.addInchiriere(inchiriere3)
        self.__repo.addInchiriere(inchiriere4)
        inchiriat = self.__repo.checkInchiriatByClient(7, 5)
        self.assertEqual(inchiriat.getData_inchirierii(), '2021-12-24')
        self.assertRaises(RepoException, self.__repo.checkInchiriatByClient, 12, 43)

    def test_delete_inchiriere(self):
        inchiriere1 = Inchiriere(1, 3, '2021-12-30')
        inchiriere2 = Inchiriere(2, 4, '2021-12-11')
        inchiriere3 = Inchiriere(5, 7, '2021-12-24')
        inchiriere4 = Inchiriere(9, 11, '2021-11-14')
        self.__repo.addInchiriere(inchiriere1)
        self.__repo.addInchiriere(inchiriere2)
        self.__repo.addInchiriere(inchiriere3)
        self.__repo.addInchiriere(inchiriere4)

        self.__repo.deleteInchiriere(3, 1)
        self.__repo.deleteInchiriere(11, 9)
        self.assertEqual(len(self.__repo.getInchirieri()), 2)
        self.assertRaises(RepoException, self.__repo.deleteInchiriere, 21, 32)

    def test_update_inchiriere(self):
        inchiriere1 = Inchiriere(1, 3, '2021-12-30')
        inchiriere2 = Inchiriere(2, 4, '2021-12-11')
        inchiriere3 = Inchiriere(5, 7, '2021-12-24')
        self.__repo.addInchiriere(inchiriere1)
        self.__repo.addInchiriere(inchiriere2)
        self.__repo.addInchiriere(inchiriere3)

        newInchiriere = Inchiriere(5, 7, '2021-11-14')
        fakeInchiriere = Inchiriere(9, 11, '2021-11-14')
        self.__repo.updateInchiriere(newInchiriere)
        inchirieri = self.__repo.getInchirieri()
        self.assertEqual(inchirieri[2], newInchiriere)
        self.assertRaises(RepoException, self.__repo.updateInchiriere, fakeInchiriere)


class TestInchiriereRepoFile(TestCase):
    def setUp(self) -> None:
        self.__repo = InchiriereRepoFile('test_inchirieri.txt')

    def test_get_inchirieri(self):
        inchiriere = Inchiriere(11, 32, '2021-12-20')
        self.__repo.addInchiriere(inchiriere)

        inchirieri = self.__repo.getInchirieri()
        self.assertEqual(len(inchirieri),1)
        self.assertEqual(inchirieri[0],inchiriere)
        self.assertIsInstance(inchirieri,list)
        self.__repo.deleteInchiriere(32,11)

    def test_check_inchiriat_by_client(self):
        inchiriere = Inchiriere(15, 47, '2021-12-24')
        self.__repo.addInchiriere(inchiriere)

        inchiriat = self.__repo.checkInchiriatByClient(47, 15)
        self.assertEqual(inchiriat.getData_inchirierii(), '2021-12-24')
        self.assertRaises(RepoException, self.__repo.checkInchiriatByClient, 12, 43)
        self.__repo.deleteInchiriere(47,15)

    def test_add_inchiriere(self):
        newInchiriere = Inchiriere(9, 11, '2021-11-14')
        fakeInchiriere = Inchiriere(9, 11, '2021-12-23')

        self.__repo.addInchiriere(newInchiriere)
        inchirieri = self.__repo.getInchirieri()
        self.assertEqual(inchirieri[0],newInchiriere)
        self.assertEqual(len(inchirieri),1)
        self.assertRaises(RepoException,self.__repo.addInchiriere,fakeInchiriere)
        self.__repo.deleteInchiriere(11,9)

    def test_delete_inchiriere(self):
        inchiriere1 = Inchiriere(1, 3, '2021-12-30')
        inchiriere2 = Inchiriere(2, 4, '2021-12-11')
        inchiriere3 = Inchiriere(5, 7, '2021-12-24')
        self.__repo.addInchiriere(inchiriere1)
        self.__repo.addInchiriere(inchiriere2)
        self.__repo.addInchiriere(inchiriere3)

        self.__repo.deleteInchiriere(3, 1)
        self.assertEqual(len(self.__repo.getInchirieri()), 2)
        self.__repo.deleteInchiriere(4, 2)
        self.assertEqual(len(self.__repo.getInchirieri()), 1)
        self.__repo.deleteInchiriere(7, 5)
        self.assertEqual(len(self.__repo.getInchirieri()), 0)

    def test_update_inchiriere(self):
        inchiriere = Inchiriere(5, 7, '2021-12-24')
        self.__repo.addInchiriere(inchiriere)
        newInchiriere = Inchiriere(5, 7, '2021-11-14')
        fakeInchiriere = Inchiriere(9, 11, '2021-11-14')

        self.__repo.updateInchiriere(newInchiriere)
        inchirieri = self.__repo.getInchirieri()
        self.assertEqual(inchirieri[0], newInchiriere)
        self.assertRaises(RepoException, self.__repo.updateInchiriere, fakeInchiriere)
        self.__repo.deleteInchiriere(7,5)
