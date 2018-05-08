def gcd( N , M ) :#必须保证N>=M
    return gcd( M , N % M ) if M else N

import sys
head , tail , K = sys.stdin.readline().split()
K = int( K )
head = list( map( int , head.split('/') ) )
tail = list( map( int , tail.split('/') ) )
if head[ 0 ] / head[ 1 ] > tail[ 0 ] / tail[ 1 ] :
    tem = head
    head = tail
    tail = tem
    del(tem)
start = int( head[ 0 ] / head[ 1 ] * K ) + 1
end = int( tail[ 0 ] / tail[ 1 ] * K )
if end / K == tail[ 0 ] / tail[ 1 ] :
    end -= 1
flag = 0
for i in range( start , end + 1 ) :
    output = False
    if i < K :
        if gcd( K , i ) == 1 :
            output = True
    elif i > K :
        if gcd( i , K ) == 1 :
            output = True
    if output :
        if flag :
            print( ' ' , end = '')
        print( '%d/%d'%( i , K ) , end ='' )
        flag = 1
''' 没什么好说的 注意两个地方就可以了
1.分子不一定比分母小
2.第二个数不一定比第一个数大
'''
