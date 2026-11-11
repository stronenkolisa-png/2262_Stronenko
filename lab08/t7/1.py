num = [int(t) for t in input().split()]
for x in num:
    if x < 0:
        print(x)
        break
else:
    print("Отрицательных чисел нет")
