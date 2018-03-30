运行超时
#include<stdio.h>
#include<stdlib.h>
enum grade { first , second , third , forth };
typedef struct Node Student ;
typedef struct Node *Ptr ;
struct Node
{
        int No;
        char Virtue;
        char Ability;
        Ptr Next;
};
int classify( Ptr , int , int ) ;
void Insert( Ptr , Ptr , int ) ;
int main(void)
{
        int N , L , H ;
        scanf("%d %d %d", &N , &L , &H ) ;
        Ptr S = ( Ptr ) malloc ( sizeof( Student ) * 4 ) ;
        for(int i = 0 ; i <4 ; i++)
                S[ i ]. Next = NULL ;
        Ptr New;
        int Count=0;
        for( int i = 0 ,Class; i < N ; i++ )
        {
                New = ( Ptr ) malloc ( sizeof( Student ) ) ;
                scanf("%d %d %d" , &New->No , &New->Virtue , &New->Ability ) ;
                Class = classify( New , L , H );
                if(Class == -1)
                        free( New );
                else
                {
                        Count++;
                        Insert( S , New , Class );
                }
        }
        printf("%d\n",Count);
        for( int i = 0 ; i < 4 ; i++ )
        {
                New = S[ i ]. Next ;
                while( New )
                {
                        printf("%d %d %d\n" , New->No , New->Virtue , New->Ability );
                        New = New->Next;
                }
        }
        return 0;
}
int classify( Ptr New , int L , int H )
{
        int Class = -1 ;
        if( New->Virtue >= L && New->Ability >= L)
        {
                if( New->Virtue >= H && New->Ability >= H )
                        Class = first ;
                else if( New->Virtue >= H && New->Ability < H )
                        Class = second ;
                else if( New->Virtue >= New->Ability )
                        Class = third ;
                else
                        Class =forth ;
        }
        return Class ;
}
void Insert( Ptr S , Ptr New , int Class)
{
        Ptr Head = &( S[ Class ] ) ;
        Ptr Current = Head -> Next ;
        Ptr Former = Head ;
        while(Current)
        {
                if( ( New->Virtue + New->Ability ) > ( Current->Virtue + Current->Ability ))
                        break ;
                else if ( ( New->Virtue + New->Ability ) == ( Current->Virtue + Current->Ability ) )
                {
                        if (  New->Virtue > Current->Virtue )
                                break ;
                        else if( ( New->Virtue == Current->Virtue ) && ( New->No < Current -> No ) )
                                break ;
                }
                Former = Current ;
                Current = Current -> Next ;
        }
        Former -> Next = New ;
        New -> Next = Current ;
}
