def Print( A , B ):#另一种思路，不过这个思路是建立在丙为整数的情况下。所以有一个测试点过不了。
    if A < B :     #思路 甲乙丙构成的关系可以写为两种关系 1 . | 甲 - 乙 | / 丙 = X      2 .  乙 / 丙 = Y  
        return 'Cong' #其中 1 分为两种情况 (1) 甲 > 乙 也就是 ( 甲 - 乙 ) / 丙 = X （2） 甲 < 乙 ( 乙 - 甲 ) / 丙 = X 将条件 2 带入
    elif A == B :     # 上述条件可以转换为 甲 / 丙 = X + Y  或者 甲/丙 = Y- X
        return 'Ping'
    else:
        return 'Gai'
M , X , Y = map( int , input().split() )
times = X + Y # 甲大于乙
start = 99 // times #丙可能的最大开始值
for c in range( start , 0 , -1 ): # c为丙 b为乙 a为甲
    a = c * times
    b = int( str( a )[ : : -1 ] )
    if divmod( b , c ) == ( Y , 0 ) :
        break
else:
    a = 0
times = Y - X # 甲小于乙
if times:
    start = 99 // times
    for k in range( start , 0 , -1 ):
        i = k *times
        j = int( str( i )[ : : -1 ] )
        if divmod( j , k ) == ( Y , 0 ) :
            break
    else :
        i = 0
else:
    i = 0
if a and i :# 比较两种情况 那个甲大 取大的那一组输出
    jia = a if a > i else i
    if jia == a:
        yi = b
        bing = c
    else:
        yi = j
        bing = k
elif a :
    jia = a
    yi = b
    bing = c
elif i :
    jia = i
    yi = j
    bing = k
else :
    print( 'No Solution' )
    exit( 0 )
print( jia , Print( M , jia ) , Print( M , yi ) , Print( M , bing ) )
