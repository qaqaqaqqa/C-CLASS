#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct Node
{
    int data;
    struct Node * next;
}LinkStackNode;
typedef struct 
{
    int Len;
    LinkStackNode *top;
}LinkStack;
LinkStack *s;


void InitList (LinkStack * * s);    //初始化
int PushList (LinkStack *s,int *x);   //进栈
int  SEmpty (LinkStack *s);     //判空
int PopLint (LinkStack *s);    //出栈
int change  (LinkStack *s,int n);    //数制转换



int main ()
{
    InitList (&s);  //初始化
    int flag = 1;   //继续运行的标志
    int i;int c;int choice;   //i是判空；c是字符；choice 是选项
   while (flag)
    {
        printf("\n        菜单      ");
        printf("\n***************************");
        printf("\n  1.进栈 ");//
        printf("\n  2.出栈 ");//
        printf("\n  3.查询多少个");//
        printf("\n  4.判空");//
        printf("\n  5.数制转换");//
        printf("\n  8.返回 ");//
        printf("\n***************************");
        printf("\n");
        scanf("%d",&choice);
        getchar();
        if (choice == 1)
        {
            printf ("\n请直接输入数字\n");
                int x;
                scanf("%d",&x);
                PushList (s,&x);
  
            
        }else if(choice ==2)
        {
           int c =  PopLint (s);
           printf("\n%d\n",c);
        }else if (choice == 3)
        {
            printf ("\n一共有 %d 个\n",s->Len);
        }else if (choice == 4)
        {
            i = SEmpty (s);
            if (i == 1)
            {
                printf("\n空\n");
            }else if (i == 0)
            {
                printf("\n非空\n");
            }
            
        }else if (choice == 5)
        {
            int m;  //输入的数
            scanf("%d",&m);
            change(s,m);
        }
        else if (choice == 8)
        {
            flag = 0;
        }
    }
    


}

void InitList (LinkStack * * s)
{
    (*s) = (LinkStack *)malloc(sizeof(LinkStack));
    (*s)->top = NULL;
    (*s)->Len = 0;
}

int PushList (LinkStack *s,int *x)
{
        
            s->Len ++;
            LinkStackNode *p;
            p = (LinkStackNode *) malloc (sizeof(LinkStackNode));
            p->data = (*x);
            p->next = s->top;
            s->top = p;
        
    return 0;
}

int SEmpty (LinkStack *s)
{
    if (s->top == NULL)
    {
        //printf("\n空\n");
        return 1;
    }else {
        //printf("\n非空\n");
        return 0;
    }
    
}

int PopLint (LinkStack *s)
{
    if (SEmpty(s))
    {
        printf("队空，出栈失败");
        return 0;
    }else
    {
    s->Len --;
    int c;
    c = s->top->data;
    LinkStackNode *p;
    // p = (LinkStackNode *) malloc (sizeof(LinkStackNode));
    p = s->top;
    s->top = s->top->next;
    free(p);
    return c;
    }
    
}
    
int change  (LinkStack *s,int m)
{
    if (! SEmpty(s))
    {
        printf("\n栈不是空的，错误\n");
        return 0;
    }
    
    int temp;   //临时数
    while (m>0)
    {
        temp =  m % 2;
        PushList(s,&temp);
        m = m / 2;
    }
    printf("*\n*");
    int c;
    while (! SEmpty(s))
    {
        c =  PopLint (s);
        printf("%d",c);
    }
    
}