import datetime

from Agentie_turism.utils.cautare import *
from Agentie_turism.utils.filtrare import *
from Agentie_turism.utils.rapoarte import *
from Agentie_turism.utils.stergere import *

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
