def Check( Data , N , M , TOL , Times ):#思想和c语言版本差不多 唯一不同的是这里检查元素个数时用到了哈希表也就是字典，这个比遍历快多了，并且这个
    cnt = 0                             #是先检查个数是否为1 再判断 与C语言版本顺序不一样。不过PYTHON速度太慢 最花时间的测试点运行超时
    for i , item in enumerate( Data ):  #这个版本在逻辑结构上应该比C语言版本更快，但是受限于语言速度问题 ，结果不尽如人意
        for j , value in enumerate( item ):
            if Times[ value ] > 1 :
                continue
            startrow = i - 1 if i - 1 > 0 else 0
            startcolumn = j - 1 if j - 1 > 0 else 0
            endrow = i + 2 if i + 2 < N else N
            endcolumn = j + 2 if j + 2 < M else M
            flag = 0
            for element in Data[ startrow : endrow ]:
                for Item in element[ startcolumn : endcolumn ] :
                    if value == Item:
                        continue
                    if abs( value - Item ) <= TOL :# 对于一个像素来说，只要周边有一个像素不满足条件直接跳出测试 加快运行速度。
                        flag = 1
                        break
                if flag :#继续跳出 测试像一个像素点。加快运行速度
                    break
            else:
                cnt += 1
                if cnt > 1:#当有两个元素满足条件直接跳出函数，加快运行速度。
                    return cnt
                global row
                row = i
                global column
                column = j
    return cnt

M , N , TOL = map( int , input().split() )
Data = []
Times ={}
row = 0
column = 0
for i in range( N ):
    tem = list( map( int , input().split() ) )
    for j in tem:
        Times[ j ] = Times.get( j , 0 ) + 1
    Data.append( tem )
cnt = Check( Data , N , M , TOL ,Times)
if not cnt :
    print('Not Exist')
elif cnt == 1 :
    print('({}, {}): {}'.format(column+1,row+1,Data[row][column]))
else:
    print('Not Unique')
