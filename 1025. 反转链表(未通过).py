import sys#测试点5超时，以python的运行速度暂时想不到解决办法
start , N , K =  map( int ,sys.stdin.readline().split() ) 
L = []
for i in range( N ):
    new = list( map( int ,sys.stdin.readline().split() ) )
    if start == new[ 0 ]:
        startindex = i
    L.append(new)
address = start
new = []
cnt = 0
while address != -1 :
    for i in range( N ) :
        if L[ i ][ 0 ] == address :
            cnt += 1
            new.append( L[i] )
            address = L[ i ][ 2 ]
            L.pop(i)
            N -= 1
            break
times = int( cnt / K )
rest = cnt % K
for i in range(times):
    tem = new[i*K+0:(i+1)*K]
    tem.reverse()
    new[i*K+0:(i+1)*K] = tem
if not rest :
    cnt -= 1
else :
    cnt -= rest
for i in range( cnt ) :
    new[i][2] = new[ i+1 ][ 0 ]
new[-1][2]= -1
for i in new[:-1]:
    print('{:05d} {:d} {:05d}'.format(*i))
print('{:05d} {:d} {:d}'.format(*new[-1]))
