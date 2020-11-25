#Задание2
print("Введите первое число")
a=int(input(">>> "))
print("Введите второе число")
b=int(input(">>> "))
for i in range(a, b+1):
    s=str(i)
    n=str(i)[::-1]
    if s == n:
        print(s)
input()
