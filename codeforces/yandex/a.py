n = int(input())
mod = 18446744073709551616
l , r = 0, mod 
while l <= r:
  m = l + r >> 1
  if m * 3 - m * 3 // mod * mod == n:
    print(m)
    exit(0)
  elif m * 3 - m * 3 // mod * mod < n:
    l = m + 1
  else:
    r = m - 1 
print(0)