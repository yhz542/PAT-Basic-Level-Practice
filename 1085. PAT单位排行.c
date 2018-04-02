#include<stdio.h>
#include<stdlib.h> //qsort malloc
#include<string.h> //用于比较字符串
#include<ctype.h> //用于转换小写字母
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
第二种 使用哈希表进行加速
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdbool.h>
typedef struct Node Student;
struct Node
{
        float Score ;
        char School[ 7 ] ;
        int Count;
};
int Index( const char *, int );
bool IsPrime( int );
Student *CreateTable( int );
float AddScore( const char , int );
void FindAndInsert( int , int []);
int cmp ( const void * , const void * );
int school_cnt = 0 ;
Student *Info = NULL ;
int main(void)
{
        int N , Size ;
        scanf( "%d" , &N ) ;
        Size=2*N+1;
        while(! IsPrime( Size ) )
                Size += 2;
        Info = CreateTable( Size );
        int school_index[N] ;
        for( int i = 0 ,index; i < N ; i++)
                FindAndInsert( Size , school_index );
        qsort(school_index , school_cnt , sizeof( int ) , cmp ) ;
        printf("%d\n" , school_cnt );
        for( int i = 0 , score = (int)Info[school_index[0]].Score , rank = 0; i < school_cnt ; i++ )
        {
                if(score > (int)Info[school_index[i]].Score)
                {
                        rank = i ;
                        score = (int)Info[school_index[i]].Score ;
                }
                printf("%d %s %d %d\n" , rank+1 , Info[school_index[i]].School , (int)Info[school_index[i]].Score , Info[school_index[i]].Count);
        }
        return 0 ;
}
int Index( const char *Key , int TableSize )
{
        unsigned int result = 0;
        while( *Key != '\0' )
                result = ( result<<5 ) + *Key++ ;
        return result % TableSize ;
}
Student *CreateTable(int Size)
{
        Student *Info = (Student *)malloc( sizeof( Student ) * Size ) ;
        for( int i = 0 ; i < Size ; i++ )
                Info[ i ].Count = 0 ;
        return Info ;
}
bool IsPrime(int number)
{
        bool prime=true;
        if(number % 5 ==0 && number != 5)
                return false;
        int i = (int)sqrt(number);
        for(i=(i%2)?i:i-1;i>2;i-=2)
        {
                if(number%i==0)
                {
                        prime=false;
                        break;
                }
        }
        return prime;
}
float AddScore( const char c , int Score )
{
        float realscore ;
        switch( c )
        {
                case 'T':
                        realscore = Score * 1.5 ;
                        break ;
                case 'A':
                        realscore = (float)Score ;
                        break ;
                case 'B':
                        realscore = Score / 1.5 ;
        }
        return realscore ;
}
void FindAndInsert( int Size , int school_index[])
{
        char Tem_No[ 7 ];
        int Tem_Score ;
        char Tem_School[ 7 ] ;
        scanf("%s %d %s", Tem_No , &Tem_Score , Tem_School );
        char *tem = Tem_School ;
        while( *tem != '\0' )
        {
                *tem = tolower( *tem ) ;
                tem++ ;
        }
        int index = Index( Tem_School , Size ) ;
        int flag = 0 ;
        int cnt = 0 ;
        while( !flag )
        {
                if( !Info[ index ].Count )
                {
                        strcpy( Info[ index ].School , Tem_School ) ;
                        Info[ index ].Score = AddScore( *Tem_No , Tem_Score );
                        Info[ index ].Count = 1 ;
                        school_index [ school_cnt ] = index ;
                        school_cnt ++ ;
                        flag = 1;
                }
                else if( !strcmp( Tem_School , Info[index].School ) )
                {
                        Info[ index ].Score += AddScore( *Tem_No , Tem_Score ) ;
                        Info[ index ].Count++ ;
                        flag = 1;
                }
                else
                {
                        if(++cnt%2)
                        {
                                index = index +(cnt+1)/2*(cnt+1)/2 ;
                                if( index >= Size)
                                        index = index % Size ;
                        }
                        else
                        {
                                index -= cnt/2*cnt/2 ;
                                if( index < 0 )
                                        index += Size ;
                        }
                }
        }
}
int cmp ( const void *p1 , const void *p2 )
{
        const int *a1 = (const int *)p1 ;
        const int *a2 = (const int *)p2 ;
        int score1 = (int)Info[ *a1 ].Score ;
        int score2 = (int)Info[ *a2 ].Score ;
        if( score1 > score2 )
                return -1 ;
        else if( score1 == score2 )
        {
                if( Info[ *a1 ].Count < Info[ *a2 ].Count )
                        return -1 ;
                else if( Info[ *a1 ].Count == Info[ *a2 ].Count )
                        return strcmp( Info[ *a1 ].School , Info[ *a2 ].School ) ;
                else
                        return 1 ;
        }
        else
                return 1 ;
}
