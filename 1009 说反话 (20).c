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
#include <stdio.h>
int Print(void);
int main(void)
{
        Print();
        return 0;
}
int Print(void)
{
        char c[81];
        int Count;
        if(scanf("%s",c)!=EOF)
        {
                Count=Print();
                if(!Count)
                        printf("%s",c);
                else
                        printf(" %s",c);
                return Count+1;
        }
        else
                return 0;
}
