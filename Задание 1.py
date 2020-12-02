#Задание1
a=int(input())
b=int(input())
c=int(input())
d=int(input())
def my_min(a,b,c,d):
  x=min(a,b)
  y=min(c,d)
  z=min(x,y)
  return(z)
print(my_min(a,b,c,d))
