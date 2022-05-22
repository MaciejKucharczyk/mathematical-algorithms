from tracemalloc import stop
import system_conversion
import algorithms
import generator
import time

def main():
    start=0
    stop =0

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

    option = input("Wybierz opcje:")

    while(option!=0):
        match option:
            case '1':
                print("         CIAG FIBBONACIEGO")
                num=int(input("Wprowadz numer wyrazu ciagu: "))
                avg_fibb=0
                for i in range(100):
                    start = time.time_ns()
                    algorithms.Algorithms.fibb(num)
                    stop = time.time_ns()
                    fibb_time=stop - start
                    avg_fibb=avg_fibb+fibb_time
                print("Sredni czas: "+ str(avg_fibb) + " ns")

            case '2':
                print("         NWD")
                a=input("Wprowadz a: ")
                b = input("Wprowadz b: ")
                start = time.time_ns()
                algorithms.Algorithms.nwd(a,b)
                nwd_time = stop - start
                print("Czas: "+ nwd_time + " ns")

            case '3':
                print("         KONWERSJA DEC -> BIN")
                print("Wprowadz przedzial, w ktorym ma sie znajdowac liczba decymalna:")
                min=input("min = ")
                max=input("max = ")
                number = generator.Generator.random_decimal(min, max)
                start = time.time_ns()
                system_conversion.SystemConversion.dec_to_bin(number)
                stop = time.time_ns()
                dec_bin_time=stop-start
                print("Czas: "+ dec_bin_time + " ns")

            case '4':
                print("         KONWERSJA DEC -> HEX")
                print("Wprowadz przedzial, w ktorym ma sie znajdowac liczba decymalna:")
                min=input("min = ")
                max=input("max = ")
                number = generator.Generator.random_decimal(min, max)
                start = time.time_ns()
                system_conversion.SystemConversion.dec_to_hex(number)
                stop = time.time_ns()
                dec_hex_time=stop-start
                print("Czas: "+ dec_hex_time + " ns")

            case '5':
                print("         KONWERSJA BIN -> HEX")
                print("Wprowadz ilosc bitow liczby binarnej:")
                size=input("rozmair = ")
                number = generator.Generator.random_binary(size)
                start = time.time_ns()
                system_conversion.SystemConversion.bin_to_hex(number)
                stop = time.time_ns()
                bin_hex_time=stop-start
                print("Czas: "+ bin_hex_time + " ns")

            case '6':
                print("         KONWERSJA BIN -> DEC")
                print("Wprowadz ilosc bitow liczby binarnej:")
                size=input("rozmiar = ")
                number = generator.Generator.random_binary(size)
                start = time.time_ns()
                system_conversion.SystemConversion.bin_to_dec(number)
                stop = time.time_ns()
                bin_dec_time=stop-start
                print("Czas: "+ bin_dec_time + " ns")

            case '7':
                print("         KONWERSJA HEX -> DEC")
                print("Wprowadz ilosc cyfr liczby heksadecymalnej:")
                size=input("rozmiar = ")
                number = generator.Generator.random_hexadecimal(size)
                start = time.time_ns()
                system_conversion.SystemConversion.hex_to_dec(number)
                stop = time.time_ns()
                hex_dec_time=stop-start
                print("Czas: "+ hex_dec_time + " ns")

            case '8': 
                print("         KONWERSJA HEX -> BIN")
                print("Wprowadz ilosc cyfr liczby heksadecymalnej:")
                size=input("rozmiar = ")
                number = generator.Generator.random_hexadecimal(size)
                start = time.time_ns()
                system_conversion.SystemConversion.hex_to_bin(number)
                stop = time.time_ns()
                bin_dec_time=stop-start
                print("Czas: "+ bin_dec_time + " ns")

            case _:
                return
        return

main()