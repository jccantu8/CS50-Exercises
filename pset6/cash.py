import cs50

z = 0

while True:
    print("Please enter change owed: ", end='')
    x = cs50.get_float()
    if x > 0:
        break


y = round(x * 100)

z += (y // 25)
y = (y % 25)

z += (y // 10)
y = (y % 10)

z += (y // 5)
y = (y % 5)

z += (y // 1)

print(int(z))