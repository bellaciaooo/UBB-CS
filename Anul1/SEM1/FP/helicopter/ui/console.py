from helicopter.repository.helicopter_repo import *
from helicopter.service.helicopter_service import *

class Console:
    def __init__(self, helicopter_service: HelicopterService):
        self.__helicopter_service = helicopter_service

    def add_helicopter_to_list(self):
        """
            Adauga un helicopter la lista de helicoptere.
        """
        id_helicopter = input("ID-ul helicopterului este: ")
        nume = input("Numele helicopterului este: ")
        sir_scopuri = input("Sirul de scopuri al helicopterului este: ")
        an_fab = input("Anul de fabricatie al helicopterului este: ")
        id_helicopter = int(id_helicopter)
        an_fab = int(an_fab)
        self.__helicopter_service.addHelicopter(id_helicopter, nume, sir_scopuri, an_fab)

    def helicoptere_dupa_scopuri(self):
        scop = input("Introduceti scopul dorit: ")
        if scop == "":
            print("Scopul nu poate fi vid!")
        else:
            filtered_helicopters = self.__helicopter_service.getHelicoptersDupaScop(scop)
            if len(filtered_helicopters) == 0:
                print("Nu exista helicoptere cu scopul dat!")
            else:
                self.__helicopter_service.ordonareDescrescatoareHelicoptere(filtered_helicopters)
                for helicopter in filtered_helicopters:
                    print(helicopter)

    def grupareScopuri(self):
        scopuri = self.__helicopter_service.grupareScopuri(self.__helicopter_service.getHelicopters())
        for scop in scopuri:
            print(scop)

    def menu(self):
        """
            Meniul aplicatiei.
        """
        print("--------------------------------------------------------------------------------------------------------------------------------------------")
        print("0. Iesirea din aplicatie.")
        print("1.*Introducerea unui elicopter.")
        print("2. Afișarea tuturor elicopterelor care conțin un anumit scop citit de la tastatură în șirul cu scopuri, ordonate descrescător după nume.")
        print("3. Grupare după scopuri: pentru fiecare scop distinct, se afișează anii de fabricație ale elicopterelor care se pot folosi cu scopul respectiv.")
        print("--------------------------------------------------------------------------------------------------------------------------------------------")

    def run(self):
        self.menu()
        dict_of_commands = {
            "1": self.add_helicopter_to_list,
            "2": self.helicoptere_dupa_scopuri,
            "3": self.grupareScopuri
        }
        while True:
            command = input("Introduceti optiunea dorita: ")
            if command in dict_of_commands:
                try:
                    dict_of_commands[command]()
                except ServiceException as ex:
                    print(ex)
                except ValidatorException as ex:
                    print(ex)
                except RepoException as ex:
                    print(ex)
                except ValueError:
                    print("Valoare introdusa trebuie sa fie de tip integer!")
                self.menu()
            elif command == '0':
                break
            else:
                print("Optiunea introdusa nu exista!")
