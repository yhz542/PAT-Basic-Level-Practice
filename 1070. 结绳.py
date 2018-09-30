import sys#没什么好说的，最简单的第五题了，排序后先把第一个确定然后进行N-1次加法和除法
N = int( sys.stdin.readline().rstrip() )
data = list( map( int , sys.stdin.readline().split()))
data.sort()
Sum = data[0]
for i in range( len(data) - 1 ):
    Sum += data[ i + 1 ]
    Sum /= 2
print( int( Sum ) )
