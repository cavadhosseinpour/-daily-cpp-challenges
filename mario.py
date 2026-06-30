def pyramid(num):
    if num > 8 or num < 1:
        print("Not a valid input")
    else:
        for i in range(1, num + 1, 1):
            print((" " * (num - i)) + ("#" * i), end=' ')
            print(("#" * i) + (" " * (num - i)))


def main():
    num = int(input("Enter pyramid heigh: "))
    pyramid(num)


main()