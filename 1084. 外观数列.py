d , N = input().split()
for i in range( int( N ) -1 ):
    cnt = 0
    new=[]
    currentchar = ''
    for index , value in enumerate( d ):
        if currentchar == value :
            cnt += 1
        else :
            new.extend( [ currentchar , str( cnt ) ] )
            cnt = 1
            currentchar = value
    new.extend( [ currentchar , str( cnt ) ] )
    d = ''.join( new[2:] )
print( d )
