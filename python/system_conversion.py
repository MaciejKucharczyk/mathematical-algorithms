import random
import string

class SystemConversion:
    def __init__(self, number):
        self.number = number

    def dec_to_oct(dec_num):
        result =[]
        r=0
        number=dec_num
        while(number!=0):
            r=number%8
            number=number//8
            _r=str(r)
            result.append(_r)
        result.reverse()
        return ''.join(result)

    def dec_to_bin(dec_num):
        result = []
        r=0
        number=dec_num

        while(number!=0):
            r=number%2
            number=number//2
            _r=str(r)
            result.append(_r)
        
        result.reverse()
        return ''.join(result)

    def dec_to_hex(dec_num)->string:     
        result = []
        r=0
        number = dec_num
        while(number!=0):
            r=number % 16
            number = number//16
            # jesli reszta z dzielenia wieksza niz 9, dodaj litere to wyniku
            if(r>9):
                match r:
                    case 10:
                        result.append('A')
                    case 11:
                        result.append('B')
                    case 12:
                        result.append('C')
                    case 13:
                        result.append('D')
                    case 14:
                        result.append('E')
                    case 15:
                        result.append('F')
            else:
                _r=str(r)
                result.append(_r)
        result.reverse()
        result2 = ''.join(result)
        return result2

    def bin_to_dec(bin_num)->int:
        r=0
        result=0
        weight=1
        while(bin_num!=0):
            r=bin_num%2
            result =result + r*weight
            weight=2*weight
            bin_num=bin_num//10
        return result

    def bin_to_hex(bin_num)->string:
        number=SystemConversion.bin_to_dec(bin_num)
        result=SystemConversion.dec_to_hex(number)
        return result

    def hex_to_bin(hex_num)->string:
        result = []
        for i in range(len(hex_num)):
            match hex_num[i]:
                case '0':
                    result.append('0000')
                case '1':
                    result.append('0001')
                case '2':
                    result.append('0010')
                case '3':
                    result.append('0011')
                case '4':
                    result.append('0100')
                case '5':
                    result.append('0101')
                case '6':
                    result.append('0110')
                case '7':
                    result.append('0111')
                case '8':
                    result.append('1000')
                case '9':
                    result.append('1001')
                case 'A':
                    result.append('1010')
                case 'B':
                    result.append('1011')
                case 'C':
                    result.append('1100')
                case 'D':
                    result.append('1101')
                case 'E':
                    result.append('1110')
                case 'F':
                    result.append('1111')
        return ''.join(result)

    def hex_to_dec(hex_num):
        _number=SystemConversion.hex_to_bin(hex_num)
        number=int(_number)
        result=SystemConversion.bin_to_dec(number)
        return result