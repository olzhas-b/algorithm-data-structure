n = input()
l = []
for i in range(200):
    l.append(0)
for i in range(len(n)):
    l[ord(n[i])] += 1
check = 1
k = 0
for i in range(len(l)):
    if l[i] != 0:
        if(l[i] % 2 == 1 and check == 1):
            check = 0
        elif l[i] % 2 == 1 and check == 0:
            print("JOJO")
            k = 1
            break
if k == 0:
    print("ZA WARUDO TOKI WO TOMARE")