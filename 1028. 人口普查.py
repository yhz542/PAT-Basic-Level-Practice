import sys
N = int( sys.stdin.readline() )
youngest = mins = '1814/09/06'
oldest = maxs = '2014/09/06'
EffectiveNum = 0
for i in range( N ):
    Name , Birthday = sys.stdin.readline().split()
    if Birthday < mins or Birthday > maxs :
        continue
    else :
        EffectiveNum += 1
        if Birthday >= youngest :
            name_young = Name
            youngest = Birthday
        if Birthday <= oldest :
            name_old = Name
            oldest = Birthday
print( EffectiveNum , end = '' )
if EffectiveNum:
    print( ' '+name_old , name_young )
