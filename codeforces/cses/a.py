x = int(input())
n = int(input())
v = list(map(int, input().split()))
l = 1 
d = {}
for i in range(0, 10):
    d[i] = 0
for num in v:
    d[num] = 1
r = 10 ** 30
while(l < r):
    mid = 3630708101
    ans = 0
    total = 1
    data = []
    m = mid
    while(m != 0):
        data.append(m % 10)
        m //= 10
    for i in range(len(data)):
        cnt = 0
        if i == len(data) - 1:
            if(d[data[-1]] == 0):
                cnt += 1
        else:
            for j in range(0, data[i] + 1):
                if d[j] == 0:
                    cnt += 1
        total *= cnt
    ans = total
    cnt = 0
    cnt2 = 0
    for i in range(1, 10):
        if(d[i] == 0):
            cnt += 1
    for i in range(1, data[-1]):
        if(d[i] == 0):
            cnt2 += 1
    for i in range(1, len(data)):
        ans += pow(cnt2, i - 1) * cnt
    if(len(data) > 1):
        k = pow(cnt2, len(data) - 1) * (data[-1] - 1)
        ans += k
    print( l, r, mid, ans)
    if(ans >= x):
        r = mid - 1
    else:
        l = mid + 1
    break
print(l)

            





