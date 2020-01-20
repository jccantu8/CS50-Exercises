import cs50
import sys

if len(sys.argv) == 1:
    print("No key provided in command line")
    sys.exit(1)

print("Please enter a string to encrypt: ", end='')
plaintext = cs50.get_string()
print()

keyd = sys.argv[1]

k = int(keyd)

print("ciphertext: ", end='')

for n in plaintext:
    if (n.isalpha()):
        if (n.isupper()):
            print(chr(65 + ((ord(n) - 65) + k) % 26), end='')
        else:
            print(chr(97 + ((ord(n) - 97) + k) % 26), end='')
    else:
        print(n, end='')

print()