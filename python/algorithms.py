class Algorithms:

    def __init__(self):
        ""

    def nwd(a, b)-> int:
        while b:
            a, b = b, a%b
        return a

    def fibb(n) -> int:
        result = 1
        a0 = 0
        a1 = 1
        a_n = 1
        if(n<1):
            return result
        else:
            while(a_n!=n):
                result = a0 + a1
                a0 = a1
                a1 = result
                a_n+=1
            return result

wynik = Algorithms.fibb(3)
print(wynik)
