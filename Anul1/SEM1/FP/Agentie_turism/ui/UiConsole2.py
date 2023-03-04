
from Agentie_turism.ui.Display import *
from Agentie_turism.ui.UiMenu import *
from Agentie_turism.utils.adaugare import *
from Agentie_turism.utils.cautare import *
from Agentie_turism.utils.rapoarte import *
from Agentie_turism.utils.stergere import *


def start():
    pachete = []
    while True:
        print(
            "--------------------------------------------------------------------------------------------------------------------------------------")
        print_menu2()
        print("Pachetele de calatorie curente sunt:")
        display_pachete(pachete)
        print(
            "--------------------------------------------------------------------------------------------------------------------------------------")
        option = read_optiune_consola2()
        if option[0] == 'adauga':
            add_pachet(pachete, dict(destinatia = str(option[1]), pret = float(option[2]), data_inc = datetime.datetime.strptime(option[3],"%Y/%m/%d"), data_sf = datetime.datetime.strptime(option[4],"%Y/%m/%d") ))
        elif option[0] == 'sterge':
            pachete = pachete_dupa_destinatie(pachete, option[1])
        elif option[0] == 'cauta':
            tiparire_pachete = tip_pachete_pentru_destinatie_data_si_pret_mai_mic_decat_suma_data(pachete,str(option[1]),float(option[2]))
            print("Pachetele disponibile cu destinația dată și cu preț mai mic decât suma dată sunt: ")
            display_pachete(tiparire_pachete)
        elif option[0] == 'raport':
            contor_pachete = oferte_pentru_destinatie_data(pachete, str(option[1]))
            print("Pentru destinatia introdusa sunt disponibile {} oferte".format(len(contor_pachete)))
        elif option[0] == 'iesire':
            break

start()
