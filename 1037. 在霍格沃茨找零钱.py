def contrast( a , b ):
    for i in range( 3 ):
        if a[ i ] != b[ i ]:
            return a[ i ] - b [ i ]
    return 0
def calculate( A , P ):
    Knut = A[ 2 ] - P[ 2 ]
    if Knut < 0 :
        A [ 1 ] -= 1
        Knut += 29
    Sickle = A[ 1 ] - P[ 1 ]
    if Sickle < 0 :
        A[ 0 ] -= 1
        Sickle += 17
    Galleon = A[0] - P[0]
    print('{}.{}.{}'.format( Galleon , Sickle , Knut ) )
P , A = input().split()
P = list( map ( int , P.split('.') ) )
A = list( map ( int , A.split('.') ) )
if contrast( A , P ) >= 0 :
    calculate( A , P )
else:
    print('-' , end = '')
    calculate( P , A )
