#include<stdio.h>//如果想加快运行速度 可以考虑取消空格的判断 第一次只输出数字 不输出空格 后面的再输出空格加数值
int main(void)
{
        int M , N , A , B , Value ;
        scanf("%d %d %d %d %d", &M , &N , &A , &B , &Value ) ;
        int Tem ;
        for( int i = 0 ; i < M ; i++ )
        {
                for( int j = 0 ; j < N ; j++ )
                {
                        if( j )
                                printf(" ");
                        scanf( "%d" , &Tem );
                        if( Tem <= B && Tem >= A )
                                printf("%03d" , Value ) ;
                        else
                                printf("%03d" , Tem ) ;
                }
                putchar('\n');
        }
        return 0;
}
