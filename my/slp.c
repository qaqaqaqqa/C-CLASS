#include"stdio.h"
#include"stdlib.h"
typedef struct stacknode //栈的节点结构 
{
	int date;
	struct stacknode *next; 
 } StackNode;
 typedef struct
{
 	StackNode *top;
 }LinkStack;   //栈的结构
int Pop(LinkStack *s,int *x) //出栈 
{
  StackNode *p;
  if(s->top==NULL) return 0;
  else {
  	p=s->top;
  	*x=p->date;
  	s->top=p->next;
  	free(p);
  	return 1;
  }	
 } 
void Push(LinkStack *s,int x)//入栈 
{
   StackNode *p;
   p=(StackNode*)malloc(sizeof(StackNode));
   p->date=x;
   p->next=s->top;
   s->top=p;
	
}
void ShowStack(LinkStack *s) //显示栈的内容 
{
	StackNode *p;
	if(s->top=NULL)
	printf("栈为空!\n");
	else
	{
		p=s->top; //保存栈顶指针
		printf("栈的元素为:");
		while(p!=NULL)
		{
			printf("%6d",p->date);
			p=p->next;
		 } 
		 printf("\n"); 
	}
	
}
void Conversion (int n) //十进制转换二进制 
{
	LinkStack *s;
	int x;
	s=(LinkStack *)malloc(sizeof(LinkStack));
	s->top=NULL;
	while(n);
	{
		x=n%2;
		Push(s,x);
		n=n/2;
	 } 
	 printf("\n\t\t转换后的二进制数值为:");
	 while(s->top!=NULL)
	 {
	 	Pop(s,&x);
	 	printf("%d",x);
		 }	
		 printf("\n");
}
int main()
{
	char choice;
	int val;
	int n;
	LinkStack *s;
	s=(LinkStack *)malloc(sizeof(LinkStack));
	s->top=NULL;
	while(1)
	{
		printf("\n");
		printf("\n\t                   栈子系统                   ");
		printf("\n\t\t********************************************");
		printf("\n\t\t*          1------进  栈                   *");
		printf("\n\t\t*          2------出  栈                   *"); 
		printf("\n\t\t*          3------显  示                   *");
		printf("\n\t\t*          4------数制转换(十-二进制)      *");
		printf("\n\t\t*          0------返  回                   *");
		printf("\n\t\t********************************************");
		printf("\n\t\t请选择菜单号(0-4)："); 
		fflush(stdin);//清空输入缓冲区
		choice=getchar();
		switch (choice)
		{
			case '1':
			while(1)
			{
				printf("\n\t\t键入一个整数('0'表示结束)并按回车：");
				scanf("%d",&val);
				getchar();
				if(val!=0)
					Push(s,val);
					else
					break;
			}
			break;
			case '2':
			if(Pop(s,&val))
				printf("\n\t\t出栈元素为: %6d\n",val);
				else
				printf("\n\n\t栈空！\n");
				break;
			case '3':
				ShowStack(s);
				break;
			case '4':
			printf("\n\t\t请输入一个十进制正整数:");
			scanf("%d",&n);
			Conversion(n);
			break;
			case '0':
				exit(0);
			default:
			 printf("\n\t\t输入菜单错误,请重新输入.\n");
			  
		  }  
	}
	return 0;
}