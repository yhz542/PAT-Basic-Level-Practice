import sys
T , K = map( int , sys.stdin.readline().split() )
for i in range( K ):
    n1 , b , t , n2 = map( int , sys.stdin.readline().split() )
    if t > T :
        print('Not enough tokens.  Total = %d.'%T ) 
    elif ( n1 > n2 and b == 0 ) or ( n1 < n2 and b == 1 ):
        T += t
        print('Win %d!  Total = %d.'%( t , T ) )
    else :
        T -= t
        print('Lose %d.  Total = %d.'%( t , T ) )
        if not T :
            print('Game Over.')
            break
