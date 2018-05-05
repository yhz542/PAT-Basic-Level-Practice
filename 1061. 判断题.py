import sys
N , M = map( int , sys.stdin.readline().split() )
FullScore = list( map( int , sys.stdin.readline().split() ) )
CorrectAnswer = list( map( int , sys.stdin.readline().split() ) )
for i in range( N ) :
    Score = 0
    student = list( map( int , sys.stdin.readline().split() ) )
    for j in range( M ) :
        if student[ j ] == CorrectAnswer[ j ] :
            Score += FullScore[ j ]
    print( Score )
