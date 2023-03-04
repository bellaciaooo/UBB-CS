"""
  Scrieti o aplicatie care are interfata utilizator tip consola cu meniu.
 Aplicatia ofera urmatoarele functionalitati:
 1.Citeste de la tastatura o lista de numere intregi
 2.Gaseste secventa de lungime maxima care respectă proprietatea x[i] < x[i+1] < ... < x[i+p]
 3.Gaseste secventa de lungime maxima care respectă proprietatea ca oricare doua elemente
  consecutive difera printr-un numar prim
 4.Gaseste secventa de lungime maxima care respectă proprietatea ca au toate elementele
 in intervalul [0, 10] dat
 5.Iesire din aplicatie
"""

def print_menu():
    print("1.Citeste de la tastatura o lista de numere intregi")
    print("2.Secventa de lungime maxima care respectă proprietatea x[i] < x[i+1] < ... < x[i+p] este:")
    print("3.Secventa de lungime maxima care respectă proprietatea ca oricare doua elemente consecutive difera printr-un numar prim este:")
    print("4.Secventa de lungime maxima care respectă proprietatea ca au toate elementele in intervalul [0, 10] dat")
    print("5.Iesire din aplicatie")

def secv_max1(elem):
    inc=0
    fin=0
    imax=0
    fmax=0
    lmax=0
    lc=1
    for i in range(len(elem)-1):
        if elem[i+1]<=elem[i]:
            inc=i+1
            fin=i+1
            lc=1
        else:
            fin+=1
            lc+=1
            if lc>lmax:
                lmax=lc
                imax=inc
                fmax=fin
    while imax <= fmax:
        print(elem[imax], end=' ')
        imax+=1
    print(' ')

def is_prime(n):
    if n == 1 or n == 0:
        return 0
    for i in range(2, n//2+1):
        if n%i == 0:
            return 0
    return 1

def secv_max2(elem):
    inc=0
    fin=0
    imax=0
    fmax=0
    lmax=0
    lc=1
    for i in range(len(elem)-1):
        if is_prime(abs(elem[i+1]-elem[i])) != 1:
            inc=i+1
            fin=i+1
            lc=1
        else:
            fin+=1
            lc+=1
            if lc>lmax:
                lmax=lc
                imax=inc
                fmax=fin
    while imax <= fmax:
        print(elem[imax], end=' ')
        imax+=1
    print(' ')

def secv_max3(elem):
    inc=0
    imax=0
    lmax=0
    lc=0
    for i in range(len(elem)):
        if elem[i] >= 0 and elem[i] <= 10:
            lc += 1
            if lc > lmax:
                lmax = lc
                imax = inc
        else:
            inc=i+1
            lc=0
    n=0
    while n<lmax:
        print(elem[imax+n], end=' ')
        n+=1
    print(' ')

def read_list():
    the_list = input("Dati lista de numere intregi: ").split(" ")
    the_list = [int(x) for x in the_list]
    return the_list


def populate_list(the_list):
    """
    Populeaza lista data cu o serie de numere predefinite
    """
    the_list.append(6)
    the_list.append(2)
    the_list.append(3)
    the_list.append(1)
    the_list.append(5)


def start():
    current_list = []
    populate_list(current_list)
    while True:
        print_menu()
        print("Lista curenta este: ",current_list)
        option = int(input("Optiunea dumneavoastra este:"))
        if option == 1:
            current_list = read_list()
            print("Lista citita este: ", current_list)
        elif option == 2:
            secv_max1(current_list)
        elif option == 3:
            secv_max2(current_list)
        elif option == 4:
            secv_max3(current_list)
        elif option == 5:
            break

start()