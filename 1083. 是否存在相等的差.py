import sys
N = int( sys.stdin.readline().rstrip() )
Dvalue = {}
for index ,value in enumerate( map( int , sys.stdin.readline().split() ) ):
    differ = abs( value - index - 1 )
    Dvalue[ differ ] = Dvalue.get( differ , 0 ) + 1
Repeat = []
for i in Dvalue:
    if Dvalue[ i ] > 1:
        Repeat.append( i )
Repeat.sort( reverse = True )
for i in Repeat:
    print( i , Dvalue[ i ] )
