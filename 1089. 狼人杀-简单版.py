#https://blog.csdn.net/weixin_41256413/article/details/82558575 参照思路
#用两个变量记录信息，1 ， 总撒谎数量， 2 ， 狼撒谎数量， 只有当总撒谎数量等于2 并且狼撒谎数量等于1时 答案才通过。
#先确定两头狼，然后遍历信息，如果某个人说的不符合当前的狼假设，就认为他撒谎，总撒谎数量加1 同时如果他为狼 则狼撒谎数量加一
import sys
N = int( sys.stdin.readline() )
Data = []
for i in range( N ):
    Data.append( int( sys.stdin.readline() ) )
for i in range( 1 , N + 1 ) :
    for j in range( i + 1 , N + 1 ):
        wolflie = 0
        amountlie = 0
        flag = 0
        for index , value in enumerate( Data ):
            if value < 0 and ( -value != i and -value != j ):
                amountlie += 1
                if index + 1 == i or index + 1 == j:
                    wolflie += 1
            elif value > 0 and ( value == i or value == j ) :
                amountlie += 1
                if index + 1 == i or index + 1 == j:
                    wolflie += 1
        if amountlie == 2 and wolflie == 1:
            print( i , j )
            flag = 1
            break
    if flag == 1:
        break
else:
    print( 'No Solution' )
