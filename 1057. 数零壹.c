#include<stdio.h>//简洁版
#include<ctype.h>
void Binary( int ) ;
int zero = 0 , one = 0 ;
int main(void)
{
        char c ;
        int N = 0 ;
        while( ( c = getchar() ) != '\n' )
                if( isalpha( c ) )
                        N += tolower( c ) - 'a' + 1 ;
        Binary( N ) ;
        printf("%d %d" , zero , one ) ;
        return 0 ;
}
void Binary( int N )
{
        if( N == 1 || N == 0 )
        {
                if( N )
                        one++ ;
        }
        else
        {
                if( N & 1 )
                        one++ ;
                else
                        zero++ ;
                Binary( N >> 1 ) ;
        }
}
//原版
/*
#include<stdio.h>
#include<ctype.h>
void Binary( int ) ;
int zero = 0 , one = 0 ;
int main(void)
{
        char str[ 100001 ] ;
        gets( str ) ;
        int index = 0 , N = 0 ;
        while( str[ index ] != '\0' )
        {
                if( isalpha( str[ index ] ) )
                        N += tolower( str[ index ] ) - 'a' + 1 ;
                index++ ;
        }
        if( N )
        {
                Binary( N ) ;
                printf("%d %d" , zero , one ) ;
        }
        else
                printf("0 0");
        return 0 ;
}
void Binary( int N )
{
        if( N == 1 || N == 0 )
        {
                if( N )
                        one++ ;
                else
                        zero++ ;
        }
        else
        {
                Binary( N / 2 ) ;
                if( N % 2 )
                        one++ ;
                else
                        zero++ ;
        }
}
*/
