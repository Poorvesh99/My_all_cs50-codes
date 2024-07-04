# TODO
from cs50 import get_string
import re

number = get_string("Number: ")

# multiplication of alternate no . from back
check = 0
for i in number[-2::-2]:
    product = str(int(i)*2)
    for k in product:
        check += int(k)

# summing up remmaning digits
sum = 0
for j in number[-1::-2]:
    sum = sum + int(j)

# checking last digit of check_sum
check_sum = check + sum
if check_sum % 10 == 0:

    if len(number) == 16 and int(number[0]) == 5 and (int(number[1]) in [1, 2, 3, 4, 5]):
        print("MASTERCARD")
    elif len(number) == 15 and int(number[0]) == 3 and (int(number[1]) in [4, 7]):
        print("AMEX")
    elif (len(number) in [13, 16]) and int(number[0]) == 4:
        print("VISA")
    else:
        print("INVALID")  # printing invalid

else:
    print("INVALID")  # printing invalid
