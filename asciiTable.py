def asciiTable(begin,end):
    for i in range(begin,end+1,1):
        print(i, chr(i))


asciiTable(32,126)