n = input()
if len( n ) < 4 :
    N=[]
    for i in range( 4 - len(n) ):
        N.append('0')
    N.extend( n )
else :
    N = list( n )
n = int( n )
a = sorted( N )
b = a[::-1]
while True:
    a = int( "".join( a ) )
    b = int( ''.join( b ) )
    if  a == b :
        print('{:04d} - {:04d} = 0000'.format( b , a ) )
        break
    elif b - a == 6174:
        print('{:04d} - {:04d} = 6174'.format( b , a ) )
        break
    else :
        print('{:04d} - {:04d} = {:04d}'.format( b , a , b-a ) )
        n = b - a
        tem = str( n )
        if len(tem) < 4 :
            N=[]
            for i in range( 4 - len(tem) ):
                N.append('0')
            N.extend(tem)
        else :
            N = list( tem )
        a = sorted( N )
        b = sorted( a , reverse = True )

