import sys
import math
def IsPrime( Num ) :
    if Num == 2 or Num == 5 or Num == 3 :
        return True
    if ( not( Num % 2 ) ) or ( not ( Num % 5 ) ) or ( not( Num % 3 ) ) :
        return False
    Max = int( math.sqrt( Num ) )
    Max = Max if Max % 2 else Max - 1
    i = 7
    while i <= Max :
        for j in range( 4 ):
            if not( Num % i ):
                return False
            i += 2
        i += 2
    if Num <= 1 :
        return False
    return True

N = int( sys.stdin.readline() )
Prize = dict()
Prize[ sys.stdin.readline().strip() ] = 'Mystery Award'
for i in range( N - 1 ) :
    if IsPrime( i + 2 ) :
        Prize[ sys.stdin.readline().strip() ] = 'Minion'
    else :
        Prize[ sys.stdin.readline().strip() ] = 'Chocolate'
K = int( sys.stdin.readline() )
for i in range( K ) :
    Input = sys.stdin.readline().strip()
    print( '{}: '.format( Input ) , end = '' )
    if Input in Prize :
        if Prize[ Input ] :
            print( Prize[ Input ] )
            Prize[ Input ] = 0
        else :
            print( 'Checked' )
    else :
        print( 'Are you kidding?' )
