from Agentie_turism.domain.Getters import *

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
