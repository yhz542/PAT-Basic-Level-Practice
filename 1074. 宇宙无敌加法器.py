import sys
N = sys.stdin.readline().rstrip()
PAT1 = sys.stdin.readline().rstrip()#将输入数字当作字符串处理 会比较方便也可以读入整数后对10整除 读入数组处理
PAT2 = sys.stdin.readline().rstrip()
len1 = len( PAT1 )
len2 = len( PAT2 )
difference = len1 - len2#比较两个输入的长度 短的一方补0，方便统一计算
if difference > 0 :
    PAT2 = ''.join(['0'*difference , PAT2 ])
    length = len1
elif difference < 0 :
    PAT1 = '0'*(-difference) + PAT1
    length = len2
answer = [ 0 for i in range(len(N)+1)]#创造答案的格式，注意由于有进位的存在 所以位数最多比进制表 N的进制还要多1位
begin = -1             #从末位开始计算
forward = 0            #记录是否进位 0不进 1 进
for i in N[::-1]:
    num = int( i )
    number = int( PAT1[begin] ) + int( PAT2[begin] )+forward
    forward = 0
    if not num:
        num=10
    if number >= num:
        number -= num
        forward = 1
    answer[begin] = number
    begin-=1
if forward == 1:#如果最后进位为 1 在头位补一个1
    answer[begin] = 1
for i,value in enumerate(answer):
    if value:
        begin = i
        break
for i in answer[i:]:
    print(i,end='')
