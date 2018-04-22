from math import *
R1 , P1 , R2 , P2 = map( float , input().split() )
A = R1 * R2 * cos( P1 ) * cos( P2 ) - R1 * R2 * sin( P1 ) * sin( P2 )
B = R1 * R2 * cos( P1 ) * sin( P2 ) + R1 * R2 * sin( P1 ) * cos( P2 )
A = 0 if -0.004 <= A <= 0.004 else A
B = 0 if -0.004 <= B <= 0.004 else B
print( '%.2f'%A , end = '' )
print( '{}{:.2f}i'.format( '+' if B >= 0 else '' , B ) ) 
#注意当为负数且绝对值小于等于0.004时 会约成 0 ，在输出时的负号需要去掉。
