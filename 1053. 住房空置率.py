import sys
N , e , D = sys.stdin.readline().split()
N , D = map( int , ( N , D ) )
e = float( e )
empty = 0
possible = 0
for i in range( N ) :
    Input = sys.stdin.readline().split()
    cnt = 0
    K = int( Input[ 0 ] )
    E = list( map( float , Input[ 1 : ] ) )
    for j in E :
        if j < e :
            cnt += 1
    if cnt > K/2 :
        if K > D :
            empty += 1
        else :
            possible += 1
print('{:.1f}% {:.1f}%'.format( possible / N * 100 , empty / N * 100) )
