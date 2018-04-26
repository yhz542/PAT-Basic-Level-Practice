Input = list( map( int , input().split() ) )
N = Input[ 0 ]
Data = Input[ 1 : ]
Sum= 0
for index in range( N - 1 ) :
    for i in range( index + 1 , N ) :
        Sum += Data[ index ] * 10 + Data[ i ]
        Sum += Data[ index ] + Data[ i ] * 10
print( Sum )
