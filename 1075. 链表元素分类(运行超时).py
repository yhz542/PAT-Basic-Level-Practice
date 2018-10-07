import sys
FirstAddress , N , K = map( int , sys.stdin.readline().split() )
Store = {}
for i in range( N ):
    Address , Data , Next = map( int , sys.stdin.readline().split() )
    Store[ Address ] = [ Data , Next ]
Data = Store[ FirstAddress ][ 0 ]
List = [ Data ]
address = [ FirstAddress ]
Next = Store[ FirstAddress ][ 1 ]
while Next != -1 :
    Data = Store[Next][ 0 ]
    List.append( Data )
    address.append( Next )
    Next = Store[ Next ][ 1 ]
Negative = []
Medium = []
Greater = []
for index,value in enumerate(List):
    if value < 0:
        Negative.append( address[ index ] )
    else:
        if value <= K:
            Medium.append( address[index] )
        else:
            Greater.append( address[index] )
Negative.extend(Medium)
Negative.extend(Greater)
end = Negative[-1]
cnt = 0
while Negative[ cnt ] != end:
    Address = Negative[ cnt ]
    print( '{:05d} {} {:05d}'.format( Address , Store[ Address ][ 0 ] , Negative[ cnt +1 ] ))
    cnt+= 1
print('%05d %d %d'%( Negative[ cnt ] , Store[Negative[cnt]][ 0 ] ,-1))
