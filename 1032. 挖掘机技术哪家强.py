import sys
N = int( sys.stdin.readline() )
school = dict()
for i in range( N ) :
    ID , Score = map(int,sys.stdin.readline().split())
    school[ ID ] = Score + school.get( ID , 0 )
maxs = -1
for i in school:
    if school[i] > maxs:
        maxs = school[i]
        maxsID = i
print(maxsID , maxs)
