import sys
N = int( sys.stdin.readline() )
L = [ 0 for i in range(N) ]
for i in range( N ) :
    tem = sys.stdin.readline().split()
    L[ int( tem[ 1 ] ) - 1 ] = tem
M = int( sys.stdin.readline() )
for i in map( int , sys.stdin.readline().split() ) :
    print( L[ i - 1 ][ 0 ] , L[ i - 1][ 2 ] )
