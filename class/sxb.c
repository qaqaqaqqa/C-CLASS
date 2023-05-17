#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef struct SepList
{
    char Data[MAXSIZE];
    int Last;
}SepList;

//建表
SepList * CreateSeplist (SepList *L)
{
    int flag = 1;//标志
    char e;//输入的
    int i = 0;//角标
    printf("逐个输入，以x结尾");
    printf ("\n");
    while (flag)
    {
        scanf("%c",&e);
        getchar();
        if (e != 'x')
        {
            L->Data[i] = e;
            i++;
        }
        else flag = 0;

    };
    L->Last = i-1;//记录last下标;
    return L;
    
}

int InsList(SepList *L,int i,char e);   //插入
int DelList(SepList *L,int i);          //删除
int ShowList(SepList *L);               //显示
int SerchList(SepList *L,char e);       //查找
int LenList(SepList *L);                //表长


int main ()
{
    int choice,i,j=1;//j是标志 choice 是选选择的 i是位序
    char e;//原石
    int n;//表长
    SepList *L;//顺序表指针L
    L = (SepList *)malloc(sizeof ( struct SepList));//申请空间
    L->Last = -1;//空值
    while (j)
    {
        printf("\n        菜单（顺序表）      ");
        printf("\n***************************");
        printf("\n1.建表 ");
        printf("\n2.插入 ");
        printf("\n3.删除 ");
        printf("\n4.显示 ");
        printf("\n5.查找 ");
        printf("\n6.求表长 ");
        printf("\n7.返回 ");
        printf("\n***************************");
        printf("\n");
        scanf("%d",&choice);
        //getchar();
        if (choice == 1)     
        { 
            L = CreateSeplist(L);//建表
        }
        if (choice == 2) 
        {
            printf ("请输入想要插入到第几个什么东西\n");
            scanf("%d %c",&i,&e);
            InsList(L,i,e);
        }
         if (choice == 3)
        {
            printf ("请输入想要删除第几个\n");
            scanf("%d",&i);
            DelList(L,i);
        }

        if (choice == 4)
        {
            ShowList(L);
        }
         if (choice == 5)
        {
            printf ("请输入想要搜索什么\n");
            scanf("%c",&e);
            SerchList(L,e);
        }
         if (choice == 6)
        {
            LenList(L);
        }
        if (choice == 7)
        {
            j = 0;
        }

    }
    


}

int InsList(SepList *L,int i,char e)    //插入
{
    if (i<1 || i>(L->Last+2))
    {
        printf("错误");
        return 0;
    }
    if (L->Last >= MAXSIZE -1)
    {
        printf("超过顺序表的长度\n");
        return 0;
    }
    L->Last += 1;
    int k = L->Last;
    int j=(i-1);
    for(k;k>j;k--){
        L->Data[k] = L->Data[k-1];
    };
    L->Data[j] = e;
    return 1;

}

int ShowList(SepList *L)        //显示
{
    int i=0;
    for ( i = 0; i <= L->Last; i++)
    {
        printf("%c ",L->Data[i]);
    }
    
}

int DelList(SepList *L,int i)   //删除
{
    if (i<1 || i>(L->Last+1))
    {
        printf("错误\n");
        return 0;
    }
    int k = i-1;
    for (k ;k < L->Last ;k++)
    {
        L->Data[k] = L->Data[k+1];
    }
    L->Last --;
    return 1;
}

int SerchList(SepList *L,char e)     //搜索
{
    int i;
    for (i=0;i<= L->Last;i++)
    {
        if(L->Data[i] == e)
        {
            printf ("找到了，在第 %d 个\n", i+1);
            return 1;
        }
    }
    printf ("找不到哦哦\n");
    return 0;
    
}

int LenList(SepList *L)         //表长
{
    printf ("表长为 %d \n",L->Last +1);
}