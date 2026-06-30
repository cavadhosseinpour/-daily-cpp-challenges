def main():
    writeToFile("text_py.txt", "Hello!")
    appendToFile("text_py.txt", "Goodbye!")
    print(readFromFile("text_py.txt"))


def writeToFile(file_name, text):
    with  open(file_name, "w") as file:
        print(text)


def appendToFile(file_name, text):
    with open(file_name, "a") as file:
        print(text)


def readFromFile(file_name):
    with open(file_name, "r") as file:
        return file.read()
    
if __name__ == "__main__":
    main()