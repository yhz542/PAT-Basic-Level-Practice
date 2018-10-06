def Connect( List ):#最后一个测试点运行超时 思路是将输入序列分成三部分 负数 正数小于等于K 大于K三部分进行连接后再首尾相连
    times = len( List ) - 1
    if times :
        global Store
        for index in range( times ) :
            Address = List[ index ]
            Next = List[ index + 1 ]
            Store[ Address ][ 1 ] = Next
            
import sys
FirstAddress , N , K = map( int , sys.stdin.readline().split() )
Store = {}
for i in range( N ):
    Address , Data , Next = map( int , sys.stdin.readline().split() )
    Store[ Address ] = [ Data , Next ]
Data = Store[ FirstAddress ][ 0 ]
List = [ Data ]
address = [ FirstAddress ]
Next = Store[ FirstAddress ][ 1 ]
while Next != -1 :
    Data = Store[Next][ 0 ]
    List.append( Data )
    address.append( Next )
    Next = Store[ Next ][ 1 ]
Negative = []
Medium = []
Greater = []
for index,value in enumerate(List):
    if value < 0:
        Negative.append( address[ index ] )
    else:
        if value <= K:
            Medium.append( address[index] )
        else:
            Greater.append( address[index] )
if len( Negative ):
    Connect( Negative )
    First = 1
else:
    First = 0
if len( Medium ) :
    Connect( Medium )
    Second = 1
else:
    Second = 0
if len( Greater ):
    Connect( Greater )
    Third = 1
else:
    Third = 0
if First :#判断每一部分是否存在 ，是否首尾相连并直接获取首尾地址
    begin = Negative[ 0 ]
    if Second :
        Store[ Negative[ - 1 ] ][ 1 ] = Medium[ 0 ]
        if Third:
            Store[ Medium[ - 1 ] ][ 1 ] = Greater[ 0 ]
            end = Greater[ -1 ]
        else:
            end = Medium[ -1 ]
    elif Third:
        Store[ Negative[ - 1 ] ][ 1 ] = Greater[ 0 ]
        end = Greater[ -1 ]
    else:
        end = Negative[ -1 ]
elif Second :
    begin = Medium[ 0 ]
    if Third:
        Store[ Medium[ -1 ] ][1] = Greater[ 0 ]
        end = Greater[ -1 ]
    else:
        end = Medium[ -1 ]
else:
    begin = Greater[ 0 ]
    end = Greater[ -1 ]
FirstAddress = begin
Store[ end ][ 1] = -1
Next = FirstAddress
while Store[Next][1]!= -1:
    print( '{:05d} {} {:05d}'.format( Next , Store[ Next ][ 0 ] , Store[Next][1]))
    Next = Store[Next][1]
print('%05d %d %d'%( Next , Store[Next][ 0 ] ,Store[Next][1]))
