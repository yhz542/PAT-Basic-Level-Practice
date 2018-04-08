import sys
N , p = map(int,sys.stdin.readline().split())
L = list( map(int,sys.stdin.readline().split()))
L.sort()
cnt = 0
NextStart = 1
for i in range( N - cnt ):
    tem = NextStart - i
    for j in range( NextStart , N ):
        if L[ i ] * p <L [ j ]:
            NextStart = j
            break;
        tem += 1
    if cnt < tem :
        cnt = tem
print(cnt)
# 思路见c语言版本
