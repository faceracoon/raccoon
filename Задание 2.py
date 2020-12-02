#Задание2
a=int(input())
def my_div(a):
  div='no div'
  for i in range(2,a-1):
    if a%1==0:
      div=1
  if div=='no div':
    return(a)
  else:
    return(div)
print(my_div(a))
