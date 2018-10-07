import sys  #注意python中的四舍五入有问题，需要用到decimal库
from decimal import Decimal,getcontext,ROUND_HALF_UP
context = getcontext()
context.rounding = ROUND_HALF_UP
N , M = map( int , sys.stdin.readline().split() )
for i in range( N ) :
    score = list( map( int ,sys.stdin.readline().split() ) )
    length = 0
    Sum = 0
    Min = M + 1
    Max = -1
    for i in score[1:] :
        if 0 <= i <= M :
            Sum += i
            length+=1
            if i > Max :
                Max = i
            if i < Min :
                Min = i
    Sum = Sum - Max - Min
    G1 = Sum / ( length - 2 )
    G2 = score[ 0 ]
    print( round((Decimal( str( G1 ) ) + Decimal( str(G2) ))/2 , 0 ))
