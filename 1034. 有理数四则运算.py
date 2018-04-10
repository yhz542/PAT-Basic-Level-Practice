def num( k , c , a , b ):#解题的关键在于辗转相除法（欧几里得算法）对分数进行化简。要求比较多，但并不难。慢慢理清要求即可写出代码。
    if not a :
        print( 0 ,end = '')
    else :
        if a < 0 :
            print( '(-' , end = '' )
        if k :
            print( k ,end='')
            if c :
                print( ' ',c,'/',b,sep='',end='')
        else :
            print( '{}/{}'.format( c , b ),end='')
        if a < 0 :
            print( ')' , end = '' )
            
def display( a3 , b3 , c3 , k3 , symbol ):
    global a1 , a2 , b1 , b2 , k1 , k2
    num( k1 , c1 , a1 , b1 )
    print(' {} '.format(symbol),end='')
    num( k2 , c2 , a2 , b2 )
    print(' = ',end='')
    num( k3 , c3 , a3 , b3 )
    print()
    
def gcd( a , b ):
    return gcd( b ,a%b) if b else a

def dealwith( a , b ):
    gys = gcd( a , b )
    return int( a / gys ) ,int( b / gys )

def solvekc( a , b ):
    return abs( int( a / b ) ), abs( a ) % b 

def add():
    global a1 , a2 , b1 , b2 , k1 , k2
    a3 = a1 * b2 + a2 * b1
    b3 = b1 * b2
    gys = gcd( a3 , b3 )
    a3 , b3 = dealwith( a3 , b3 )
    k3 , c3 = solvekc( a3 , b3 )
    display( a3 , b3 ,c3 , k3 ,'+' )

def subtract():
    global a1 , a2 , b1 , b2 , k1 , k2
    a3 = a1 * b2 - a2 * b1
    b3 = b1 * b2
    gys = gcd( a3 , b3 )
    a3 , b3 = dealwith( a3 , b3 )
    k3 , c3 = solvekc( a3 , b3 )
    display( a3 , b3 ,c3 , k3 ,'-' )

def multiply():
    global a1 , a2 , b1 , b2 , k1 , k2
    a3 = a1 * a2
    b3 = b1 * b2
    gys = gcd( a3 , b3 )
    a3 , b3 = dealwith( a3 , b3 )
    k3 , c3 = solvekc( a3 , b3 )
    display( a3 , b3 ,c3 , k3 ,'*' )

def divide():
    global a1 , a2 , b1 , b2 , k1 , k2
    a3 = a1 * b2 
    b3 = b1 * a2
    gys = gcd( a3 , b3 )
    a3 , b3 = dealwith( a3 , b3 )
    if b3 :
        k3 , c3 = solvekc( a3 , b3 )
    num( k1 , c1 , a1 , b1 )
    print(' / ',end='')
    num( k2 , c2 , a2 , b2 )
    print(' = ',end='')
    if b3 :
        num( k3 , c3 , a3 , b3 )
    else :
        print( 'Inf')
    
A , B = input().split()
a1 , b1 = map( int , A.split( '/' ) )
a2 , b2 = map( int , B.split( '/' ) )
a1 , b1 = dealwith( a1 , b1 )
a2 , b2 = dealwith( a2 , b2 )
k1 , c1 = solvekc( a1 , b1 )
k2 , c2 = solvekc( a2 , b2 )
add()
subtract()
multiply()
divide()
