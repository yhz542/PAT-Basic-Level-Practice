C1 , C2 = map( int , input().split() )
ALL_TCK = C2 - C1
ALL_TIME = ALL_TCK / 100
if ALL_TIME - int( ALL_TIME ) >= 0.5 :
    ALL_TIME = int( ALL_TIME ) + 1
else :
    ALL_TIME = int( ALL_TIME )
hour = ALL_TIME // 3600
rest = ALL_TIME % 3600
minute = rest // 60
second = rest % 60
print("{:02d}:{:02d}:{:02d}".format(hour,minute,second))
