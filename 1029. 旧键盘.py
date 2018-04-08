import sys
theory = sys.stdin.readline().strip()
reality = set(sys.stdin.readline().strip().upper())
for i in theory :
    i = i.upper() if i.islower() else i
    if i not in reality :
        print( i ,end='')
        reality.add( i )
