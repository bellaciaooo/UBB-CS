def nprim():
    """
    Afiseaza cel mai mare număr prim mai mic decât un număr dat.
    """
    n = int(input("dati un numar:"))
    ok = False
    while not ok:
        n = n + 1
        ok = True
        for i in range(2, n // 2):
            if n % i == 0:
                ok = False
    print(n)
    return


def fibo():
    """
     Găsește cel mai mic număr m din șirul lui Fibonacci definit de
    f[0]=f[1]=1, f[n]=f[n-1]+f[n-2], pentru n>2,
    mai mare decât numărul natural n dat, deci exista k astfel ca f[k]=m si m>n.
    """
    n = int(input("dati un numar:"))
    a = 0
    b = 1
    c = 1
    while c <= n:
        a = b
        b = c
        c = a + b
    print(c)
    return



