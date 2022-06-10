import time

value = 999868
filename = "SilniaPy.csv"

def AddToFile(filename, time)-> None:
    file = open(filename, "a")
    if file.writable():
        file.write(str(time))
        file.write('\n')
    file.close()

def silnia(val):
    result = 1
    i=1
    for _ in range(val):
        result = result*i
        i+=1
    return result

def main():
    file = open(filename, "a")
    if file.writable():
        file.write("Silnia dla: ")
        file.write(str(value))
        file.write('\n')
    file.close()

    for i in range(2):
        start = time.time_ns()
        silnia(value)
        stop = time.time_ns()
        time_of = stop - start
        AddToFile(filename, time_of)

main()