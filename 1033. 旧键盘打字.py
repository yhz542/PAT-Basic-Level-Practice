import sys
brokenkeys = set( sys.stdin.readline().strip() )
words = sys.stdin.readline().strip()
shift = 0 if '+' in brokenkeys else 1 #记录上档键是否损坏 损坏记 0 否则记 1
for i in words :
    if i.upper() not in brokenkeys :
        if i.isupper():
            print( i if shift else '' ,end='')
        else :
            print(i,end='')
