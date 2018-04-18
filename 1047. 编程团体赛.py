import sys
N = int( sys.stdin.readline() )
Team = dict()
for i in range( N ) :
    Num , Grade = sys.stdin.readline().split()
    Num = int( Num.split( '-' )[0] )
    Team[ Num ] = Team.get( Num , 0 ) + int( Grade )
best = list( Team.keys( ) )[ 0 ]
for i in Team.keys() :
    if Team[ i ] > Team[ best ] :
        best = i
print( best , Team[ best ] )
