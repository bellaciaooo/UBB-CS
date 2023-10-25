"""
11) Se dau două numere naturale m şi n. Generaţi liste formate din numere de la 1 la n cu
proprietatea că diferenţa (în valoare absolută) între două numere consecutive din listă este
m. Tipăriţi un mesaj dacă problema nu are soluţie.
"""
############ BACKTRACKING RECURSIV ##############
def backtracking(lista_numere, n, m):
    if len(lista_numere) > n:
        return #stop recursion
    lista_numere.append(0)
    for i in range(1, n + 1):
        lista_numere[-1] = i
        if isSet(lista_numere,m):
        #continue only if lista_numere can conduct to a solution
            print(lista_numere)
            backtracking(lista_numere, n, m)
    lista_numere.pop()

def isSet(lista_numere, m):
    test_lista = set(lista_numere)
    if len(test_lista) != len(lista_numere):
        return False
    for i in range(0,len(lista_numere)-1):
        if abs(lista_numere[i]-lista_numere[i+1]) != m:
            return False
    return True

n = 6
m = 2
lista_numere = []
#backtracking(lista_numere,n,m)

############ BACKTRACKING ITERATIV ##############
def backIter(lista_numere, n, m):
    lista_numere = [0]  # candidate solution
    while len(lista_numere) > 0:
        choosen = False
        while not choosen and lista_numere[-1] < n:
            lista_numere[-1] = lista_numere[-1] + 1  # increase the last component
            if isSet(lista_numere,m):
                choosen = True
        if choosen:
            print(lista_numere)
            lista_numere.append(0)  # expand candidate solution
        else:
            lista_numere = lista_numere[:-1]  # go back one component

backIter(lista_numere, n, m)