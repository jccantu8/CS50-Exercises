#import cs50 library to use get_int function
import cs50

#while loop used to accept an appropriate input
while (True):
    print("Please enter a height between 0 and 23: ", end='')
    x = cs50.get_int()
    if (x >= 0 and x <= 23):
        break

#for loop logic used to print appropriate number of spaces and hashes
for j in range(x):
    print(" " * (x - (j + 1)), end='')
    print("#" * (j + 1), end='')
    print("  ", end='')
    print("#" * (j + 1))