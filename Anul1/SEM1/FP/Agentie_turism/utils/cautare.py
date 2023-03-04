from Agentie_turism.domain.Getters import *

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