import sys
def islegal( num ) :
    flag = True
    dotcnt = 0
    num = num[ 1 : ] if num[ 0 ] == '-' or num[ 0 ] == '+' else num
    for index , i in enumerate( num ) :
        if ( not i.isdigit() ) and i != '.' :
            flag = False
            break
        elif i == '.' :
            dotcnt += 1
            if len( num[ index + 1 : ] ) > 2 or dotcnt > 1 :
                flag = False
                break
    if flag :
        num = float( num )
        if -1000 > num or num > 1000 :
            flag = False
    return flag
    
N = int( sys.stdin.readline() )
Sum = 0
cnt = 0
for i in sys.stdin.readline().split() :
    if islegal( i ) :
        i = float( i )
        Sum += i
        cnt += 1
    else :
        print( 'ERROR: %s is not a legal number' %i )
if not cnt :
    print( 'The average of 0 numbers is Undefined' )
else :
    print( 'The average of {} number{} is {:.2f}'.format( cnt ,'s' if cnt > 1 else '', Sum / cnt ) )
