#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct Node //定义结构体类型
{
    char data;
    struct Node * next; 
}Node,* LinkList;

LinkList InitList (LinkList L) //初始化
{
    L = (LinkList)malloc(sizeof(Node)); //开阔空间
    L->next = NULL; //指向空
    return L;   //返回指针
}

int LenList (LinkList L)       //求表长
{
    if(L->next == NULL){
        return 0;
    }
    Node *p;
    p = (Node *)malloc (sizeof(Node));
    p = L->next;
    int j = 1;
    while (p->next != NULL)
    {
        p = p->next;
        j++;
    }
    int len = j;
    //printf ("\n 一共有 %d 个 ",len);
    return len;

}

void CreatFromHead (LinkList L) //头插法建表
{
    if(LenList(L) != 0)
    {
        return;
    }
    char c; int flag = 1; Node *s;
    while (flag)
    {
        c = getchar();
        if(c != '$')
        {
        s = (Node *)malloc(sizeof(Node));
        s->data = c;
        s->next = L->next;
        L->next = s;
        }
        else    flag = 0;
    }
    
}

void ShowList (LinkList L)  //展示
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p = L->next;
    printf ("\n");
    while (p->next != NULL)
    {
        printf (" %c",p->data);
        p = p->next;
    }
    printf (" %c",p->data);
    

}

void Serchi (LinkList L,int i)  //搜索第几个
{
    if(i<1)
    {
        printf ("\n 错误");
        return;
    }
    Node *p;
    p = (Node *)malloc (sizeof(Node));
    p = L;
    int j =0;
    while(j != i && p->next != NULL)
    {
        p = p->next;
        j++;
    } 

    if (j == i && p->data !='\n'){
        printf ("\n %c",p->data);
    }
    else {
        printf ("\n 找不到哦");
     }

}

void Serchc (LinkList L,char c) //搜索字符
{
    Node *p;
    p = (Node *)malloc (sizeof(Node));
    p = L->next;
    int j =1;
    while (p->data != c && j<LenList(L))
    {
        p = p->next;
        j++;
    }
    if (p->data == c)
    {
        printf ("\n 在第 %d 个",j);
    }else {
        printf ("\n 找不到哦");
    }
    
    
}

void DelList (LinkList L,int i) //删除
{
    if (i<1 || i> LenList(L))
    {
        printf ("错误");
        return;
    }
    Node *p;
    p = (Node *)malloc (sizeof(Node));
    p = L->next;
    int j=1;
    if (i = 1)
    {
        L->next = p->next;
        free(p);
    }else {
        while (j != i-1)
        {
            p = p->next;
            j++;
        }
        Node *s;
        s = (Node *)malloc (sizeof(Node));
        s = p->next;
        p->next = p->next->next;
        free(s);
    }


}

void AddList (LinkList L,int i,char c) //插入
{
    if (i<1 || i> LenList(L) +1 )

    {
        printf ("错误");
        return;
    }
        Node *s;
        s = (Node *)malloc (sizeof(Node));
        s->data = c;

        Node *p;
        p = (Node *)malloc (sizeof(Node));
        p = L->next;

        int j =1;
        if (i>1)
        {
        while (j != i-1)
        {
            p = p->next;
            j++;
        }
        s->next = p->next;
        p->next =s;
        }else if (i ==1 )
        {
            s->next = p;
            L->next = s;
        }
    
}

int main () //主函数
{   
    LinkList L;
    L = InitList(L);    //初始化
    int flag = 1;   //继续运行的标志
    int i;char c;int choice;   //i是序列；c是字符；choice 是选项
   while (flag)
    {
        printf("\n        菜单（链表）      ");
        printf("\n***************************");
        printf("\n  1.建表 ");//
        printf("\n  2.插入 ");//
        printf("\n  3.删除 ");//
        printf("\n  4.显示 ");//
        printf("\n  5.查找序列 ");//
        printf("\n  6.查找字符 ");//
        printf("\n  7.求表长 ");//
        printf("\n  8.返回 ");//
        printf("\n***************************");
        printf("\n");
        scanf("%d",&choice);
        getchar();
        if (choice == 1)
        {
            printf ("\n请直接输入字符，以 $ 结束\n");
            CreatFromHead(L);
        }else if(choice ==2)
        {
            printf ("\n序列 字符(用空格隔开)\n");
            scanf("%d %c",&i,&c);
            AddList (L,i,c);
        }else if (choice == 3)
        {
            printf ("\n序列\n");
            scanf("%d",&i);
            DelList(L,i);
        }else if (choice == 4)
        {
            ShowList(L);
        }else if (choice == 5)
        {
            printf ("\n序列\n");
            scanf("%d",&i);
            Serchi (L,i);
        }else if (choice == 6)
        {
            printf ("\n字符\n");
            scanf("%s",&c);
            Serchc (L,c);
        }else if (choice == 7)
        {
            printf ("一共有 %d 个",LenList (L));
            
        }
        else if (choice == 8)
        {
            flag = 0;
        }
    }
    


}
 

