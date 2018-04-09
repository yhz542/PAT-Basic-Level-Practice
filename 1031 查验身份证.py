import sys
weight = [ 7 , 9 , 10 , 5 , 8 , 4 , 2 , 1 , 6 , 3 , 7 , 9 , 10 , 5 , 8 , 4 , 2 ]
M = [ '1' , '0' , 'X' ,'9' , '8' , '7' , '6' , '5' , '4' , '3' , '2' ]
N = int( sys.stdin.readline() )
flag = 0
for i in range( N ) :
    cnt = 0
    tem = sys.stdin.readline()
    for j in range( 17 ):
        if tem[j].isdigit() :
            cnt += int( tem[ j ] ) * weight[ j ]
        else:
            flag = 1
            print( tem ,end='')
            break
    if j==16 and M[ cnt % 11 ] != tem[17]:
        print( tem,end='' )
        flag = 1
if not flag :
    print( 'All passed' )
