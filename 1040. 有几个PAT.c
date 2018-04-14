#include<stdio.h>
int main(void)
{
        char str[ 100001 ] ;
        scanf( "%s" , str ) ;
        int P = 0 , T = 0;
        int start , i ;
        for( i = 0 ; str[ i ] ; i ++ )//找到第一个A
        {
                if( str[ i ] == 'P' )
                       P++ ;
                else if( str[ i ] == 'A')
                {
                        start = i ;
                        break ;
                }
        }
        if( !str[ i ] )//处理特殊情况 ， 如果字符串中没有A ，直接遍历到尾，为了统一处理，使start指向尾巴前的一个下标，这样下次循环开始即可跳出。
                start = i - 1 ;
        for( i = start + 1 ; str[ i ] ; i++ )
        {
                if( str[ i ] == 'T' )
                        T++ ;
        }
        long long cnt = P*T ;
        for( i = start + 1 ; str[ i ] ; i++ )//遍历每一个A进行计算，直到结束。
        {
                if( str[ i ] == 'P' )
                        P++ ;
                else if( str[ i ] == 'T' )
                        T-- ;
                else
                        cnt += P*T ;
        }
        printf( "%d" , cnt % 1000000007 );
        return 0 ;
}
/*解题思路，以A为中心，对一个字母A来说，假如它的前面有10个字母P,后面有 4个字母'T'那么对于这个A来说，可以组成 10*4=40个PAT。那么根据这个思路，从遇到
的第一个字母'A'开始，依次向后面遍历，每遇到一个'A'就计算依次PAT的个数，遇到P就增加 P 的计数，遇到T就减小T的个数（注意T是越来越小的）
*/
