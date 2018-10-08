import sys#代码未优化过，应该可以写得更简单一点。 题目需要注意的是解压的时候 数字不一定是1位 也可能是2位 3位 4位 处理时需要把之间的数字保存下来
#https://blog.csdn.net/qq_37430374/article/details/78816224 别人写的C++版本 稍微改改就可以变成C语言版本
def zipped( string ):
    former = string[ 0 ]
    cnt = 1
    for value in string[ 1 : ] :
        if value == former :
            cnt += 1
        else:
            if cnt > 1:
                addition = str( cnt ) + former
            else:
                addition = former
            print( addition , end = '' )
            cnt = 1
            former = value
    else:
        if cnt > 1:
            addition = str( cnt ) + former
        else:
            addition = former
        print( addition )

def unzipped( string ):
    former = string[ 0 ]
    if former.isdigit():
        cnt = former
    else:
        print( former , end ='')
        cnt ='0'
    for i in string[1: ]:
        if i.isdigit() :
            if former.isdigit():
                cnt = cnt + i
            else:
                cnt = i
        else:
            cnt = int( cnt )
            if cnt :
                print( cnt * i ,end = '')
            else:
                print( i , end ='' )
            cnt ='0'
        former = i

NeedZip = sys.stdin.readline().rstrip()
string = sys.stdin.readline().rstrip('\n')
if NeedZip == 'C':
    answer = zipped( string )
else:
    answer = unzipped( string )
