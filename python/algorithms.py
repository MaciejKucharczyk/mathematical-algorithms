def nwd(a, b)-> int:
    while b:
        a, b = b, a%b
    return a

def fibb(n) -> int:
    result = 1
    a0 = 0
    a1 = 1
    a_n = 2
    if(n<=2):
        return result
    else:
        while(a_n!=n):
            result = a0 + a1
            a0 = a1
            a1 = result
            a_n+=1
        return result
