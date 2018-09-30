import sys
M , N , S = map( int , sys.stdin.readline().split() )
'''分两种情况 一种keep going 一种 抽奖人数大于第一个中奖序号，注意 这里中奖间隔是按照中奖的那个人开始计算的，也就是说如果因为重复转发导致中奖人延后
这个间隔也必须延后'''
LuckyBoy = set()
cnt = 0 ;
if M >= S :
    for i in range(S):
        name = sys.stdin.readline().rstrip() 
    LuckyBoy.add(name)
    print( name )
    for i in range( M - S ):
        cnt += 1
        name = sys.stdin.readline().rstrip()
        if cnt == N:
            if name in LuckyBoy:
                cnt -= 1
            else :
                LuckyBoy.add(name)
                print( name )
                cnt = 0
else :
    for i in range( M ):
        name = sys.stdin.readline()   
    print('Keep going...')
