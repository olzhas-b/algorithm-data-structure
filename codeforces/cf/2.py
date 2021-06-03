n = int(input())
dp0 = []
dp1 = []
dp2 = []
for i in range(40 + 2):
    dp0.append(0)
    dp1.append(0)
    dp2.append(0)

dp0[1] = 1
dp1[1] = 1
dp2[1] = 1

dp0[2] = 3
dp1[2] = 2
dp2[2] = 3
for i in range(3, n + 1):
    dp2[i] = dp1[i - 1] + dp0[i - 1] + dp2[i - 1]
    dp1[i] = dp0[i - 1] + dp2[i - 1]
    dp0[i] = dp0[i - 1] + dp1[i - 1] + dp2[i - 1]
print(dp0[n] + dp1[n] + dp2[n])