A = input()#没什么好说的 python写这个真实太容易了
for i in range( 10 ):
    B = A[ : : -1 ]
    if A == B:
        print( A , 'is a palindromic number.' )
        break
    Result = int( A ) + int( B )
    print( A , '+' , B , '=' , Result )
    A = str( Result )
else:
    print( 'Not found in 10 iterations.' )
