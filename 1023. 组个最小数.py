L = input().split()
L = [ int(i) for i in L ]
for i in range(1,10) :
    if L[i] :
        L[i] -= 1
        break
print(i,end='')
for i in range(10):
    print( str(i)*L[i],end='' )
