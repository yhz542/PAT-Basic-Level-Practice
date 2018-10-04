import sys
N = sys.stdin.readline().rstrip()
PAT1 = sys.stdin.readline().rstrip()
PAT2 = sys.stdin.readline().rstrip()
len1 = len( PAT1 )
len2 = len( PAT2 )
difference = len1 - len2
if difference > 0 :
    PAT2 = ''.join(['0'*difference , PAT2 ])
    length = len1
elif difference < 0 :
    PAT1 = '0'*(-difference) + PAT1
    length = len2
answer = [ 0 for i in range(len(N)+1)]
begin = -1
forward = 0
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
if forward == 1:
    answer[begin] = 1
for i,value in enumerate(answer):
    if value:
        begin = i
        break
for i in answer[i:]:
    print(i,end='')
