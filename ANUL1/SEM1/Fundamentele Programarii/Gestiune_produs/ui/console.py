from Gestiune_produs.service.produs_service import *

class Console:
    def __init__(self, produs_service : ProdusService):
        self.__produs_service = produs_service
        self.__undo_list = []
        self.__text = "as"
        self.__pret = 90

    def addProdus(self):
        """
            Adaugare produs la lista de produse.
        """
        id_produs = input("Introduceti id-ul produsului: ")
        denumire = input("Introduceti denumirea produsului: ")
        pret = input("Introduceti pretul produsului: ")
        id_produs = int(id_produs)
        self.__produs_service.addProdus(id_produs,denumire,pret)

    def deleteProdus(self):
        """
            Stergerea produselor cu care au in pret cifra introdusa de la tastatura, se afiseaza nr de produse sterse.
        """
        cifra = input("Introduceti cifra dorita: ")
        nr_produse = self.__produs_service.deleteProdus(self.__undo_list, cifra)
        print("S-au sters " + str(nr_produse) + " produse din lista.")

    def undo(self):
        """
            Se realizeaza undo la ultima operatie de stergere efectuata.
        """
        self.__produs_service.undo(self.__undo_list)

    def filtrare(self):
        print("Criteriile de filtare actuale sunt: ")
        print("    - text: " + str(self.__text) )
        print("    - pret: " + str(self.__pret))
        if self.__pret == -1:
            produse = self.__produs_service.filtrareText(self.__text)
        elif self.__text == '':
            produse = self.__produs_service.filtrarePret(self.__pret)
        else:
            produse = self.__produs_service.filtrareTextPret(self.__text,self.__pret)
        if len(produse) == 0:
            print("Nu exista produse care sa indeplineasca criteriile date! ")
        else:
            print("Produsele care indeplinesc criteriile date sunt:" )
            for produs in produse:
                print(produs)

    def modificare_criterii(self):
        self.__text = input("Introduceti textul dorit: ")
        pret_introdus = input("Introduceti pretul dorit: ")
        self.__pret = int(pret_introdus)

    def menu(self):
        """
           Afisam meniul aplicatiei.
        """
        print("---------------------------------------------------------------------------")
        print("0. Iesirea din aplicatie.")
        print("1. Adaugare produs in lista.")
        print("2. Stergere produse care contin in pret cifra data de la tastatura.")
        print("3. Modificare criterii filtrare produse.")
        print("    - Daca textul introdus este sir vid => nu se mai doreste filtrare si in functie de denumire.")
        print("    - Daca pretul introdus este -1 => nu se mai doreste filtrarea si in functie de pret.")
        print("4. Undo ultima operatie de stergere.")
        print("---------------------------------------------------------------------------")

    def run(self):
        """
            Se realizeaza rularea aplicatiei.
        """
        self.menu()
        dictionary_of_commands = {
            "1" : self.addProdus,
            "2" : self.deleteProdus,
            "3" : self.modificare_criterii,
            "4" : self.undo
        }
        while True:
            command = input("Introduceti optiunea dorita: ")
            if command in dictionary_of_commands:
                try:
                    dictionary_of_commands[command]()
                except RepoException as ex:
                    print(ex)
                except ServiceException as ex:
                    print(ex)
                except ValueError:
                    print("Valoarea introdusa trebuie sa fie de tip integer!!")
                self.filtrare()
                self.menu()
            elif command == "0":
                self.filtrare()
                break
            else:
                print("Optiunea introdusa nu exista!!")