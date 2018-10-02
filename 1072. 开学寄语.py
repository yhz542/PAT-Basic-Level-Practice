import sys
N , M = map( int , sys.stdin.readline().split() )
Items = set( sys.stdin.readline().split() )
NumOfStu = 0
NumOfItems = 0
for i in range( N ) :
    name , K  = sys.stdin.readline().rstrip().split( ' ' , 1 )
    flag = 0
    if K[0] != '0':
        UnCheck = K.split()[1:]     
        for i in UnCheck :
            if i in Items:
                if not flag:
                    print( '%s:'%name ,end = '')
                    flag = 1
                    NumOfStu += 1
                print( ' %s'%i,end='')
                NumOfItems += 1
    if flag:
        print()
print('{} {}'.format( NumOfStu , NumOfItems ) )
