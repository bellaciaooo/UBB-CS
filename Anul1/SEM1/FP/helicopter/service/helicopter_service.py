from helicopter.repository.helicopter_repo import *
from helicopter.validators.validators import *

class HelicopterService:
    def __init__(self, helicopter_repo : HelicopterRepo, helicopter_validator : HelicopterValidator):
        self.__helicopter_repo = helicopter_repo
        self.__helicopter_validator = helicopter_validator

    def getHelicopters(self):
        return self.__helicopter_repo.getHelicopters()

    def addHelicopter(self, id_helicopter, nume, sir_scopuri, an_fab):
        """
            Adaugarea unui nou helicopter.
        """
        newHelicopter = Helicopter(id_helicopter, nume, sir_scopuri, an_fab)
        try:
            self.__helicopter_validator.validate(newHelicopter)
            try:
                self.__helicopter_repo.addHelicopter(newHelicopter)
            except RepoException as ex:
                raise ServiceException(ex)
        except ValidatorException as ex:
            raise ServiceException(ex)

    def ordonareDescrescatoareHelicoptere(self, helicopters):
        """
            Ordonarea descrescatoare dupa nume a helicopterelor.
        """
        helicopters.sort(key = lambda x : x.getNume(), reverse=True)
        return helicopters

    def getHelicoptersDupaScop(self, scop):
        """
            Filtrarea helicopterelor cu un anumit scop dat de la tastatura fata de restul helicopterelor.
        """
        helicopters = self.__helicopter_repo.getHelicopters()
        filtered_helicopters = []
        for helicopter in helicopters:
            if scop in helicopter.getSir_scopuri():
                filtered_helicopters.append(helicopter)
        return filtered_helicopters

    def grupareScopuri(self, helicopters):
        """
            Se creaza si returneaza lista cu scopuri distincte ale helicopterelor si se introduc pentru fiecare scop anii
            de fabricație ale helicopterelor care se pot folosi cu scopul respectiv.
        """
        grupari = []
        for helicopter in helicopters:
            for scop in helicopter.getSir_scopuri().split(" "):
                ok = False
                for grupare in grupari:
                    if scop == grupare.getNume_scop():
                        grupare.addAn(helicopter.getAn_fab())
                        ok = True
                        break
                if not ok:
                    grupareNoua = Grupare(scop)
                    grupareNoua.addAn(helicopter.getAn_fab())
                    grupari.append(grupareNoua)

        return grupari

