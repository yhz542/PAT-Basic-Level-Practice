#include<stdio.h> //用到了strtof 将字符串转换为浮点数，并在不可转换的位置停止并把地址赋给end变量。
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
bool IsLegal( char [] ) ;
int main(void)
{
        int N ;
        float sum = 0 ;
        int cnt = 0 ;
        scanf( "%d" , &N ) ;
        char Data[ 1000 ] ;
        for( int i = 0 ; i < N ; i++ )
        {
                scanf( "%s" , Data ) ;
                if( IsLegal( Data ) )
                {
                        cnt++ ;
                        sum += atof( Data ) ;
                }
                else
                        printf("ERROR: %s is not a legal number\n", Data ) ;
        }
        printf(!cnt?"The average of 0 numbers is Undefined":"The average of %d number%s is %.2f",cnt,cnt==1?"":"s",sum/cnt);
        return 0 ;
}
bool IsLegal( char Data[] )
{
        bool flag = true ;
        int Length = strlen( Data ) ;
        char *end ;
        float num = strtof( Data , &end ) ;
        if( *end )//如果end不为空字符 说明遇到了不能转换的字符。则该字符串不合法
        {
                flag = false ;
        }
        if( flag )//判断小数点后位数是否超过2位
        {
                int index = Length - 1 ;
                for( int i = 0 ; i < Length ; i++ )
                        if( Data[ i ] == '.' )
                        {
                                index = i ;
                                break ;
                        }
                if( Length - index - 1 > 2 )
                        flag = false ;
        }
        if( flag )//字符串为数字，判断范围是否合法
                if( num > 1000 || num < -1000 )
                        flag = false ;
        return flag ;
}
