#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int transformation( char * );
int cmp(const void * , const void * );
void intostr( int , char *);
int main(void)
{
        char N[5] ;
        char n[5] ;
        scanf( "%s" , N ) ;
        int length = strlen( N ) ;
        if( length < 4 )
        {
                for( int  i = length ; i < 4 ; i++ )
                        N[ i ] = '0' ;
                N[ 4 ] = 0 ;
        }
        qsort( N , 4 , sizeof(char) , cmp ) ;
        for( int i = 0 ; i < 4 ; i++ )
        {
                n[ i ] = N[ 3 - i ] ;
        }
        n[4]=0;
        int New = transformation( n ) - transformation( N ) ;
        while( New != 6174 && New )
        {
                printf("%s - %s = %04d\n", n , N , New);
                intostr( New , N );
                qsort( N , 4 , sizeof(char) , cmp );
                for( int i = 0 ; i < 4 ; i++ )
                {
                        n[ i ] = N[ 3 - i ] ;
                }
                New = transformation( n ) - transformation( N ) ;
        }
        if( New == 6174)
                printf("%s - %s = %04d\n", n , N , New);
        else
                printf("%s - %s = 0000\n", n , N );
        return 0 ;
}
int cmp(const void *p1 , const void *p2 )
{
        const char *a1 = (const char *)p1 ;
        const char *a2 = (const char *)p2 ;
        return *a1-*a2;
}
int transformation( char *str )
{
        int num = 0 ;
        for( int i = 0 ; i < 3 ; i++ )
        {
                num += ( str[i] - '0') ;
                num *= 10 ;
        }
        num += ( str[ 3 ] - '0') ;
        return num;
}
void intostr( int num , char *str )
{
        str[ 0 ] = num / 1000 + '0';
        num %= 1000 ;
        str[ 1 ] = num / 100 + '0' ;
        num %= 100 ;
        str[ 2 ] = num / 10 + '0';
        num %= 10 ;
        str[ 3 ] = num + '0' ;
}
