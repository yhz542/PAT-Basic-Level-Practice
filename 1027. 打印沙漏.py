def pr ( number , space ):
    global symbol
    if number == 1 :
        print(' ' * space , symbol ,sep = '' )
    else :
        print(' ' * space , symbol * number ,sep = '')
        pr( number - 2 , space + 1 )
        print(' ' * space , symbol * number ,sep = '')

N , symbol = input().split()
N = int( N )
cnt = 1
times = 1
i = 3
while cnt + 2 * i <= N :
    cnt += 2 * i
    i += 2
    times += 1
i -= 2
pr( i , 0 )
print( N - cnt )
