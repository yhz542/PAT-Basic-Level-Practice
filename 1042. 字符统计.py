string = input().strip()
Data = dict()
for i in string :
    if i.isalpha() :
        Data[ i.lower() ] = Data.get( i.lower() , 0 ) + 1
key = sorted( Data.keys() )
maxs = 0
for i in key :
    if Data[ i ] > maxs :
        maxs = Data[ i ]
        maxkey = i
print('%s %d'%( maxkey , maxs ) )
