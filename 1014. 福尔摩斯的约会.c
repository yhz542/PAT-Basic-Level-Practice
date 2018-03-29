#include<stdio.h>
#include<ctype.h>
void PrintWeek( int );
void PrintHour( char );
int main(void)
{
        char One[ 61 ] ;
        char Two[ 61 ] ;
        scanf("%s%s",One,Two);
        const char *Pos;
        int i;
        for(i = 0 ; One[ i ] != '\0' ; i++ )
        {
                if( One[ i ] >= 'A' && One[ i ] <= 'G' )
                {
                        if( One[ i ] == Two [ i ] )
                                break;
                }
        }
        PrintWeek( One[ i ] - 'A' ) ;
        while( One[ ++i ] != '\0' )
        {
                if( ( One[ i ] <= 'N' && One[ i ] >= 'A' ) || isdigit( One[ i ] ) )
                {
                        if( One[ i ] == Two[ i ] )
                                break ;
                }
        }
        PrintHour( One[i] ) ;
        scanf( "%s%s" , One , Two) ;
        for( i = 0 ; One[ i ] != '\0' ; i++ )
        {
                if( isalpha( One[i] ) )
                        if( One[i] == Two[i] )
                                break;
        }
        printf( "%02d" , i );
        return 0;
}
void PrintWeek( int N )
{
        const char *WeekDay;
        switch(N)
        {
                case 0:
                        WeekDay = "MON" ;
                        break ;
                case 1:
                        WeekDay = "TUE" ;
                        break ;
                case 2:
                        WeekDay = "WED" ;
                        break ;
                case 3:
                        WeekDay = "THU" ;
                        break ;
                case 4:
                        WeekDay = "FRI" ;
                        break ;
                case 5:
                        WeekDay = "SAT" ;
                        break ;
                case 6:
                        WeekDay = "SUN" ;
                        break ;
        }
        printf( "%s" , WeekDay );
}
void PrintHour( char c )
{
        int hour ;
        if( isdigit( c ) )
                hour = c - '0' ;
        else
                hour = c - 'A' + 10 ;
        printf(" %02d:", hour ) ;
}
