def commaFormat(number):
    strNum = str(number)
    if '.' in strNum:
        dotIndex = strNum.index('.')
        fractional = strNum[dotIndex:]
        strNum = strNum[:dotIndex]
    else:
        fractional = ''

    result = ''
    count = 0
    for i in range(len(strNum) - 1, -1, -1):
        if count == 3 and i != len(strNum) - 1:
            result = ',' + result
            count = 0

        result = strNum[i] + result
        count +=1
    return result + fractional


def main():
    print(commaFormat(1234567.1234567))


main()