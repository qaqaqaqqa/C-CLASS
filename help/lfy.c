#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 10
typedef struct
{  int data[MAXLEN];//        定义数据的类型 
   int front,rear;  //        定义队头，队尾指针 
}csequeue;
void InitQueue(csequeue *q)//初始化队列 
{
    q->front =q->rear =0;
}
void InQueue(csequeue *q,int x)      //入队 
{if((q->rear+1)%MAXLEN==q->front)    //判满 
printf("队满！无法入队！");          //队满无法入队！ 
else
  {scanf("%d",&x);
  q->data[q->rear]=x;
  q->rear =(q->rear +1)% MAXLEN;
  }                                   
}
void Outsequeue(csequeue *q)//出队
{ if(q->front==q->rear)
    {  printf("\n\t\t此队列为空！");return;   }   //队空不能出队
	else
	{ q->front=(q->front+1) % MAXLEN;
	 printf("\n\t\t出队元素为：%d\n",q->data[q->front]);//输出队头元素
	 return; 
	 } 
 }
void ShowQueue(csequeue *q)//显示队列元素 
{if(q->front==q->rear)
    {  printf("\n\t\t此队列为空！");return;   }   //队空不能出队
	else
    {
	 int i=q->front ;
     printf("队列中的元素为：");
     while((i%MAXLEN)!=q->rear)
      {printf("%d",q->data[1]);
        i++;
	  }
	  printf("\n"); 
    }
	  
 }
int length(csequeue *q)// 求队列长度
{   int k;
    k=(q->rear-q->front+MAXLEN)%MAXLEN;
    return k;
 } 
int main()
{  int i=1;           //标志位，控制循环
   int choice;
   int val;     //入队的值
   csequeue * q;
   q=(csequeue*)malloc(sizeof(csequeue));//申请空间 并对q赋初值
   InitQueue(q); //初始化队列
   while (i)
   {
   	printf("\n\t\t              循环队列         \n");
   	printf("\n\t\t*********************************");
   	printf("\n\t\t*       1---------进   队       *");
   	printf("\n\t\t*       2---------出   队       *");
   	printf("\n\t\t*       3---------显   示       *");
   	printf("\n\t\t*       4---------求队列长度    *");
   	printf("\n\t\t*       0---------返   回       *");
   	printf("\n\t\t*********************************");
   	printf("\n\n\t\t请选择菜单号：    ");
    scanf("%d",&choice); 
    switch(choice)
    {
    	case 1:
    	while(1){
    	printf("\n\t\t 输入一个队列的整数数据（输入‘0’结束）：");
		scanf("%d",&val);
		if(val!=0)         InQueue(q,val);
		else break; 
		        }
		case 2: Outsequeue(q);break;
		case 3: ShowQueue(q);break;
		case 4: printf("\n\t\t队列长度为： %d\n",length(q));break;
		case 0: return 0;
		} 
	}

     
}
