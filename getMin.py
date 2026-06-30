def getMin(list=[]):
    if len(list) == 0: return None
    result = list[0]
    for i in range(len(list)):
        if list[i] < result:
            result = list[i]
    
    return result


def main():
    list = [6, 9, 1, 0, 3, 7]
    print(getMin(list))


main()