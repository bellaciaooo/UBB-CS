import datetime

def read_data(prompt="Introduceti data calendaristica in format AAAA/ll/zz: "):
    """
    Citeste si analizeaza un obiect de data din consola si verifica ca acesta a fost introdus in formatul corect
    :param prompt: Textul afisat in consola
    :return: data calendaristica
    """
    while True:
        try:
            data_introdusa = input(prompt)
            if datetime.datetime.strptime(data_introdusa, "%Y/%m/%d"):
                return datetime.datetime.strptime(data_introdusa, "%Y/%m/%d")
        except ValueError:
            print("Data introdusa nu este valida")

def read_destinatie():
    """
    Citeste si analizeaza un obiect de data din consola si verifica ca acesta a fost introdus in formatul corect
    :return: destinatia pachetului
    """
    while True:
        try:
            destinatia_introdusa = input("Introduceti o destinatie: ")
            return destinatia_introdusa
        except ValueError:
            print("Destinatia introdusa nu este valida")

def read_pret():
    """
    Citeste si analizeaza un obiect de data din consola si verifica ca acesta a fost introdus in formatul corect
    :return: pretul pachetului
    """
    while True:
        try:
            pretul_introdus = input("Introduceti un pret: ")
            return float(pretul_introdus)
        except ValueError:
            print("Pretul introdus nu este valid")

def read_pachet():
    """
    Citeste o entitate de tip pachet din consola
    :return: datele unui nou pachet de calatorii
    """
    data_inc = read_data("Introduceti data de inceput a calatoriei in format AAAA/ll/zz: ")
    data_sf = read_data("Introduceti data de sfarsit a calatoriei in format AAAA/ll/zz: ")
    destinatia = read_destinatie()
    pret = read_pret()
    return dict(data_inc = data_inc, data_sf = data_sf, destinatia = destinatia, pret = pret)

def read_suma():
    """
        Citeste si analizeaza un obiect de data din consola si verifica ca acesta a fost introdus in formatul corect
        :return: suma introdusa de la tastatura
    """
    while True:
        try:
            suma_introdusa = input("Introduceti o suma: ")
            return float(suma_introdusa)
        except ValueError:
            print("Suma introdusa nu este valida")

def read_optiune():
    """
        Citeste si analizeaza un obiect de data din consola si verifica ca acesta a fost introdus in formatul corect
        :return: optiunea introdusa de la tastatura
    """
    while True:
        try:
            optiunea_introdusa = input("Introduceti o optiune: ")
            return int(optiunea_introdusa)
        except ValueError:
            print("Optiunea introdusa nu este valida")

def read_optiune_consola2():
    """
            Citeste si analizeaza un obiect de data din consola si verifica ca acesta a fost introdus in formatul corect
            :return: optiunea introdusa de la tastatura
    """
    while True:
        try:
            optiune = input("Introduceti o optiune: ")
            optiune = optiune.split()
            if len(optiune):
                if optiune[0] == 'adauga' and len(optiune) > 1:
                    if str(optiune[1]) and len(optiune) > 2:
                        if float(optiune[2]) and len(optiune) > 3:
                            if datetime.datetime.strptime(optiune[3],"%Y/%m/%d") and len(optiune) > 4:
                                if datetime.datetime.strptime(optiune[4], "%Y/%m/%d"):
                                    return optiune
                elif optiune[0] == 'sterge' and len(optiune) > 1:
                    if str(optiune[1]):
                        return optiune
                elif optiune[0] == 'cauta' and len(optiune) > 1:
                    if str(optiune[1]) and len(optiune) > 2:
                        if float(optiune[2]):
                            return optiune
                elif optiune[0] == 'raport' and len(optiune) > 1:
                    if str(optiune[1]):
                        return optiune
                elif optiune[0] == 'iesire':
                    return optiune
                else:
                    print("Optiunea introdusa nu este corecta!!!")
        except ValueError:
                print("Optiunea introdusa nu este corecta!!!")

def read_nr_pachet():
    """
        Citeste si analizeaza un obiect de data din consola si verifica ca acesta a fost introdus in formatul corect
        :return: numarul de pachet introdus de la tastatura
    """
    while True:
        try:
            nr_pachet = input("Introduceti numarul de pachet: ")
            return int(nr_pachet)
        except ValueError:
            print("Numarul de pachet introdus nu este valid")

def read_alegere():
    """
    Verifica daca alegerea de la tastatura a fost scrisa corespunzator
    :return: alegerea corespunzatoare
    """
    while True:
        try:
            alegere = input('Introduceti "destinatia" daca doriti sa modificati destinatia pachetului sau "pret" daca doriti sa modificati pretul: ')
            if alegere == 'destinatia' or alegere == 'pret':
                return alegere
            else:
                print("Alegerea introdusa nu exista!")
        except ValueError:
            print("Alegerea introdusa nu exista!")

def read_nr_zile():
    """
    Citeste si analizeaza un obiect de data din consola si verifica ca acesta a fost introdus in formatul corect
    :return: numarul de zile introdus de la tastatura de catre utilizator
    """
    while True:
        try:
            nr_zile = input("Introduceti numarul de zile: ")
            return int(nr_zile)
        except ValueError:
            print("Numarul de zile introdus nu este valid")

def read_luna():
    """
    Citeste si analizeaza un obiect de data din consola si verifica ca acesta a fost introdus in formatul corect
    :return: luna introdusa de la tastatura de catre utilizator
    """
    while True:
        try:
            luna_citita = input("Introduceti luna: ")
            return int(luna_citita)
        except ValueError:
            print("Luna introdusa nu este valida")

