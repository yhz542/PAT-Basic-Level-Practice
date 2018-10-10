#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum { GP , GM , GF };
typedef struct TreeNode *AVLTree ;
typedef AVLTree Position ;
typedef char ElementType ;
struct TreeNode
{
        ElementType StudentID[ 21 ] ;
        int score[ 4 ] ;
        AVLTree Left ;//左子树
        AVLTree Right ;//右子树
        int Height ;//树高
};
typedef struct NData *Node ;
struct NData
{
        int score[ 4 ] ;
        char StudentID[ 21 ] ;
};
Position Find( ElementType [] , AVLTree BST ) ;
int Max( int , int ) ;
int GetHeight( AVLTree );
AVLTree SingleLeftRotation( AVLTree );
AVLTree SingleRightRotation( AVLTree) ;
AVLTree DoubleLeftRightRotation( AVLTree );
AVLTree DoubleRightLeftRotation( AVLTree );
AVLTree Insert( AVLTree , ElementType [] ) ;
void InOrderTraversal( AVLTree );//中序遍历
int cmp( const void * , const void *);
int tem , flag ;
Position *Data = NULL ;
int cnt = 0;
int main( void )
{
        int P , M , N ;
        AVLTree T = NULL ;
        Position pos;
        scanf( "%d %d %d", &P , &M , &N ) ;
        Data = ( Position * )malloc( sizeof( Position ) * ( P + M + N ) ) ;
        char StudentID[ 21 ] ;
        flag = GP ;
        for( int i = 0 ; i < P ; i++ )
        {
                scanf( "%s %d" , StudentID , &tem ) ;
                T = Insert( T , StudentID ) ;
        }
        flag = GM ;
        for( int i = 0 ; i < M ; i++ )
        {
                scanf( "%s %d" , StudentID , &tem ) ;
                pos = Find( StudentID , T ) ;
                if( !pos )
                        T = Insert( T , StudentID ) ;
                else
                        pos->score[ flag ] = tem ;
        }
        flag = GF ;
        for( int i = 0 ; i < N ; i++ )
        {
                scanf( "%s %d" , StudentID , &tem ) ;
                pos = Find( StudentID , T ) ;
                if( !pos )
                        T = Insert( T , StudentID );
                else
                        pos->score[ flag ] = tem ;
        }
        InOrderTraversal( T ) ;
        qsort( &Data[0] , cnt , sizeof( Position ) , cmp ) ;
        for( int i = 0 ; i < cnt ; i++ )
                printf("%s %d %d %d %d\n",Data[i]->StudentID , Data[ i ]->score[ 0 ] ,
                Data[i]->score[ 1 ],Data[i]->score[ 2 ],Data[i]->score[3]);
}
void InOrderTraversal( AVLTree BT )
{
        if( BT )
        {
                InOrderTraversal( BT->Left ) ;
                if( BT->score[ GP ] >= 200 )
                {
                        float G ;
                        if( BT->score[ GM ] > BT->score[ GF ] )
                                G = ( ( BT->score[ GM ] << 2 ) + BT->score[ GF ] * 6 )/10.0 ;
                        else
                                G = BT->score[ GF ] ;
                        int Gscore = (int)G ;
                        Gscore = ( G - Gscore > 0.5 ? Gscore + 1 : Gscore ) ;
                        BT->score[ 3 ] = Gscore ;
                        if( Gscore >= 60 )
                                Data[ cnt++ ] = BT ;
                }
                InOrderTraversal( BT->Right ) ;
        }
}
Position Find( ElementType X[] , AVLTree BST )
{
        if( !BST )
                return NULL;
        if( strcmp( X , BST->StudentID ) > 0 )
                return Find( X , BST->Right ) ;
        else if( strcmp( X , BST->StudentID ) < 0 )
                return Find( X , BST->Left ) ;
        else
                return BST;//查找成功
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
AVLTree Insert( AVLTree T , ElementType X[] )
{
        if(!T)//如果当前为空树，创建并插入子节点
        {
                T=(AVLTree)malloc(sizeof( struct TreeNode ) );
                T->score[ 0 ] = -1 ;
                T->score[ 1 ] = -1 ;
                T->score[ 2 ] = -1 ;
                strcpy( T->StudentID , X ) ;
                T->score[ flag ] = tem ;
                T->Height = 0 ;
                T->Left = T->Right = NULL;
        }
        else if( strcmp( X , T->StudentID ) < 0 )//插入左边
        {
                T->Left = Insert( T->Left , X );
                if(  GetHeight(T->Left) - GetHeight( T->Right ) == 2 )
                {
                        if( strcmp(X , T->Left->StudentID ) < 0 )
                                T = SingleLeftRotation( T );
                        else
                                T = DoubleLeftRightRotation( T ) ;
                }
        }
        else if( strcmp( X , T->StudentID ) > 0 )//插入右边
        {
                T->Right = Insert( T->Right , X ) ;
                if(  GetHeight( T->Left ) - GetHeight( T->Right ) == -2 )
                {
                        if( strcmp( X , T->Right->StudentID ) > 0 )
                                T = SingleRightRotation( T ) ;
                        else
                                T = DoubleRightLeftRotation( T ) ;
                }
        }
        T->Height = Max( GetHeight( T->Left ) , GetHeight( T->Right ) ) + 1 ;
        return T ;
}
int cmp( const void *a , const void *b )
{
        Position A = *(Position *) a ;
        Position B = *(Position *) b ;
        int differ = A->score[ 3 ] - B->score[ 3 ] ;
        if(  differ > 0 )
                return -1;
        else if( differ < 0 )
                return 1 ;
        else
                return strcmp( A->StudentID , B->StudentID ) ;
}
