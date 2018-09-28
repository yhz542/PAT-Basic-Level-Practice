#include<stdio.h>//https://blog.csdn.net/u011036919/article/details/68942343 分析的不错 如果有问题 这里应该都有答案
#include<stdlib.h>//这里没有把哈希表放上来 如果放哈希表 程序速度应该会更快
#include<math.h>
int Check( int ** , int , int , int ) ;
int Row , Column ;
int main( void )
{
        int M , N , TOL ;
        scanf("%d %d %d" , &M ,&N , &TOL ) ;
        int **Data = (int **)malloc( sizeof( int * ) * N );
        for( int i = 0 ; i < N ; i++ )
                Data[i] = (int *)malloc( sizeof( int ) * M ) ;
        for( int i = 0 ; i < N ; i++ )
                for( int j = 0 ; j < M ; j++ )
                        scanf( "%d" , &Data[ i ][ j ] ) ;
        int cnt =Check( Data , N , M , TOL );
        if( !cnt )
                printf("Not Exist") ;
        else if( cnt == 1 )
                printf("(%d, %d): %d", Column + 1 , Row + 1 , Data[ Row ][ Column ] ) ;
        else
                printf("Not Unique") ;
        return  0 ;
}
int Check( int **Data , int N , int M , int TOL )
{
        int cnt = 0 ;
        for( int i = 0 ; i < N ; i++ )
        {
                for( int j = 0 , flag = 0; j < M ; j++)
                {
                        flag = 0 ;
                        int startrow = i - 1 > 0 ? i - 1 : 0, startcolumn = j - 1 > 0 ? j - 1 : 0 ;
                        int endrow = i + 2 < N  ? i + 2 : N  , endcolumn = j + 2 < N  ? j + 2 : M ;
                        for( int x = startrow ; x < endrow ; x++ )
                        {
                                for( int y =startcolumn ; y < endcolumn ; y++ )
                                {
                                        if( x == i && y == j )//不计算自身和自身比较
                                                continue ;
                                        if( abs( Data[ i ][ j ] - Data[ x ][ y ] ) <= TOL )//如果插值不够大直接跳出
                                        {
                                                flag = 1 ;
                                                break ;
                                        }
                                }
                                if( flag )
                                        break ;
                        }
                        if( !flag )
                        {
                                int temcnt = 0 ;
                                for( int n = 0 ; n < N ; n++ )
                                {
                                        for( int m = 0 ; m < M ; m++ )
                                        {
                                                if(Data[ n ][ m ] == Data[ i ][ j ])
                                                {
                                                        temcnt++ ;
                                                        if(temcnt > 1 )
                                                                break ;
                                                }
                                        }
                                        if( temcnt > 1 )
                                                break ;
                                }
                                if( temcnt == 1 )
                                {
                                        cnt++ ;
                                        if( cnt > 1 )
                                        {
                                                return cnt;
                                        }
                                        Row = i ;
                                        Column = j ;
                                }
                        }
                }
        }
        return cnt ;
}
