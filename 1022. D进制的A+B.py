def cal( N , D ) :
    if(  N >= D ):
        cal( int( N / D ) , D )
    print( N % D , end='' )
A , B , D = map( int , input().split())
N = A + B
cal ( N , D)
