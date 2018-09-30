#include <stdio.h>//https://www.jianshu.com/p/ec4ccf1a76c8 讲得很清楚，我这里多了一个判断 一旦加法次数达到N-1直接跳出，数组大部分空余时可以节省时间
int main(void)
{
        int i , N , tem , data[ 10000 ] = { 0 } ;
        float sum ;
        scanf( "%d" , &N ) ;
        for( int i = 0 ; i < N ; i++ )
        {
                scanf( "%d" , &tem ) ;
                data[ tem - 1 ]++ ;
        }
        for( i = 0 ; i < 10000 ; i++ )
                if( data[ i ] )
                {
                        data[ i ]-- ;
                        sum = i + 1 ;
                        break ;
                }
        for( int cnt = 1 ; i < 10000 && cnt < N ; i++ )
        {
                while( data[i] )
                {
                        data[ i ]-- ;
                        sum += (i + 1) ;
                        sum /= 2 ;
                        cnt++ ;
                }
        }
        printf( "%d" , (int) sum ) ;
        return 0 ;
}
