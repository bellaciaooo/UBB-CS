
from Agentie_turism.utils.adaugare import *
from Agentie_turism.utils.undo import *
from Agentie_turism.ui.UiMenu import *
from Agentie_turism.ui.Display import *
from Agentie_turism.Teste.teste_rulare import *

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

start()
rulare_teste()