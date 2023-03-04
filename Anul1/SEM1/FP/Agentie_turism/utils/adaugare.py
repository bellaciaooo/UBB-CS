from Agentie_turism.domain.Read_functions import *

def add_pachet(pachete, pachet_nou):
    """
    Se adauga in lista noul pachet de calatorii
    :param pachete: lista curenta
    :param pachet_nou: pachetul de calatorii adaugat in lista
    """
    pachete.append(pachet_nou)

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

        