N , C = input().split()
column = int( N ) / 2
column = int( column + 1 ) if column - int(column) >= 0.5 else int( column )
print( C * int(N) )
for i in range( column - 2 ) :
    print( C,' '*( int(N) - 2 ),C,sep='')
print( C * int(N) )
