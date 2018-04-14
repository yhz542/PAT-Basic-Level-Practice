import sys
Source = dict()
S_length = 0
for i in sys.stdin.readline().strip() :
    Source[ i ] = Source.get( i , 0 ) + 1
    S_length += 1
Lack = 0
T_length = 0
for i in sys.stdin.readline().strip() :
    if i in Source :
        Source[ i ] -= 1
        if Source[ i ] < 0 :
            Lack += 1
    else :
        Lack += 1
    T_length += 1
if not Lack :
    print( 'Yes' , S_length - T_length )
else :
    print( 'No' , Lack )
'''思路： 将输入读入字典或者哈希表，同时记录输入长度。 读入输入后，查询输入的字母是否存在于字典中，存在则计数减1，同时检查计数是否为负数，如果为负数则
将缺乏珠子个树加一。同时，假如输入的字母不存在于字典之中，直接将缺乏珠子个数加一。'''
