#include<stdio.h>
int main(void)
{
        int N;
        scanf("%d",&N);//循环次数
        int answer[N];
        char str[101];//存储字符串变量
        for(int i=0;i<N;i++)
        {
                int a=0,b=0,c=0;
                int cnt=0;//计数器
                int index=0;//字符串下标
                scanf( "%s" , str );
                while( str[ index ] == 'A' )
                {
                        cnt++;
                        index++;
                }
                a = cnt;//计算a部分有多少个A
                cnt = 0;
                if( str[ index++ ] != 'P' )
                {
                        answer[ i ]=0;
                        continue;
                }
                if( str[ index ] != 'A')
                {
                        answer[ i ]=0;
                        continue;
                }
                else
                {
                        while( str[ index ] == 'A')
                        {
                                cnt++ ;
                                index++ ;
                        }
                }
                b = cnt;//计算b部分有多少个A
                cnt = 0;
                if( str[ index++ ] != 'T' )
                {
                        answer[ i ] = 0;
                        continue;
                }
                if( str[ index ] == '\0' )
                        c = 0;
                else
                {
                        if( str[ index ] != 'A' )
                        {
                                answer[ i ] = 0;
                                continue;
                        }
                        while( str[ index ] == 'A' )
                        {
                                cnt++ ;
                                index++ ;
                        }
                }
                if( str[ index ] != '\0' )
                {
                        answer[ i ]=0;
                        continue;
                }
                else
                {
                        c = cnt;
                        if( b>1 )
                        {
                                if( a * b == c)
                                        answer[ i ] = 1;
                                else
                                        answer[ i ] = 0;
                        }
                        else
                        {
                                if ( a == c )
                                        answer[ i ] = 1;
                                else
                                        answer[ i ] = 0;
                        }
                }
        }
        for(int i=0;i<N;i++)
                if(answer[i])
                        puts("YES");
                else
                        puts("NO");
        return 0;
}

解题思路：
将输入字符串截成3部分,通过字符P和字符T截取为 a b c分别表示A的个数
那么根据条件2 当b=1时 a = c
根据条件3 当b>1时 c = a * (b-1)+c
由条件2知 c=a 那么 c = a*(b-1)+a = a*b
所以判断是否通过的条件就为a*b=c
