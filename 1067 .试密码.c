#include<stdio.h>//注意尝试中的密码可以有空格等空白符 不要用scanf进行输入
#include<string.h>
int main(void)
{
        char Key[ 21 ] , Attempt[ 100 ] = "\0" ;
        int N ;
        scanf( "%s %d" , Key , &N ) ;
        getchar() ;
        gets( Attempt ) ;
        for( int i = 0 ; strcmp(Attempt , "#" ) ; fgets( Attempt , 100 , stdin ) , Attempt[ strlen(Attempt) - 1 ] = '\0')
        {
                if(strcmp( Attempt , Key))
                {
                        printf("Wrong password: %s\n", Attempt ) ;
                        i++ ;
                        if( i == N )
                        {
                                printf("Account locked") ;
                                break ;
                        }
                }
                else
                {
                        printf("Welcome in") ;
                        break ;
                }
        }
        return 0;
