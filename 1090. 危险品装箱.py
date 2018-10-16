import sys
N , M = map( int , sys.stdin.readline().split() )#将不兼容的编号分别插入字典中，建立自身不兼容的列表，这样查找起来比较快
Incompatible = {}                                #将测试清单转为列表和集合两部分，列表用来对每一个编号进行查找不兼容的遍历，集合用于快速寻
for i in range( N ) :                            #找不兼容的编号是否在集合中。
    A , B = map( int , sys.stdin.readline().split() )
    if A not in Incompatible :
        Incompatible[ A ] = [ B ]      # A型号与B型号不兼容，考虑到不兼容的不只一个 做成列表形式
    else :
        Incompatible[ A ].append( B )
    if B not in Incompatible :
        Incompatible[ B ] = [ A ]      # B型号也与A型号不兼容。 有点类似于图
    else :
        Incompatible[ B ].append( A )
for i in range( M ):
    Data = list(map( int , sys.stdin.readline().split()[1:] ))  #制成列表用于遍历每一个输入型号
    Set = set( Data )                                           #制成集合用于查找不兼容的型号是否在输入中
    flag = 0
    for i in Data[:-1]:
        if i not in Incompatible:
            continue
        else:
            for j in Incompatible[ i ]:
                if j in Set:
                    print( 'No' )
                    flag = 1
                    break
        if flag:
            break
    else:
        print('Yes')
