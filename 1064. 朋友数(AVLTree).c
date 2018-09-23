#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int cnt = 0;
typedef struct TreeNode *AVLTree ;
typedef AVLTree Position ;
typedef int ElementType ;
struct TreeNode
{
        ElementType Data ;
        AVLTree Left ;//左子树
        AVLTree Right ;//右子树
        int Height ;//树高
};
Position Find( ElementType X , AVLTree BST ) ;
void InOrderTraversal( AVLTree );
int Max( int , int ) ;
int GetHeight( AVLTree );
AVLTree SingleLeftRotation( AVLTree ) ;
AVLTree SingleRightRotation( AVLTree) ;
AVLTree DoubleLeftRightRotation( AVLTree ) ;
AVLTree DoubleRightLeftRotation( AVLTree ) ;
AVLTree Insert( AVLTree , ElementType X ) ;
int main(void)
{
        int N ;
        scanf( "%d" , &N ) ;
        char Data[6] ;
        AVLTree T = NULL ;
        int Count = 0;
        for( int i = 0 ; i < N ; i++ )
        {
                scanf( "%s" , Data ) ;
                int  j = 0 , sum = 0 ;
                while( Data[j] != '\0' )
                {
                        sum += Data[ j ] - '0' ;
                        j++ ;
                }
                if( ! Find( sum , T )  )
                {
                        Count++ ;
                        T = Insert( T , sum ) ;
                }
        }
        printf( "%d\n" , Count );
        InOrderTraversal( T ) ;
        return 0;
}
Position Find( ElementType X , AVLTree BST )
{
        if( !BST )
                return NULL;
        if( X > BST->Data )
                return Find( X , BST->Right ) ;
        else if( X < BST->Data)
                return Find( X , BST->Left ) ;
        else
                return BST;//查找成功
}
int Max( int a , int b )
{
        return a > b ? a : b ;
}
AVLTree SingleLeftRotation( AVLTree A )
{
        AVLTree B = A->Left ;
        A->Left = B->Right ;
        B->Right = A ;
        A->Height = Max( GetHeight(A->Left) , GetHeight(A->Right))+1;
        B->Height = Max( GetHeight(B->Left) , A->Height)+1;
        return B;
}
AVLTree SingleRightRotation( AVLTree A )
{
        AVLTree B = A->Right ;
        A->Right = B->Left ;
        B->Left = A ;
        A->Height = Max( GetHeight(A->Left) , GetHeight(A->Right))+1;
        B->Height = Max( GetHeight(B->Right) , A->Height )+1;
        return B ;
}
int GetHeight( AVLTree A )
{
        int Height ;
        if( !A )
                Height = -1 ;
        else
                Height = A->Height ;
        return Height ;
}
AVLTree DoubleLeftRightRotation( AVLTree A )
{
        A->Left = SingleRightRotation(A->Left);
        return SingleLeftRotation(A);
}
AVLTree DoubleRightLeftRotation( AVLTree A )
{
        A->Right = SingleLeftRotation(A->Right) ;
        return SingleRightRotation( A ) ;
}
AVLTree Insert( AVLTree T , ElementType X )
{
        if(!T)
        {
                T=(AVLTree)malloc(sizeof( struct TreeNode ) );
                T->Data = X;
                T->Height = 0 ;
                T->Left = T->Right = NULL;
        }
        else if( X < T->Data )
        {
                T->Left = Insert( T->Left , X );
                if( GetHeight(T->Left) - GetHeight( T->Right ) == 2 )
                        if( X < T->Left->Data )
                                T = SingleLeftRotation( T );
                        else
                                T = DoubleLeftRightRotation( T ) ;
        }
        else if( X > T->Data )
        {
                T->Right = Insert( T->Right , X ) ;
                if( GetHeight( T->Left ) - GetHeight( T->Right ) == -2 )
                        if( X > T->Right->Data )
                                T = SingleRightRotation( T ) ;
                        else
                                T = DoubleRightLeftRotation( T ) ;
        }
        T->Height = Max( GetHeight( T->Left ) , GetHeight( T->Right ) ) + 1 ;
        return T ;
}
void InOrderTraversal( AVLTree BT )
{
        if( BT )
        {
                InOrderTraversal( BT->Left ) ;
                if( !cnt )
                        printf( "%d" , BT->Data ) ;
                else
                        printf( " %d" ,BT->Data ) ;
                cnt = 1;
                InOrderTraversal( BT->Right ) ;
        }
}
