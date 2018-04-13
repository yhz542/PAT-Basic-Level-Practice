import sys
N = int ( sys.stdin.readline() )
Score = map( int , sys.stdin.readline().split() ) 
K , Search = sys.stdin.readline().strip().split( maxsplit = 1 )
Data = [ 0 for i in range(101) ]
for i in Score :
    Data[ i ] += 1
flag = 0
Search = map( int , Search.split() )
for i in Search :
    if not flag :
        print( Data[ i ],end='')
        flag = 1
    else :
        print( '' , Data[ i ],end='')
