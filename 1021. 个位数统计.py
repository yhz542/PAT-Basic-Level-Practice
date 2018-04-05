import operator
N = input()
Data = {}
for i in N:
    Data[i] = Data.get(i,0)+1
Data = sorted( Data.items() ,key = operator.itemgetter(0))
for i,j in Data:
    print('{}:{}'.format(i,j))
