Data = [ 0 , 0 , 0 , 0 , 0 , 0 ]
maps = { 'P' : 0 , 'A' : 1 , 'T' :2 , 'e' : 3 , 's' : 4 , 't' : 5 }
cnt = 0
for i in input().strip() :
    if i in maps :#如果字母不为PATest中的字符就跳过
        Data[ maps[ i ] ] += 1
        cnt += 1
while cnt :
    if Data[ 0 ] :
        Data[ 0 ] -= 1
        cnt -= 1
        print( 'P' , end = '' )
    if Data[ 1 ] :
        Data[ 1 ] -= 1
        print( 'A' , end = '' )
        cnt -= 1
    if Data[ 2 ] :
        Data[ 2 ] -= 1
        cnt -= 1
        print( 'T' , end = '' )
    if Data[ 3 ] :
        cnt -= 1
        Data[ 3 ] -= 1
        print( 'e' , end = '' )
    if Data[ 4 ] :
        cnt -= 1
        Data[ 4 ] -= 1
        print( 's' , end = '' )
    if Data[ 5 ] :
        cnt -= 1
        Data[ 5 ] -= 1
        print( 't' , end = '' )
#最后循环处理的时候可以将其写为函数进行调用来简化代码
