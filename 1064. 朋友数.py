import sys
N = int( sys.stdin.readline() )
num =  sys.stdin.readline().split()
FriendNum = set()
for i in num:
    Sum = 0
    for n in i:
        k = int( n )
        Sum += k
    if Sum not in FriendNum :
        FriendNum.add( Sum )
FriendNum = list( FriendNum )
length = len( FriendNum )
print( length )
FriendNum.sort()
print( FriendNum[ 0 ] ,end = '')
if length > 1 :
    for i in FriendNum[1:] :
        print( ' %d'%i , end = '' )
