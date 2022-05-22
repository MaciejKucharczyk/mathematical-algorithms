from tracemalloc import stop
import system_conversion
import algorithms
import generator
import time

def main():
    start=0
    stop =0
    iterator = 100

    print("==== Pomiary ====")
    print("Wybierz opcje:\n")
    print("1. Ciag fibbonaciego")
    print("2. Najwiekszy wspolny dzielnik")
    print("3. dec -> bin")
    print("4. dec -> hex")
    print("5. bin -> hex")
    print("6. bin -> dec")
    print("7. hex -> dec")
    print("8. hex -> bin")
    print("0. Wyjscie")

    option = 1

    while(option!=0):
        option = input("Wybierz opcje:")
        match option:
            case '1':
                print("         CIAG FIBBONACIEGO")
                num=int(input("Wprowadz numer wyrazu ciagu: "))
                avg_fibb=0
                for i in range(iterator):
                    start = time.time_ns()
                    algorithms.Algorithms.fibb(num)
                    stop = time.time_ns()
                    fibb_time=stop - start
                    avg_fibb=avg_fibb+fibb_time
                avg_fibb=avg_fibb/iterator
                print("Sredni czas: "+ str(avg_fibb) + " ns")

            case '2':
                print("         NWD")
                a=int(input("Wprowadz a: "))
                b = int(input("Wprowadz b: "))
                avg_nwd=0
                for i in range(iterator):
                    start = time.time_ns()
                    algorithms.Algorithms.nwd(a,b)
                    stop=time.time_ns()
                    nwd_time = stop - start
                    avg_nwd=avg_nwd+nwd_time
                avg_nwd=avg_nwd/iterator
                print("Sredni czas: "+ str(avg_nwd) + " ns")

            case '3':
                print("         KONWERSJA DEC -> BIN")
                print("Wprowadz przedzial, w ktorym ma sie znajdowac liczba decymalna:")
                min=int(input("min = "))
                max=int(input("max = "))
                avg_dec_bin=0
                for i in range(iterator):
                    number = generator.Generator.random_decimal(min, max)
                    start = time.time_ns()
                    system_conversion.SystemConversion.dec_to_bin(number)
                    stop = time.time_ns()
                    dec_bin_time=stop-start
                    avg_dec_bin=avg_dec_bin+dec_bin_time
                avg_dec_bin=avg_dec_bin/iterator
                print("Czas: "+ str(avg_dec_bin) + " ns")

            case '4':
                print("         KONWERSJA DEC -> HEX")
                print("Wprowadz przedzial, w ktorym ma sie znajdowac liczba decymalna:")
                min=int(input("min = "))
                max=int(input("max = "))
                avg_dec_hex=0
                for i in range(iterator):
                    number = generator.Generator.random_decimal(min, max)
                    start = time.time_ns()
                    system_conversion.SystemConversion.dec_to_hex(number)
                    stop = time.time_ns()
                    dec_hex_time=stop-start
                    avg_dec_hex=avg_dec_hex+dec_hex_time
                avg_dec_hex=avg_dec_hex/iterator
                print("Czas: "+ str(avg_dec_hex) + " ns")

            case '5':
                print("         KONWERSJA BIN -> HEX")
                print("Wprowadz ilosc bitow liczby binarnej:")
                size=int(input("rozmair = "))
                avg_bin_hex=0
                for i in range(iterator):
                    number = generator.Generator.random_binary(size)
                    start = time.time_ns()
                    system_conversion.SystemConversion.bin_to_hex(number)
                    stop = time.time_ns()
                    bin_hex_time=stop-start
                    avg_bin_hex=avg_bin_hex+bin_hex_time
                avg_bin_hex=avg_bin_hex/iterator
                print("Czas: "+ str(avg_bin_hex) + " ns")

            case '6':
                print("         KONWERSJA BIN -> DEC")
                print("Wprowadz ilosc bitow liczby binarnej:")
                size=int(input("rozmiar = "))
                avg_bin_dec=0
                for i in range(iterator):
                    number = generator.Generator.random_binary(size)
                    start = time.time_ns()
                    system_conversion.SystemConversion.bin_to_dec(number)
                    stop = time.time_ns()
                    bin_dec_time=stop-start
                    avg_bin_dec=avg_bin_dec + bin_dec_time
                avg_bin_dec=avg_bin_dec/iterator
                print("Czas: "+ str(avg_bin_dec) + " ns")

            case '7':
                print("         KONWERSJA HEX -> DEC")
                print("Wprowadz ilosc cyfr liczby heksadecymalnej:")
                size=int(input("rozmiar = "))
                avg_hex_dec=0
                for i in range(iterator):
                    number = generator.Generator.random_hexadecimal(size)
                    start = time.time_ns()
                    system_conversion.SystemConversion.hex_to_dec(number)
                    stop = time.time_ns()
                    hex_dec_time=stop-start
                    avg_hex_dec=avg_hex_dec+hex_dec_time
                avg_hex_dec=avg_hex_dec/iterator
                print("Czas: "+ str(avg_hex_dec) + " ns")

            case '8': 
                print("         KONWERSJA HEX -> BIN")
                print("Wprowadz ilosc cyfr liczby heksadecymalnej:")
                size=int(input("rozmiar = "))
                avg_hex_bin=0
                for i in range(iterator):
                    number = generator.Generator.random_hexadecimal(size)
                    start = time.time_ns()
                    system_conversion.SystemConversion.hex_to_bin(number)
                    stop = time.time_ns()
                    hex_bin_time=stop-start
                    avg_hex_bin=avg_hex_bin+hex_bin_time
                avg_hex_bin=avg_hex_bin/iterator
                print("Czas: "+ str(avg_hex_bin) + " ns")

            case _:
                return
    return

main()