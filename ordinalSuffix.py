def ordinalSuffix(number):
    last_two_digits = number % 100
    last_one_digit = number % 10

    if last_two_digits in [11, 12, 13]:
        return f"{number}th"
    
    match last_one_digit:
        case 1: return f"{number}st"
        case 2: return f"{number}nd"
        case 3: return f"{number}rd"
        case _: return f"{number}th"

number = int(input("Enter your number: "))
print(ordinalSuffix(number))