#Задание3
a = int(input())
b = int(input())
def my_sum(a,b):
  if (b>=0):
    while b!=0:
      a =a+1
      b =b-1
      my_sum(a,b)
  elif (b<0):
    while b!=0:
      a = a-1
      b = b+1
      my_sum(a,b)
  return(a)
print(my_sum(a,b))
