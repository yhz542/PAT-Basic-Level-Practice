import sys
N = int( sys.stdin.readline() )
Data = list( map( int , sys.stdin.readline().split() ) )
Data.sort( reverse = True)
flag = 0
for index, i in enumerate( Data ):
    if i <= (index+1) :
        flag = 1
        break
print( index if flag else index + 1 )
'''思路：没什么好说的 逆序排序后，进行遍历，当当前元素值小于等于下标时跳出循环，（即公里数小于等于天数）
额外两组测试数据
4
5 4 4 1
答案是3
3
4 4 4
答案还是3
'''
