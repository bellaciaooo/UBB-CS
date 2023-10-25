from Agentie_turism.domain.Getters import *

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