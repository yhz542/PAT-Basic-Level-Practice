#include <stdio.h>
void Print(char *,int );
int main(void)
{
        char sentence[ 81 ] ;
        gets(sentence);
        Print( sentence , 0 );
        return 0;
}
void Print(char *sentence ,int start )
{
        int end;
        while( sentence [ start ] == ' ' )
                start++ ;
        end = start ;
        while( sentence [ end ] != ' ' && sentence [ end ] != '\0')
                end++ ;
        if( sentence [ end ] == '\0')
        {
                for( int i = start ; i < end ; i++)
                        putchar( sentence[ i ] );
                return;
        }
        else
                Print( sentence , end );
        putchar(' ');
        for( int i = start ; i < end ; i++)
                        putchar( sentence[ i ] );
}
递归求解
