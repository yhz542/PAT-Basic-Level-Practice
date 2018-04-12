def IsInsertionSort( origin , sort , N ):#探测是否是插入排序，如果从无序数据点开始，之后的数据与原未排序的数据相同，那么就是插入排序，否则归并
    i = 1 
    while i < N :
        if sort[ i ] < sort[ i - 1 ] :
            break
        i += 1
    Length = i
    while i < N :
        if sort[ i ] != origin[ i ] :
            print( 'Merge Sort' )
            flag = 0
            break
        i += 1
    if i == N :
        print( 'Insertion Sort' )
        flag = 1
    return flag , Length

def InsertionSort( sort , N ):#探测到实际需要排序的点时并不排序，先输出排序点排序后所在位置之前的数据，再输出排序点，最后输出剩余数据
    for i in range( N ):
        if sort[ N ] < sort[i] :
            break
        else :
            print( sort[ i ],'' , end = '')
    print( sort[ N ] ,end='')
    for i in sort[ i : N ] :
        print( '',i , end = '' )
    for i in sort[ N + 1 :] :
        print( '' , i , end = '' )
        
def FindSubLength( sort , N ) :
'''寻找子列长度，从4开始探测（至少是2 不可能是1 ）每隔子列长度，比较一下元素是否满足要求如果全部数据满足当前归并子列长度，长度乘2,直到不满足要求跳出
为止，此时子列长度即为实际长度  注意，此算法理论时间复杂度为 x/2+x/4+x/8+..... O( x ) 约等于线性（比线性还有略小），如果从4开始探测 则时间复杂度为
O(1/2 x) 算得上是很快的速度了'''
    subLength = 4
    while True:
        for i in range( int( subLength/2 ) , N , subLength ) :
            if sort[ i ] < sort[ i - 1 ]:
                return int( subLength / 2)
        subLength *= 2
            
        
def MergeSort( sort , N ):
    subLength = FindSubLength( sort  , N )
    #print('Sublength=%d'%subLength)
    currentLength = subLength * 2
    times = N // currentLength
    for i in range( times ):
        tem = sorted( sort[ i * currentLength : ( i + 1)*currentLength ] )
        sort[ i * currentLength : ( i + 1)*currentLength ] = tem
    tem = sorted( sort[ ( i + 1)*currentLength :])
    sort[ ( i + 1)*currentLength :] = tem
    print(sort[0],end='')
    for i in sort[1:]:
        print( '',i ,end='') 

import sys
N = int( sys.stdin.readline() )
origin = list( map( int , sys.stdin.readline().split() ) )
sort = list( map( int , sys.stdin.readline().split() ) )
flag , Length =  IsInsertionSort( origin , sort , N )
if flag :
    InsertionSort( sort , Length )
else :
    MergeSort( sort  , N )
