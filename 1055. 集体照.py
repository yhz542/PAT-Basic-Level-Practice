def display( start , end , m) :
    global Info
    L = Info[ start : end ]
    flag = m % 2
    for i in range( m ) :
        if i == m//2 :
            print(L[ 0 ][0] , end = '' )
        elif i < m//2 :
            print( L[ -2 - i*2 ][0] if flag else L[ -1 - i*2 ][0], '' , end='')
        else :
            print( '' , L[ -1 - 2*(m - i - 1 ) ][0] if flag else L[ -2 - 2 *(m - i - 1 )][0], end = '' )
    print()    
            
import sys
N , K = map( int , sys.stdin.readline().split() )
numperow = N // K
res = N % K
Info = []
for i in range( N ) :
    name , high = sys.stdin.readline().split()
    Info.append(( name , int( high ) ))
Info = sorted( Info , key = lambda x :( -x[1],x[0] ) )
start = 0
end = 0
for i in range( K ) :
    if not i :
        m = numperow + res
    else :
        m = numperow
    end = start + m
    display( start , end , m )
    start = end
