def findAndReplace(string, old, new):
    if len(string) == 0 or len(old) == 0 or len(new) == 0:
        return "Not a valid request!"
    replaced_string = ""
    i = 0
    while i < len(string):
        if string[i : i + len(old)] == old:
            replaced_string += new
            i += len(old)
        else:
            replaced_string += string[i]
            i += 1
    return replaced_string
def main():
    print(findAndReplace("The Dog", "Dog", "Cat"))

main()