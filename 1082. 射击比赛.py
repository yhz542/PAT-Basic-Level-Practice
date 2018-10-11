import sys
worstdistance = -1
bestdistance = 101 ** 2 + 101 ** 2
N = int( sys.stdin.readline().rstrip() )
for i in range( N ) :
    ID , x , y = map( int , sys.stdin.readline().split() )
    distance = x ** 2 + y ** 2
    if distance < bestdistance :
        bestdistance = distance
        bestID = ID
    if distance > worstdistance:
        worstID = ID
        worstdistance = distance
print( '%04d'%bestID , '%04d'%worstID )
