from Agentie_turism.domain.Getters import *

def oferte_pentru_destinatie_data(pachete, destinatia_data):
    """
    Selecteaza pachetele (elementele) din lista data in functie de criteriul ales (destinatia data)
    :param pachete: lista data
    :param destinatia_data: criteriul de selectie
    :return: elementele care indeplinesc conditia impusa
    """
    return list(filter(lambda f: get_destinatia(f) == destinatia_data, pachete))

def medie_pret_pachete(pachete):
    suma = 0
    if len(pachete)!=0:
        for elem in pachete:
            suma = suma + elem['pret']
        return float(suma/len(pachete))
    return 0