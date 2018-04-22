#include<stdio.h>
int GetInput( char [][5] ) ;
int main(void)
{
        char hands[ 10 ][ 5 ] , eyes[ 10 ][ 5 ] , mouths[ 10 ][ 5 ];
        int len1 , len2 , len3 ;
        len1 = GetInput( hands ) ;
        len2 = GetInput( eyes ) ;
        len3 = GetInput( mouths ) ;
        int N ;
        scanf("%d", &N ) ;
        int a , b , c , d , e ;
        for( int i = 0 ; i < N ; i++ )
        {
                scanf("%d %d %d %d %d" , &a , &b , &c , &d , &e ) ;
                if( a > len1 || a < 1 || b > len2 || b < 1 || c > len3 || c < 1 || d < 1 || d > len2 || e <1 || e > len1 )
                        printf("Are you kidding me? @\\/@\n");
                else
                        printf("%s(%s%s%s)%s\n" , hands[ a-1 ] , eyes[ b - 1] , mouths[ c - 1 ] , eyes[ d - 1 ], hands[ e - 1 ] ) ;
        }
        return 0 ;
}
int GetInput( char Body[][5] )
{
        char c ;
        int cnt = 0 ;
        while( ( c = getchar() ) != '\n' )
        {
                if( c == '[' )
                {
                        int j = 0 ;
                        while( (c = getchar()) != ']' )
                        {
                                Body[ cnt ][ j ] = c ;
                                j++ ;
                        }
                        Body[ cnt ][ j ] = '\0' ;
                        cnt++ ;
                }
        }
        return cnt;
}
