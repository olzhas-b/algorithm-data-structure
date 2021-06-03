from math import factorial
for i in range(100):
    x=factorial(i)+1
    y=pow(x,0.5)
    if x ==int(y) * int(y):
        print(i,int(y))