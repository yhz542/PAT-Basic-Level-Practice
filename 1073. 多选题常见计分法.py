import sys#用C语言读入 操作起来应该更加舒服一些，另外如果用字典把选项和下标index对应起来代码应该更加少一些
N , M = map( int , sys.stdin.readline().split() )
QuestionInfo = []
for i in range( M ) :
    Info = sys.stdin.readline().split()
    QuestionInfo.append( list( map( int , Info[:3] )))
    QuestionInfo[i].extend([ 0 for j in range(QuestionInfo[i][1])])
    for j in Info[3:]:
        if j ==  'a':
            QuestionInfo[i][3] = 1
        elif j == 'b':
            QuestionInfo[i][4] = 1
        elif j == 'c':
            QuestionInfo[i][5] = 1
        elif j == 'd':
            QuestionInfo[i][6] = 1
        elif j == 'e':
            QuestionInfo[i][7] = 1
ErrorInfo = [[0,0,0,0,0] for i in range( M )]
for i in range( N ) :
    Sum = 0
    for num , j in enumerate( sys.stdin.readline().rstrip().rstrip(')').split(')')):
        homework = j.lstrip('(').split()
        Select = QuestionInfo[num][3:]
        for k in homework[1:]:
            if k == 'a':
                Select[0] -= 1
            elif k =='b':
                Select[1] -= 1
            elif k =='c':
                Select[2] -= 1
            elif k =='d':
                Select[3] -= 1
            elif k =='e':
                Select[4] -= 1
        flag = 0
        for order , k in enumerate(Select):
            if k == -1 :
                ErrorInfo[num][order]+=1
                flag = 1
            elif k == 1:
                ErrorInfo[num][order]+=1
                if not flag:
                    flag = 2
        if not flag:
            Score = QuestionInfo[num][0]
        elif flag==1:
            Score = 0
        else :
            Score = QuestionInfo[num][0]/2
        Sum += Score
    print( '%.1f'%Sum)
Max = 0
for i in ErrorInfo:
    tem = max( i )
    if tem > Max:
        Max = tem
if not Max:
    print('Too simple')
else:
    for i,test in enumerate( ErrorInfo ):
        for j,value in enumerate( test ):
            if value == Max:
                print( '%d %d-'%( Max , i+1 ),end = '')
                if j == 0:
                    print('a')
                elif j ==1:
                    print('b')
                elif j ==2:
                    print('c')
                elif j ==3 :
                    print('d')
                elif j ==4:
                    print('e')
