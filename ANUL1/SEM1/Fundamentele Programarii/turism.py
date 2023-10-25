"""
Creați o aplicație pentru gestiunea pachetelor de călătorie oferite de o agenție de
turism. Aplicația stochează pachete de călătorie oferite clienților după cum
urmează: data de început și cea de sfârșit a călătoriei, destinația și prețul.
"""
from dataclasses import dataclass
import datetime

@dataclass
class pachet:
    """
    Cream o structura de date potrivita
    """
    data_inc: datetime.datetime
    data_sf: datetime.datetime
    destinatia: str
    pret: float

""" 
 Transformam in lista de dictionare 
 pachete = [ { 'data_inc' : '2021/12/11, 'data_sf' : '2021/12/15 , 'destinatia' : 'Paris' , 'pret'= '450'} 
             { 'data_inc' : '2021/12/19, 'data_sf' : '2021/12/24 , 'destinatia' : 'Roma' , 'pret'= '800'}
           ]
"""

def get_data_inc(pachet):
    """
    Acceseaza un anumit field al dictionarului
    :param pachet: dictionarul primit
    :return: data de inceput a pachetului de calatorie ales
    """
    return pachet['data_inc']

def get_data_sf(pachet):
    """
    Acceseaza un anumit field al dictionarului
    :param pachet: dictionarul primit
    :return: data de sfarsit a pachetului de calatorie ales
    """
    return pachet['data_sf']

def get_destinatia(pachet):
    """
    Acceseaza un anumit field al dictionarului
    :param pachet: dictionarul primit
    :return: destinatia pachetului de calatorie ales
    """
    return pachet['destinatia']

def get_pret(pachet):
    """
    Acceseaza un anumit field al dictionarului
    :param pachet: dictionarul primit
    :return: pretul pachetului de calatorie ales
    """
    return pachet['pret']

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

def add_pachet(pachete, pachet_nou):
    """
    Se adauga in lista noul pachet de calatorii
    :param pachete: lista curenta
    :param pachet_nou: pachetul de calatorii adaugat in lista
    """
    pachete.append(pachet_nou)

def display_pachete(pachete):
    """
    Afiseaza elementele din lista data
    :param pachete: lista data
    """
    for pachet in pachete:
        print(pachet)

def modif_pachet(pachete, nr_pachet, alegere):
    """
    Se modifica specificatia aleasa de utilizator din consola
    :param pachete: lista data de pachete de calatorie
    :param nr_pachet: pachetul (elementul) din lista data care se modifica
    :param alegere: specificatia care se va modifica
    :return:
    """
    if alegere == 'destinatia':
        destinatia_noua = read_destinatie()
        pachete[nr_pachet]["destinatia"] = destinatia_noua
    else:
        pret_nou = read_pret()
        pachete[nr_pachet]["pret"] = pret_nou

def pachete_dupa_destinatie(pachete, destinatia_data):
    """
    Selecteaza pachetele (elementele) din lista in functie de destinatia data, sa fie diferite de aceasta
    :param pachete: lista data
    :param destinatia_data: criteriul de selectie
    :return: elementele care indeplinesc conditia
    """
    return list(filter(lambda f: get_destinatia(f) != destinatia_data, pachete))

def pachete_cu_durata_mai_mare_sau_egala_cu_un_nr_de_zile_dat(pachete, nr_zile):
    """
    Selecteaza pachetele (elementele) din lista data in functie de numarul de zile introdus
    :param pachete: lista data
    :param nr_zile: criteriul de selectie
    :return: elementele care indeplinesc conditia
    """
    return list(filter(lambda f: get_data_sf(f).day - get_data_inc(f).day + 1 >= nr_zile, pachete))

def pachete_cu_pretul_mai_mic_decat_suma_data(pachete, suma_data):
    """
    Selecteaza pachetele (elementele) din lista data in functie de suma data
    :param pachete: lista data
    :param suma_data: criteriul de selectie
    :return: elementele care indeplinesc conditia
    """
    return list(filter(lambda f: get_pret(f) <= suma_data, pachete))

def tip_pachete_intre_anumite_date(pachete, data_inceput, data_sfarsit):
    """
    Selecteaza pachetele (elementele) din lista data in functie de data de inceput si de sfarsit a sejurului
    :param pachete: lista data
    :param data_inceput: primul criteriu de selectie
    :param data_sfarsit: al doilea criteriu de selectie
    :return: elementele care indeplinesc conditiile
    """
    return list(filter(lambda f: get_data_inc(f) >= data_inceput and get_data_sf(f) <= data_sfarsit, pachete))

def tip_pachete_pentru_destinatie_data_si_pret_mai_mic_decat_suma_data(pachete, destinatia_data, suma_data):
    """
    Selecteaza pachetele (elementele) din lista data in functie de criteriile alese (suma si destinatia)
    :param pachete: lista data
    :param destinatia_data: primul criteriu de selectie
    :param suma_data: al doilea criteriu de selectie
    :return: elementele care indeplinesc conditiile date
    """
    return list(filter(lambda f: get_destinatia(f) == destinatia_data and  get_pret(f) < suma_data, pachete))

def tip_pachete_cu_anumita_data_de_sfarsit(pachete,data_sfarsit):
    """
    Selecteaza pachetele (elementele) din lista data in functie de criteriul ales (data de sfarsit a calatoriei)
    :param pachete: lista data
    :param data_sfarsit: criteriul de selectie
    :return: elementele care indeplinesc conditia impusa
    """
    return list(filter(lambda f: get_data_sf(f) == data_sfarsit, pachete))

def oferte_pentru_destinatie_data(pachete, destinatia_data):
    """
    Selecteaza pachetele (elementele) din lista data in functie de criteriul ales (destinatia data)
    :param pachete: lista data
    :param destinatia_data: criteriul de selectie
    :return: elementele care indeplinesc conditia impusa
    """
    return list(filter(lambda f: get_destinatia(f) == destinatia_data, pachete))

def oferte_cu_pret_mai_mic_sau_egal_decat_suma_data_si_destinatia_aceasi_fata_de_destinatia_data(pachete, suma_data, destinatia_data):
    """
    Selecteaza pachetele (elementele) din lista data in functie de criteriile alese (suma si destinatia)
    :param pachete: lista data
    :param suma_data: primul criteriu de selectie
    :param destinatia_data: al doilea criteriu de selectie
    :return: elementele care indeplinesc conditiile date
    """
    return list(filter(lambda f: get_pret(f) <= suma_data and get_destinatia(f) == destinatia_data, pachete))

def oferte_care_nu_sunt_in_luna_citita_de_la_tastatura(pachete, luna):
    """
    Selecteaza pachetele (elementele) din lista data in functie de criteriul ales (luna sa fie diferita de cea citita de la tastatura)
    :param pachete: lista data
    :param luna: criteriul de selectie
    :return:
    """
    return list(filter(lambda f: get_data_inc(f).month != luna and get_data_sf(f).month != luna, pachete))

def medie_pret_pachete(pachete):
    suma = 0
    if len(pachete)!=0:
        for elem in pachete:
            suma = suma + elem['pret']
        return float(suma/len(pachete))
    return 0


def make_copy(pachete):
    cpy = []
    for el in pachete:
        elem_curent = {}
        for key, value in el.items():
            elem_curent[key] = value
        cpy.append(elem_curent)

    return cpy

def save_for_undo( undo_list, pachete):
    """
    Salveaza starea curenta a listei din al doilea parametru pentru cand vom face undo 
    :param undo_list: starile predecente ale listei date
    :param pachete: lista data
    :return: 
    """
    undo_list.append(pachete)

def print_menu():
    print("1. Adaugă pachet de călătorie")
    print("2. Modifică pachet de călătorie")
    print("3. Ștergerea tuturor pachetelor de călătorie disponibile pentru o destinație dată")
    print("4. Ștergerea tuturor pachetelor de călătorie care au o durată mai scurtă decât un număr de zile dat")
    print("5. Ștergerea tuturor pachetelor de călătorie care au prețul mai mare decât o sumă dată")
    print("6. Tipărirea pachetelor de călătorie care presupun un sejur într-un interval dat (e.g. 10/08/2018 - 24/08/2018)")
    print("7. Tipărirea pachetelor de călătorie cu o destinație dată și cu preț mai mic decât o sumă dată.")
    print("8. Tipărirea pachetelor de călătorie cu o anumită dată de sfârșit")
    print("9. Tipărirea numărului de oferte pentru o destinație dată.")
    print("10. Tipărirea tuturor pachetelor disponibile într-o anumită perioadă citită de la tastatură în ordinea crescătoare a prețului.")
    print("11. Tipărirea mediei de preț pentru o destinație dată ")
    print("12. Eliminarea ofertelor care au un preț mai mare decât cel dat și o destinație diferită de cea citită de la tastatură")
    print("13. Eliminarea ofertelor în care sejurul presupune zile dintr-o anumită lună (citită de la tastatură sub forma unui număr natural între 1 și 12)")
    print("14. UNDO - Refacerea ultimei operații")
    print("15. Iesirea din aplicatie")

def test_stergere_pachete_destinatie_data():
    lista_pachete = [
        dict(data_inc=datetime.datetime(2021, 12, 11), data_sf=datetime.datetime(2021, 12, 17), destinatia='Paris',
               pret=470)]
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 11, 10), data_sf=datetime.datetime(2021, 11, 18), destinatia='Madrid',
               pret=500))
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 12, 10), data_sf=datetime.datetime(2021, 12, 14), destinatia='Paris',
               pret=620))
    destinatia_data = 'Paris'
    lista_pachete2 = [
        dict(data_inc=datetime.datetime(2021, 11, 10), data_sf=datetime.datetime(2021, 11, 18), destinatia='Madrid',
               pret=500)]
    lista_pachete = pachete_dupa_destinatie(lista_pachete, destinatia_data)
    assert lista_pachete[0] == lista_pachete2[0]

def test_stergere_pachete_dupa_durata_zile_data():
    lista_pachete = [
        dict(data_inc=datetime.datetime(2021, 12, 11), data_sf=datetime.datetime(2021, 12, 17), destinatia='Londra',
             pret=470.29)]
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 12, 10), data_sf=datetime.datetime(2021, 12, 14), destinatia='Cipru',
             pret=620.80))
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 11, 10), data_sf=datetime.datetime(2021, 11, 18), destinatia='Mamaia',
             pret=500))
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 12, 19), data_sf=datetime.datetime(2021, 12, 22), destinatia='Lampedusa',
             pret=321.45))
    lista_pachete2 = [
        dict(data_inc=datetime.datetime(2021, 12, 11), data_sf=datetime.datetime(2021, 12, 17), destinatia='Londra',
             pret=470.29)]
    lista_pachete2.append(
         dict(data_inc=datetime.datetime(2021, 11, 10), data_sf=datetime.datetime(2021, 11, 18), destinatia='Mamaia',
             pret=500))
    nr_zile = 7
    lista_pachete = pachete_cu_durata_mai_mare_sau_egala_cu_un_nr_de_zile_dat(lista_pachete, nr_zile)
    assert lista_pachete[0] == lista_pachete2[0]
    assert lista_pachete[1] == lista_pachete2[1]

def test_stergere_pachete_pret_mai_mare_suma_data():
    lista_pachete = [
        dict(data_inc=datetime.datetime(2021, 12, 11), data_sf=datetime.datetime(2021, 12, 17), destinatia='Miami',
               pret=470.29)]
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 11, 10), data_sf=datetime.datetime(2021, 11, 18), destinatia='Madrid',
               pret=500))
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 12, 10), data_sf=datetime.datetime(2021, 12, 14), destinatia='Oradea',
               pret=620.80))
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 12, 19), data_sf=datetime.datetime(2021, 12, 22), destinatia='Iasi',
               pret=321.45))
    suma_data = 490.78
    lista_pachete2 = [
        dict(data_inc=datetime.datetime(2021, 12, 11), data_sf=datetime.datetime(2021, 12, 17), destinatia='Miami',
               pret=470.29)]
    lista_pachete2.append(
        dict(data_inc=datetime.datetime(2021, 12, 19), data_sf=datetime.datetime(2021, 12, 22), destinatia='Iasi',
               pret=321.45))
    lista_pachete = pachete_cu_pretul_mai_mic_decat_suma_data(lista_pachete, suma_data)
    assert lista_pachete[0] == lista_pachete2[0]
    assert lista_pachete[1] == lista_pachete2[1]


def test_eliminare_oferte_dupa_pret_si_destinatie():
    lista_pachete = [
        dict(data_inc=datetime.datetime(2021, 12, 11), data_sf=datetime.datetime(2021, 12, 17), destinatia='Paris',
               pret=470.29)]
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 11, 10), data_sf=datetime.datetime(2021, 11, 18), destinatia='Madrid',
               pret=500))
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 12, 10), data_sf=datetime.datetime(2021, 12, 14), destinatia='Paris',
               pret=620.80))
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 12, 19), data_sf=datetime.datetime(2021, 12, 22), destinatia='Paris',
               pret=321.45))
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 12, 19), data_sf=datetime.datetime(2021, 12, 22), destinatia='Iasi',
               pret=390.95))
    suma_data = 480
    destinatia_data = 'Paris'
    lista_pachete = oferte_cu_pret_mai_mic_sau_egal_decat_suma_data_si_destinatia_aceasi_fata_de_destinatia_data(
        lista_pachete, suma_data, destinatia_data)
    lista_pachete2 = [
        dict(data_inc=datetime.datetime(2021, 12, 11), data_sf=datetime.datetime(2021, 12, 17), destinatia='Paris',
               pret=470.29)]
    lista_pachete2.append(
        dict(data_inc=datetime.datetime(2021, 12, 19), data_sf=datetime.datetime(2021, 12, 22), destinatia='Paris',
               pret=321.45))
    assert lista_pachete[0] == lista_pachete2[0]
    assert lista_pachete[1] == lista_pachete2[1]

def test_eliminare_oferte_dupa_luna_citita():
    lista_pachete = [
        dict(data_inc=datetime.datetime(2021, 11, 11), data_sf=datetime.datetime(2021, 12, 17), destinatia='Moldova',
             pret=470.29)]
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 12, 10), data_sf=datetime.datetime(2021, 12, 14), destinatia='Oradea',
             pret=620.80))
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 11, 10), data_sf=datetime.datetime(2021, 11, 18), destinatia='Madrid',
             pret=500))
    lista_pachete2 = [
        dict(data_inc=datetime.datetime(2021, 12, 10), data_sf=datetime.datetime(2021, 12, 14), destinatia='Oradea',
             pret=620.80)]
    luna_citita = 11
    lista_pachete = oferte_care_nu_sunt_in_luna_citita_de_la_tastatura(lista_pachete, luna_citita)
    assert lista_pachete[0] == lista_pachete2[0]

def test_rap_oferte_dupa_destinatie_data():
    lista_pachete = [
        dict(data_inc=datetime.datetime(2021, 12, 11), data_sf=datetime.datetime(2021, 12, 17), destinatia='Paris',
             pret=470.29)]
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 11, 10), data_sf=datetime.datetime(2021, 11, 18), destinatia='Madrid',
             pret=500))
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 12, 19), data_sf=datetime.datetime(2021, 12, 22), destinatia='Paris',
             pret=321.45))
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 12, 19), data_sf=datetime.datetime(2021, 12, 22), destinatia='Iasi',
             pret=390.95))
    lista_pachete2 = [
        dict(data_inc=datetime.datetime(2021, 12, 11), data_sf=datetime.datetime(2021, 12, 17), destinatia='Paris',
             pret=470.29)]
    lista_pachete2.append(
        dict(data_inc=datetime.datetime(2021, 12, 19), data_sf=datetime.datetime(2021, 12, 22), destinatia='Paris',
             pret=321.45))
    destinatia_data = 'Paris'
    lista_pachete = oferte_pentru_destinatie_data(lista_pachete, destinatia_data)
    assert lista_pachete[0] == lista_pachete2[0]
    assert lista_pachete[1] == lista_pachete2[1]

def test_modificare_pachet():
    lista_pachete = [
        dict(data_inc=datetime.datetime(2021, 12, 11), data_sf=datetime.datetime(2021, 12, 17), destinatia='Paris',
             pret=470.29)]
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 11, 10), data_sf=datetime.datetime(2021, 11, 18), destinatia='Madrid',
             pret=500))
    alegere = 'destinatia'
    nr_pachet = 0
    if alegere == 'destinatia':
        destinatia_noua = 'Roma'
        lista_pachete[nr_pachet]["destinatia"] = destinatia_noua
    else:
        pret_nou = 230.14
        lista_pachete[nr_pachet]["pret"] = pret_nou
    alegere = 'pret'
    nr_pachet = 1
    if alegere == 'destinatia':
        destinatia_noua = 'Roma'
        lista_pachete[nr_pachet]["destinatia"] = destinatia_noua
    else:
        pret_nou = 230.14
        lista_pachete[nr_pachet]["pret"] = pret_nou
    assert lista_pachete[0]["destinatia"] == 'Roma'
    assert lista_pachete[1]["pret"] == 230.14

def test_tip_pachete_intre_anumite_date():
    lista_pachete = [
        dict(data_inc=datetime.datetime(2021, 11, 24), data_sf=datetime.datetime(2021, 11, 29), destinatia='Paris',
             pret=470.29)]
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 11, 10), data_sf=datetime.datetime(2021, 11, 18), destinatia='Madrid',
             pret=500))
    lista_pachete2 = [
        dict(data_inc=datetime.datetime(2021, 11, 24), data_sf=datetime.datetime(2021, 11, 29), destinatia='Paris',
             pret=470.29)]
    data_inceput = datetime.datetime.strptime('2021/11/20', "%Y/%m/%d")
    data_sfarsit = datetime.datetime.strptime('2021/11/30', "%Y/%m/%d")
    lista_pachete = tip_pachete_intre_anumite_date(lista_pachete,data_inceput,data_sfarsit)
    assert lista_pachete[0] == lista_pachete2[0]

def test_tip_pachete_pentru_destinatie_si_pret_mai_mic():
    lista_pachete = [
        dict(data_inc=datetime.datetime(2021, 12, 11), data_sf=datetime.datetime(2021, 12, 17), destinatia='Paris',
             pret=470.29)]
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 11, 10), data_sf=datetime.datetime(2021, 11, 18), destinatia='Madrid',
             pret=500))
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 12, 10), data_sf=datetime.datetime(2021, 12, 14), destinatia='Paris',
             pret=620.80))
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 12, 19), data_sf=datetime.datetime(2021, 12, 22), destinatia='Paris',
             pret=321.45))
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 12, 19), data_sf=datetime.datetime(2021, 12, 22), destinatia='Iasi',
             pret=390.95))
    suma_data = 480
    destinatia_data = 'Paris'
    lista_pachete2 = [
        dict(data_inc=datetime.datetime(2021, 12, 11), data_sf=datetime.datetime(2021, 12, 17), destinatia='Paris',
             pret=470.29)]
    lista_pachete2.append(
        dict(data_inc=datetime.datetime(2021, 12, 19), data_sf=datetime.datetime(2021, 12, 22), destinatia='Paris',
             pret=321.45))
    lista_pachete = tip_pachete_pentru_destinatie_data_si_pret_mai_mic_decat_suma_data(lista_pachete, destinatia_data, suma_data)
    assert lista_pachete[0] == lista_pachete2[0]
    assert lista_pachete[1] == lista_pachete2[1]

def test_tip_pachete_pentru_anumita_data_sfarsit():
    lista_pachete = [
        dict(data_inc=datetime.datetime(2021, 11, 11), data_sf=datetime.datetime(2021, 12, 17), destinatia='Moldova',
             pret=470.29)]
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 12, 10), data_sf=datetime.datetime(2021, 12, 14), destinatia='Oradea',
             pret=620.80))
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 11, 10), data_sf=datetime.datetime(2021, 11, 18), destinatia='Madrid',
             pret=500))
    lista_pachete2 = [
        dict(data_inc=datetime.datetime(2021, 12, 10), data_sf=datetime.datetime(2021, 12, 14), destinatia='Oradea',
             pret=620.80)]
    data_sfarsit = datetime.datetime.strptime('2021/12/14', "%Y/%m/%d")
    lista_pachete = tip_pachete_cu_anumita_data_de_sfarsit(lista_pachete, data_sfarsit)
    assert lista_pachete[0] == lista_pachete2[0]

def test_media_pret():
    lista_pachete = [
        dict(data_inc=datetime.datetime(2021, 11, 11), data_sf=datetime.datetime(2021, 12, 17), destinatia='Moldova',
             pret=470)]
    lista_pachete.append(
        dict(data_inc=datetime.datetime(2021, 12, 10), data_sf=datetime.datetime(2021, 12, 14), destinatia='Oradea',
             pret=620.5))
    lista_pachete2 = []
    assert medie_pret_pachete(lista_pachete) == 545.25
    assert medie_pret_pachete(lista_pachete2) == 0

def rulare_teste():
    test_modificare_pachet()
    test_stergere_pachete_destinatie_data()
    test_stergere_pachete_dupa_durata_zile_data()
    test_stergere_pachete_pret_mai_mare_suma_data()
    test_tip_pachete_intre_anumite_date()
    test_tip_pachete_pentru_destinatie_si_pret_mai_mic()
    test_tip_pachete_pentru_anumita_data_sfarsit()
    test_rap_oferte_dupa_destinatie_data()
    test_eliminare_oferte_dupa_pret_si_destinatie()
    test_eliminare_oferte_dupa_luna_citita()
    test_media_pret()

def start():
    pachete = []
    undo_list = []
    while True:
        print( "--------------------------------------------------------------------------------------------------------------------------------------")
        print_menu()
        print("Pachetele de calatorie curente sunt:")
        display_pachete(pachete)
        print("--------------------------------------------------------------------------------------------------------------------------------------")
        option = read_optiune()
        if option == 1:
            save_for_undo(undo_list, make_copy(pachete))
            pachet_nou = read_pachet()
            add_pachet(pachete, pachet_nou)
        elif option == 2:
            save_for_undo(undo_list, make_copy(pachete))
            print('Alegeti pachetul pe care doriti sa il moficati, tinand cont ca numerotarea pachetelor incepe de la 0 ')
            nr_pachet = read_nr_pachet()
            alegere = read_alegere()
            modif_pachet(pachete,nr_pachet,alegere)
        elif option == 3:
            save_for_undo(undo_list, make_copy(pachete))
            destinatia_data = read_destinatie()
            pachete = pachete_dupa_destinatie(pachete, destinatia_data)
        elif option == 4:
            save_for_undo(undo_list, make_copy(pachete))
            nr_zile = read_nr_zile()
            pachete = pachete_cu_durata_mai_mare_sau_egala_cu_un_nr_de_zile_dat(pachete,nr_zile)
        elif option == 5:
            save_for_undo(undo_list, make_copy(pachete))
            suma_data = read_suma()
            pachete = pachete_cu_pretul_mai_mic_decat_suma_data(pachete, suma_data)
        elif option == 6:
            data_inceput = read_data("Introduceti data de inceput a calatoriei in format AAAA/ll/zz: ")
            data_sfarsit = read_data("Introduceti data de sfarsit a calatoriei in format AAAA/ll/zz: ")
            tiparire_pachete = tip_pachete_intre_anumite_date(pachete, data_inceput, data_sfarsit)
            print("Pachetele disponibile in perioada respectiva sunt: ")
            display_pachete(tiparire_pachete)
        elif option == 7:
            destinatia_data = read_destinatie()
            suma_data = read_suma()
            tiparire_pachete = tip_pachete_pentru_destinatie_data_si_pret_mai_mic_decat_suma_data(pachete, destinatia_data, suma_data)
            print("Pachetele disponibile cu destinația dată și cu preț mai mic decât suma dată sunt: ")
            display_pachete(tiparire_pachete)
        elif option == 8:
            data_sfarsit = read_data("Introduceti data de sfarsit a calatoriei in format AAAA/ll/zz: ")
            tiparire_pachete = tip_pachete_cu_anumita_data_de_sfarsit(pachete, data_sfarsit)
            print("Pachetele disponibile cu anumita data de sfarsit introdusa sunt: ")
            display_pachete(tiparire_pachete)
        elif option == 9:
            destinatia_data = read_destinatie()
            contor_pachete = oferte_pentru_destinatie_data(pachete, destinatia_data)
            print("Pentru destinatia introdusa sunt disponibile {} oferte".format(len(contor_pachete)))
        elif option == 10:
            data_inceput = read_data("Introduceti data de inceput a calatoriei in format AAAA/ll/zz: ")
            data_sfarsit = read_data("Introduceti data de sfarsit a calatoriei in format AAAA/ll/zz: ")
            pachete_perioada = tip_pachete_intre_anumite_date(pachete, data_inceput, data_sfarsit)
            print("Pachetele disponibile in perioada citita sunt: ")
            for elem in sorted(pachete_perioada, key = lambda i: i['pret']):
                print(elem)
        elif option == 11:
            destinatia_data = read_destinatie()
            pachete_destinatie = oferte_pentru_destinatie_data(pachete, destinatia_data)
            print("Media de pret pentru destinatia data este: ",medie_pret_pachete(pachete_destinatie))
        elif option == 12:
            save_for_undo(undo_list, make_copy(pachete))
            suma_data = read_suma()
            destinatia_data = read_destinatie()
            pachete = oferte_cu_pret_mai_mic_sau_egal_decat_suma_data_si_destinatia_aceasi_fata_de_destinatia_data(
                pachete, suma_data, destinatia_data)
        elif option == 13:
            save_for_undo(undo_list, make_copy(pachete))
            luna = read_luna()
            pachete = oferte_care_nu_sunt_in_luna_citita_de_la_tastatura(pachete, luna)
        elif option == 14:
            pachete = undo_list.pop()
        else:
            break

rulare_teste()
start()
