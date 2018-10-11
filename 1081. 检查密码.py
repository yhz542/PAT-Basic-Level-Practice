import sys
N = int( sys.stdin.readline().rstrip() )
for i in range( N ):
    password = sys.stdin.readline().rstrip('\n')
    num = False
    alpha = False
    if len( password ) < 6 :
        print('Your password is tai duan le.')
    else:
        for j in password:
            if j.isdigit():
                num = True
            elif j.isalpha() :
                alpha = True
            elif j !='.':
                print( 'Your password is tai luan le.' )
                break
        else:
            if alpha and ( not num ) :
                print( 'Your password needs shu zi.' )
            elif num and ( not alpha ):
                print( 'Your password needs zi mu.' )
            else:
                print('Your password is wan mei.')
