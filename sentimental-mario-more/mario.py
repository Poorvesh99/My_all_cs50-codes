# TODO
while True:
    try:
        h = int(input("Height: "))

        if h > 0 and h < 9:
            break
    except:
        pass


count = h - 1  # counter to give keep count of white spaces

for i in range(1, h + 1):

    print(" " * count, end="")

    print("#" * i, end="")  # actual hashes location
    print("  ", end="")  # inbetween whitespaces
    print("#" * i, end="")

    print()  # to declare end of line

    count -= 1