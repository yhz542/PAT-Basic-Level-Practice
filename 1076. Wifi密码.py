import sys
answer = { 'A' : 1 , 'B' : 2 , 'C' : 3 ,'D' : 4 }
N = int( sys.stdin.readline().rstrip() )
for i in range( N ):
    for value in sys.stdin.readline().split():
        if value[2] == 'T':
            print(answer[ value[0] ],end='')
            #break 可加快速度
