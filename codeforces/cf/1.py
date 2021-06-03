n = int(input())
nums = list(map(float, input().split(" ")))
nums.sort()
res = nums[0]
for i in range(1, n):
    res = (res + nums[i]) / 2
print(res)
