import sys
N = int( sys.stdin.readline() )
Data = list( map( float  , sys.stdin.readline().split() ) )
Sum = 0
Length = len( Data )
for index , i in enumerate( Data ) :
    Sum += i*(index+1)*( Length - index)
print( '{:.2f}'.format( Sum ) )
'''思路：对于 数列 1 2 3 4 5而言 1 出现了5此 2出现了 (5-1)*2 = 8 次，可以看作 包含在1 中的 2 （4个）和 以2为头的4个，同理可得对3而言 在1 中出现了3次
在2中也出现了3次，以3打头依然会出现3次，后面以4或者5打头就不会出现3了。所以该方法可以实现线性时间遍历'''
