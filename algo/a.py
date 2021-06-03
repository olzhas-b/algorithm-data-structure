nums = list(map(int, (input().split())))
x = nums[0]
y = nums[1]
f = nums[2]
n = nums[3]
a =  list(map(float, (input().split())))
b = list(map(float, (input().split())))

if(x > y + f or x + f <= y or f == 0):
    print(1)
elif(x > y):
    ind = 0
    mx = -10000000
    for i in range(n):
        k = a[i] * b[i]
        if(mx < k):
            mx = k
            ind = i
    print(ind + 1)
else:
    ind = 0
    mx = -10000000
    for i in range(n):
        k = a[i] * (100000 - b[i])
        if(mx < k):
            mx = k
            ind = i
    print(ind + 1)