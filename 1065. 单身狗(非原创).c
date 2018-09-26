//转载自https://blog.csdn.net/bawangtu/article/details/81394619
#include<stdio.h>
#define Single 1
int main( void )
{
        int N ;
        scanf("%d" , &N ) ;
        int Couple[ 100000 ] ;
        for( int i = 0 ; i < 100000 ; i++ )
                Couple[ i ] = -1 ;
        int Husband , Wife ;
        for( int i = 0 ; i < N ; i++ )
        {
                scanf("%d %d", &Husband , &Wife ) ;
                Couple[ Husband ] = Wife ;
                Couple[ Wife ] = Husband ;
        }
        int SingleDog[ 100000 ] = { 0 } ;
        int M ;
        scanf( "%d" , &M ) ;
        int Person , cnt = 0;
        for( int i = 0 ; i < M ; i++ )
        {
                scanf( "%d" , &Person ) ;
                SingleDog[ Person ]++ ;
                if( Couple[ Person ] != -1 && SingleDog[ Couple[ Person ] ] )
                {
                        cnt += 2 ;
                        SingleDog[ Person ]++ ;
                        SingleDog[ Couple[ Person ] ]++;
                }
        }
        M -= cnt ;
        printf( "%d" , M ) ;
        int i = 0 ,flag = 0;
        while( M )
        {
                if( SingleDog[i] == Single )
                {
                        if( flag )
                                printf(" %05d" , i ) ;
                        else
                        {
                                printf("\n%05d" , i );
                                flag = 1;
                        }
                        M-- ;
                }
                i++ ;
        }
        return 0 ;
}
