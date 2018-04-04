import sys
N , D = sys.stdin.readline().split()
N = int( N )
D = int( D )
C = []
for i in sys.stdin.readline().split() :
    i = float ( i )
    tem = [ i ]
    C.append( tem )
tem = 0
for i in sys.stdin.readline().split() :
    i = float ( i )
    C[ tem ].append( i )
    tem += 1
for i in range( N ):
    price =  C[i][1] / C[i][0]
    C[i].append(price)
C = sorted( C , key = lambda x:x[2] ,reverse = True )
stock = 0
profit = 0 
for i in range( N ) :
    if D - stock >= C[ i ][ 0 ] :
        profit += C[ i ][ 1 ]
        stock += C[ i ][ 0 ]
    elif D - stock > 0 :
        profit += ( D - stock ) * C[ i ][ 2 ]
        stock = D
    else:
        break
print('{:.2f}'.format( profit))
