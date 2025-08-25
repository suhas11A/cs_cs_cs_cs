x = 10
y = 5

if x > 5:
    if y > 3:
        print("Printing A")
    else:
        print("Printing B")
elif x > 3:
    if y > 4:
        print("Printing C")
    elif y > 2:
        print("Printing D")
    else:
        print("Printing E")
else:
    print("Printing F")