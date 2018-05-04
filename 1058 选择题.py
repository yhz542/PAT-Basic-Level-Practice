import sys
N , M = map( int , sys.stdin.readline().split() )
text = []
for i in range( M ) :
    FullScore ,  AllSelect , CorrectItems = sys.stdin.readline().strip().split( maxsplit = 2 )
    text.append( ( int( FullScore ) , CorrectItems ) );
error = [ 0 for i in range( M ) ]
TemScore = 0
for i in range( N ) :
    answer = sys.stdin.readline().split( ')' )
    for i in range( M ) :
        if answer[ i ].strip()[ 1 : ] == text[ i ][ 1 ] :
            TemScore += text[ i ][ 0 ]
        else :
            error[ i ] += 1
    print( TemScore )
    TemScore = 0
Most = max( error )
flag = 0
if Most :
    print( Most , end = '' )
    for index , i in enumerate( error ) :
        if Most == i :
            print( '' , index + 1 , end = '' )
            flag = 1
else :
    print( 'Too simple' )
