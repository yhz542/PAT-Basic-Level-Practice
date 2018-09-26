import sys
N = int( sys.stdin.readline() ) #注意会卡的几个地方 1.没有单身狗 则只输出个数。 2.编号从00000开始 可能出现前面为0后面为自然数的组合 如果按int读入
Couple = {}                     #可能会出现问题。
for i in range( N ):
    husband , wife = map( int , sys.stdin.readline().split() )
    Couple[ husband ] = wife
    Couple[ wife ] = husband
M = int( sys.stdin.readline() )
SingleDog = set()
cnt = 0
for i in map( int , sys.stdin.readline().split() ):#这个人有三种情况  1 ，不在夫妻配对中(加入)， 2，在夫妻中但是配偶没来（加入） 
    if i not in Couple:                            #3 ，在夫妻中但是配偶来了(删除配偶 且不加入)
        SingleDog.add( i )
    else:
        if Couple[i] not in SingleDog:
            SingleDog.add( i )
        else:
            SingleDog.discard( Couple[i] )
            cnt += 1
SingleDog = list( SingleDog )
SingleDog.sort()
Num = M - 2 * cnt
print( Num )
if( Num ):
    print( '%05d'%SingleDog[0] , end = '')
    for i in SingleDog[1:]:
        print(' %05d'%i,end='')
        
