import random

class Generator:

    def __init__(self):
        ""

    def random_decimal(min, max)-> int:
        number = random.randint(min ,max)
        return number

    def random_binary(size):
        number = []
        number.append('1')
        for i in range(size-1):
            temp = random.randint(0,1)
            _temp=str(temp)
            number.append(_temp)
        _number="".join(number)
        result=int(_number)
        return result

    def random_hexadecimal(size):
        number = []
        number.append(str(random.choice([1, 2, 3, 4, 5, 6, 7, 8, 9, 'A', 'B', 'C', 'D', 'E', 'F'])))
        for i in range(size-1):
            temp = str(random.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'A', 'B', 'C', 'D', 'E', 'F']))
            number.append(temp)
        return number