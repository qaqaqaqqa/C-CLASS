#include <stdio.h>
#define MaxSize 12
typedef struct Queue
{
    int basic[MaxSize];
    int qFront;
    int qRear;
}queue;

void PushQueue  (queue *p,int n);//进队1
void PopQueue   (queue *p);//出队1
int EmptyQueeu  (queue *p);//判空1
void DoingQueue (queue *p);//队列情况
void ShowQueue  (queue *p);//显示队列
int FullQueue   (queue *p);//判满1


int main()
{
    queue *p;//队列里的指针
    p->qFront = 0;
    p->qRear = 0;
    printf("\n正在初始化.....");
    printf("\n初始化完成");
    int flag = 1;   //继续运行的标志
    int i;int c;int choice;   //i是序列；c是字符；choice 是选项
   while (flag)
    {
        printf("\n        菜单（链表）      ");
        printf("\n***************************");
        printf("\n  1.入    队");//
        printf("\n  2.出    队");//
        printf("\n  3.队列情况 ");//
        printf("\n  4.判    空");//
        printf("\n  5.显示队列 ");//
        printf("\n  8.返回 ");//
        printf("\n***************************");
        printf("\n");
        scanf("%d",&choice);
        getchar();
        if (choice == 1)
        {
             printf("\n请输入入队数字\n");
             scanf("%d",&c);
             PushQueue(p,c);
        }else if(choice ==2)
        {
            PopQueue(p); 
        }else if (choice == 3)
        {
            DoingQueue(p);
        }else if (choice == 4)
        {
           int flag = EmptyQueeu(p);
           if (flag ==1)
           {
            printf("\n队伍为空");
           }else if (flag == 0)
           {
            printf("\n队伍非空");
           }
           
           
        }else if (choice == 5)
        {
            ShowQueue(p);
        }else if (choice == 6)
        {
            
        }else if (choice == 7)
        {
           
            
        }
        else if (choice == 8)
        {
            flag = 0;
        }
    }

}

void PushQueue  (queue *p,int n)//进队
{
    if (FullQueue(p))
    {
            printf("\n错误，队满。\n");
            return;
    }else
    {
        p->basic[p->qRear] = n;
        p->qRear = (p->qRear +1 ) % MaxSize;
    }
    
    
}
void PopQueue   (queue *p)//出队
{
    if (EmptyQueeu(p))
    {
        printf("\n错误，队空\n");
        return;
    }else
    {
        int c;
        c =p->basic[p->qFront];
        p->qFront = (p->qFront + 1 ) % MaxSize;
        printf("\n出队成功 %d \n",c);
    }
    
    
}
int EmptyQueeu  (queue *p)//判空
{
    if (p->qFront == p->qRear)
    {
        return 1;//为空则返回1
    }else
    {
        return 0;//不为空则返回0
    }
}
void DoingQueue (queue *p)//队列情况
{
    int len = 0;    //初始长度
    int res = 0;    //剩余长度
    printf("\n队伍总长度为%d ",MaxSize - 1 );
    if (EmptyQueeu(p))
    {
        printf("\n队空");
        res = MaxSize -1 ;
    }else
    {
        printf("\n队不空");
            if (FullQueue(p))
            {
                 printf("\n队满 队长为 %d",MaxSize - 1);
                 res = 0;
            }else
            {
                int n = p->qFront;  //套用显示队列
                while (n != p->qRear)
                {
                     n = (n+1) % MaxSize;
                     len++;
                }
                printf("\n队不满 队长为 %d",len);  
                res = MaxSize - 1 - len;   
            }
    }
    printf("\n队伍剩余长度为%d ",res);
}
void ShowQueue  (queue *p)//显示队列
{
    if (EmptyQueeu(p))
    {
        printf("\n错误，队空\n");
        return;
    }else
    {
        int n = p->qFront ;
        while (n != p->qRear)
        {
            printf("%3d",p->basic[n]);
            n = (n+1) % MaxSize;
        }
    }
    
    
}
int FullQueue   (queue *p)//判满
{
    if ((p->qRear + 1) % MaxSize == p->qFront )
    {
        return 1; //队满返1
    }else
    {
        return 0;//否则返0
    }
    
    
}