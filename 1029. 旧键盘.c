#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void)
{
        char theory[ 81 ];
        char reality[ 81 ];
        char answer[ 81 ];
        scanf( "%s %s" , theory , reality ) ;
        int i,j,k;
        for( i = 0 , j = 0 , k = 0; reality[ j ] != '\0' ; )
        {
                if( theory[ i ] == reality [ j ] )
                {
                        i++ ;
                        j++ ;
                }
                else
                {
                        answer[ k++ ] = theory[ i++ ];
                }
        }
        if( theory[ i ] != '\0')
                strcpy( &answer[k] , theory+i );
        else
                answer[ k ] = '\0' ;
        k = strlen( answer ) ;
        for( int i = 0 ; i < k ; i++ )
        {
                answer[ i ] = toupper( answer[i] ) ;
                for(int j = 0 ; j < i ; j++ )
                {
                        if( answer[ i ] == answer[ j ] )
                        {
                                answer[ i ] = -1 ;
                                break ;
                        }
                }
        }
        for(int i = 0 ; i < k ; i++ )
        {
                if(answer[i] != -1)
                        printf("%c",answer[i]);
        }
        return 0;
}
//hash表解法 ASCII表中 0-9实际对应48-57 A-Z对应65-90 _对应95直接取100作为hash表大小， 字符转换为大写后取其整数值作为地址下标。
#include<stdio.h>
#include<ctype.h>
int Find( char ) ;
void Insert( char * , int );
int main(void)
{
        char HashTable[ 100 ] = { 0 } ;
        char theory[ 81 ] ;
        scanf( "%s\n" , theory ) ;
        char tem ;
        int Position ;
        while( 1 )
        {
                scanf( "%c" , &tem ) ;
                if( '\n' == tem )
                        break ;
                Position = toupper( tem ) ;
                HashTable[ Position ] = 1 ;
        }
        int i = 0 ;
        while( theory[ i ] )
        {
                Position = toupper( theory[ i ] ) ;
                if( !HashTable[ Position ] )
                {
                        printf( "%c" , Position ) ;
                        HashTable[ Position ] = 1 ;
                }
                i++;
        }
        return 0;
}
