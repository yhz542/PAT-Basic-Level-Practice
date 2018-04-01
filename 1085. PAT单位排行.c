#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct Node Student;
struct Node
{
        char No[ 7 ];
        int Score ;
        char School[ 7 ] ;
        int num;
};
int cmp1(const void *p1,const void *p2);
int calculate(int [],int *,int );
int cmp2(const void *p1,const void *p2);
Student *Info = NULL;
int main(void)
{
        int N;
        scanf( "%d" , &N );
        Info = ( Student * )malloc( sizeof( Student ) * N ) ;
        int Index[N];
        int num[N+1];
        for( int i = 0 ; i < N ; i++ )
                Index[i] = i ;
        for ( int i = 0 ; i < N ; i++ )
        {
                scanf( "%s %d %s" , Info[i].No , &Info[i].Score , Info[i].School );
                for(int j = 0 , Length = strlen( Info[i].School ) ; j < Length ; j++ )
                        Info[i].School[j] = tolower( Info[i].School[j] );
        }
        qsort(Index, N , sizeof(int) , cmp1 );
        int Length=calculate(Index,num,N);
        qsort(Index,Length+1,sizeof(int),cmp2);
        printf("%d\n",Length+1);
        for ( int i = 0 ,rank = 0,score=Info[Index[0]].Score; i<=Length ; i++ )
        {
                if(Info[Index[i]].Score < score)
                {
                        rank = i;
                        score = Info[Index[i]].Score ;
                }
                printf( "%d %s %d %d\n" , rank+1 , Info[Index[i]].School , Info[Index[i]].Score , Info[Index[i]].num );
        }
        return 0 ;
}
int cmp1(const void *p1,const void *p2)
{
        const int *a1 = (const int *)p1;
        const int *a2 = (const int *)p2;
        int n=strcmp(Info[*a1].School,Info[*a2].School);
        if(n>0)
                return 1;
        else if(!n)
                return 0;
        else
                return -1;
}
int calculate(int Index[],int num[],int N)
{
        char *tem_name = Info[Index[0]].School;
        float tem_score=0;
        int cnt = 0 ;
        int rank=0;
        int tem;
        for( int i = 0 ; i < N ; i++ )
        {
                tem = Index[i];
                if(!strcmp(tem_name,Info[tem].School))
                {
                        cnt++;
                        switch(Info[ tem ].No[0])
                        {
                                case 'T':
                                        tem_score += 1.5*Info[tem].Score;
                                        break;
                                case 'A':
                                        tem_score += Info[tem].Score;
                                        break;
                                case 'B':
                                        tem_score += (Info[tem].Score/1.5);
                        }
                }
                else
                {
                        Info[ Index[rank ]].num = cnt ;
                        cnt = 0 ;
                        Info[ Index[rank] ].Score = (int)tem_score;
                        tem_score = 0 ;
                        strcpy(Info[ Index[rank] ].School , tem_name);
                        tem_name = Info[tem].School ;
                        rank++;
                        i--;
                }
        }
        Info[ Index[rank ]].num = cnt ;
        Info[ Index[ rank ] ].Score = (int)tem_score;
        strcpy(Info[ Index[rank] ].School , tem_name);
        return rank;
}
int cmp2(const void *p1,const void *p2)
{
        const int *a1 = (const int *)p1;
        const int *a2 = (const int *)p2;
        Student *one=&(Info[*a1]);
        Student *two=&(Info[*a2]);
        if(one->Score > two->Score)
                return -1;
        else if(one->Score == two->Score)
        {
                if(one->num < two->num)
                        return -1;
                else if(one->num == two->num )
                {
                        if(strcmp(one->School,two->School)<1)
                                return -1;
                        else
                                return 1;
                }
                else
                        return 1;
        }
        else
                return 1;
}
