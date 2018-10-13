N = int( input() )
two = 0
three = 0
five = 0
cnt = 1
for i in range( N ) :
    flag = False
    two += 1
    three += 1
    five += 1
    if 2 == two :
        two = 0
        flag = True
    if 3 == three :
        three = 0
        flag = True
    if 5 == five:
        five = 0
        flag = True
    if flag:
        cnt += 1
print( cnt )
