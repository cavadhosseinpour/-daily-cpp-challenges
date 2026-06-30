def getChessSquareColor(i,j):
    if i < 1 or i > 7 or j < 1 or j > 7:
        print("Not a valid chess board square!")
    elif (i % 2 == 0 and j % 2 == 0) or (i % 2 != 0 and j % 2 != 0):
        print("white")
    else:
        print("black")


def main():
    i = int(input("Enter chess board number i: "))
    j = int(input("Enter chess board number j: "))
    getChessSquareColor(i,j)


main()