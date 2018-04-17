import sys
N = int( sys.stdin.readline() )
Data = list( map( int , sys.stdin.readline().split() ) )
Sort = sorted( Data )
Pivot = []
cnt = 0
Left_Max = 0
for index,i in enumerate( Data ):
    if i > Left_Max :
        Left_Max = i
        if i == Sort[ index ] :
            Pivot.append( i )
            cnt += 1
print( cnt )
if cnt :
    print( Pivot[ 0 ] , end = '')
    for i in Pivot[ 1 : ] :
        print( '' , i , end = '')
else :
    print()
''' 解题思路： 对于一个主元进行一次快速排序后，所有大于它的值都在右边，所有小于它的值都在其左边。所以毫无疑问对一个主元排序一次后，他便直接处于当前数组内
的正确位置。所以判断是否是主元的第一个条件就是，数组排序前主元的位置和排序后主元的位置相同。其次，因为数组中元素各不相同。所以只要能确定主元左边的元素是
全部小于它，或者数组右边的元素全部大于它。也就是说只用确认测试元素是否大于左边最大的元素，或者小于右边最小的元素即可确认是否主元。'''


'''第二种解题办法。传统解法，两边进行测试，大于左边最小，小于右边最大，测试点1超时
def NextRight_Min( ) :
    global N , Right_Array , DeleteElement , Right_cnt ,Right_Min
    while Right_cnt < N-1 and Right_Array[ Right_cnt ] in DeleteElement :
        Right_cnt += 1
    if Right_cnt < N - 1: 
        Right_Min = Right_Array[ Right_cnt ]
import sys
N = int( sys.stdin.readline() )
Data = list( map( int , sys.stdin.readline().split() ) )
if N == 1 :
    print( N,Data[0],sep='\n' )
    exit(0)
Left_Max = 0
Right_Array = sorted( Data[ 1 : ] )
DeleteElement = set()
Right_cnt = 0
Right_Min = Right_Array[ Right_cnt ]
Output = []
All = 0
for i in Data :
    DeleteElement.add( i )
    if Left_Max < i :
        Left_Max = i
        if i < Right_Min :
            Output.append( i )
            All += 1
        elif i == Right_Min :
            Output.append( i )
            All += 1
            NextRight_Min()            
    else :
        if i == Right_Min :
            NextRight_Min()
print( All )
if All :
    print( Output[ 0 ] , end = '')
    for i in Output[ 1 : ] :
        print( '' , i , end = '')
else :
    print()
'''
