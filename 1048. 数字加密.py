def getlength() :
    global A , B
    lenA = len( A )
    lenB = len( B )
    if lenA > lenB :
        length = lenA
        B = '0'*( lenA - lenB )+ B
    elif lenA <= lenB :
        length = lenA
        print( B[ : lenB - lenA ] , end = '' )
        B = B[ lenB - lenA : ]
    return length
        
A , B = input().split()
length = getlength()
flag = 1 if length % 2 else 0
for i in range( length ):
    if flag :
        new = int( A[ i ] ) + int( B[ i ] )
        new %= 13
        if new == 10 :
            new = 'J'
        elif new == 11 :
            new = 'Q'
        elif new == 12 :
            new = 'K'
    else :
        new = int( B[ i ] ) - int( A[ i ] )
        if new < 0 :
            new += 10
    print( new , end = '' )
    flag = ( flag + 1 ) % 2
