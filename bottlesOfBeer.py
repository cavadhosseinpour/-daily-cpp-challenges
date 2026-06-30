def bottlesOfBeer(num):
    i = num
    while i > 0:
        print(f"{i} bottles of beer on the wall,")
        print(f"{i} bottles of beer,")
        print("Take one down,")
        print("Pass it around,")
        if (i - 1) != 0:
            print(f"{i - 1} bottles of beer on the wall,")
        else:
            print("No more bottles of beer on the wall.")
        print("\n")
        i -= 1


def main():
    bottlesOfBeer(99)


main()