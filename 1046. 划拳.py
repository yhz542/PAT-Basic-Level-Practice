import sys
N = int( sys.stdin.readline( ) )
Drink_A = 0
Drink_B = 0
for i in range( N ) :
    Shout_A , Finger_A , Shout_B ,Finger_B = map(int , sys.stdin.readline().split())
    Sum = Shout_A + Shout_B
    if Finger_A != Finger_B :
        if Finger_A == Sum :
            Drink_B += 1
        elif Finger_B == Sum :
            Drink_A += 1
print( Drink_A , Drink_B )
