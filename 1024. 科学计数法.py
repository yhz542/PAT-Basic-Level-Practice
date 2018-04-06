def dealwithE( N , E ):
    if N[ 0 ] == '-' :
        print('-',end='')
    if E > 0 :
        length = len(N)-3
        if E >= length:
                print( N[1],N[3:],'0' * ( E - length ),sep='' )
        else :
                print( N[1],N[3:3+E],'.',N[3+E:],sep='')
    elif not E :
        print( N[1:])
    else :
        E = E*-1-1
        print( '0.','0'*E,N[1],N[3:],sep='')
N , E = input().split('E')
E = int(E)
dealwithE( N ,E )
#测试点4是幂次数为正且大于小数的位数 例如 -1.2345E+2
