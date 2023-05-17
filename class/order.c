#include <stdio.h>
#include <malloc.h>
#define TREEMAX 100
typedef struct BT
{
    char date;
    struct BT *lchild;
    struct BT *rchild;

}BT;
BT *CreateTree();//创建二叉树..
void ShowTree(BT *T,int nLayer);//显示二叉树
void Preorder(BT *T);//前序遍历
void Postorder(BT *T);//后序遍历
void Levelorder(BT *T);//层次遍历
void Inorder(BT *T);//中序遍历
void Leafnum(BT *T);//叶子数..
void Nodenum(BT *T);//求结点数..
int Treedepth(BT *T);//求树深度..

int count = 0;//结点数
int count1 = 0;//叶子数
void main ()
{
    BT *T =NULL;
    int ch1,ch2;//ch2 是输入选择项
    ch1 = 1;//标志
    int nlayer =0;//显示用的
    while (ch1)
    {
        printf("\n");
        printf("\n\t\t 二叉树系统 ");
        printf("****************************");
        printf("\n\t\t* 1建二叉树 *");
        printf("\n\t\t* 2凹入显示 *");
        printf("\n\t\t* 3先序遍历 *");
        printf("\n\t\t* 4中序遍历 *");
        printf("\n\t\t* 5后序遍历 *");
        printf("\n\t\t* 6层次遍历 *");
        printf("\n\t\t* 7求叶子数 *");
        printf("\n\t\t* 8求结点数 *");
        printf("\n\t\t* 9求树深度 *");
        printf("\n\t\t* 0返回 *");
        printf("****************************");
        printf("\n\t\t请选择（0-9）；");
        scanf("%d",&ch2);
        getchar();//清空输入区
        printf("\n");
        switch (ch2)
        {
        case 1:
            T = CreateTree();
            break;
        case 2:
            ShowTree(T,nlayer);
            break;    
        case 3:
            //Preorder(T);//前序遍历
            break;
        case 4:
            //Inorder(T);//中序遍历
            break;
        case 5:
            //Postorder(T);//后序遍历
            break;
        case 6:
            printf("\n\t\t该二叉树的层次遍历序列为\n");
            //Levelorder(T);//层次遍历
            break;
        case 7:
            count1 = 0;
            Leafnum(T);
            printf("\n\t\t该二叉树有 %d 个结点\n",count1);
            break;
        case 8:
            count = 0;
            Nodenum(T);
            printf("\n\t\t该二叉树有 %d 个结点\n",count);
            break;
        case 9:
            printf("\n\t\t该数深度是 %d \n",Treedepth(T));
            break;
        case 0:
            ch1 = 0;
            break;
                
        default:
            printf("\n\t\t输入错误\n");
        }//switch
        
    }//while
    
}
void Leafnum(BT *T)//叶子数
{
    if (T)
    {
        if (T->lchild==NULL && T->rchild==NULL)
            {
                count1++;
            }
        Leafnum(T->lchild);
        Leafnum(T->rchild);

    }
    
}
void Nodenum(BT *T)//求结点数
{
    if (T)
    {
        count++;
        Nodenum(T->lchild);
        Nodenum(T->rchild);

    }
    
}
BT *CreateTree()//创建二叉树
{
    BT *t;
    char x;
    printf("请输入结点字符\n");
    scanf("%c",&x);
    getchar();
    if (x =='0')
    {
        t = NULL;
    }else
    {
        t = (BT *)malloc(sizeof(BT));
        t->date = x;
        printf("请输入 %c 的左结点\n",x);
        t->lchild = CreateTree();
        printf("请输入 %c 的右结点\n",x);
        t->rchild = CreateTree();
    }
    return t;
}
int Treedepth(BT *T)//求树深度
{
    int ldepth,rdepth,max;
    if (T != NULL)
    {
        ldepth =Treedepth(T->lchild);
        rdepth = Treedepth(T->rchild);
        if (ldepth >rdepth)
        {
            max = ldepth + 1 ;
        }else
        {
            max = rdepth + 1 ;
        }
        return max;
    }
    return 0;
    
}
void ShowTree(BT *T,int nLayer)//显示二叉树
{
    BT *stack [TREEMAX],*p;
    int level[TREEMAX][2],top,n,i,width = 4;
    if (T != NULL)
    {
        int top =1;
        stack[top] = T;
        level[top][0]= width;
        while (top>0)
        {
            p = stack[top];
            n = level[top][0];
            for (int i = 0; i < n; i++)
            {
                printf(" ");
            }
            printf("%c",p);
            for (int i = 0; n+i < 30; i++)
            {
                printf("=");
            }
            printf("\n");
            top--;
            if (p->rchild != NULL)
            {
                top++;
                stack[top]= p->rchild;
                level[top][0]=n+width;
                level[top][1]=2;
            }
            if (p->lchild != NULL)
            {
                top++;
                stack[top]= p->lchild;
                level[top][0]=n+width;
                level[top][1]=1;
            }
        }  
    }
    printf("\n此树为空");
    
}
void Preorder(BT *T);//前序遍历
void Postorder(BT *T);//后序遍历
void Levelorder(BT *T);//层次遍历
void Inorder(BT *T);//中序遍历