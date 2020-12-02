#Задание4
a = int(input())
n = int(input())
def my_power(a, n):
    if n == 0:
        return 1
    return a*my_power(a, n-1)
print(my_power(a,n))
