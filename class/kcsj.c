#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAXSIZE 10
typedef struct 
{
    int data[MAXSIZE];//存放指数项
    int HighPower;//最高次项
}Sqlist;
void InistPoly  (Sqlist *L);//初始化
void CreetPoly  (Sqlist *L);//创建多项式
void PrintPoly  (Sqlist *L);//打印多项式
void AddPoly    (Sqlist L1, Sqlist L2, Sqlist *L3);//相加
void SubtractPoly    (Sqlist L1, Sqlist L2, Sqlist *L3);//相减
void MultiplyPoly    (Sqlist L1, Sqlist L2, Sqlist *L3);//相乘
void main ()
{
    Sqlist L1,L2,L3;
    InistPoly(&L1);
    InistPoly(&L2);
    InistPoly(&L3);
    int ch1,ch2;//ch2 是输入选择项
    ch1 = 1;//标志
    while (ch1)
    {
        printf("\n");
        printf("\n\t 多项式运算 （顺序存储）");
        printf("****************************");
        printf("\n\t\t* 1建多项式 *");
        printf("\n\t\t* 2相加 *");
        printf("\n\t\t* 3相减 *");
        printf("\n\t\t* 4相乘 *");
        printf("\n\t\t* 5打印多项式 *");
        printf("\n\t\t* 6程序运行结果 *");
        printf("\n\t\t* 0返回 *");
        printf("****************************");
        printf("\n\t\t请选择（0-9）；");
        scanf("%d",&ch2);
        getchar();//清空输入区
        printf("\n");
        switch (ch2)
        {
        case 1:
            printf("\n建立第一个多项式");
            CreetPoly(&L1);
            printf("\n建立第二个多项式");
            CreetPoly(&L2);
            printf("\n第一个多项式为");
            PrintPoly(&L1);
            printf("\n第二个多项式为");
            break;
        case 2:
            AddPoly(L1,L2,&L3);
            printf("\n相加后的结果\n");
            PrintPoly(&L3);
            break;    
        case 3:
            SubtractPoly(L1,L2,&L3);
            printf("\n相减后的结果\n");
            PrintPoly(&L3);
            break;
        case 4:
            MultiplyPoly(L1,L2,&L3);
            printf("\n相乘后的结果\n");
            PrintPoly(&L3);
            break;
        case 5:
            printf("\n打印\n");
            PrintPoly(&L1);
            printf("\n");
            PrintPoly(&L2);
            break;
        case 6:
            AddPoly(L1,L2,&L3);
            printf("\n相加后的结果\n");
            PrintPoly(&L3);
            SubtractPoly(L1,L2,&L3);
            printf("\n相减后的结果\n");
            PrintPoly(&L3);
            MultiplyPoly(L1,L2,&L3);
            printf("\n相乘后的结果\n");
            PrintPoly(&L3);
            break;
            break;
        case 0:
            ch1 = 0;
            break;
                
        default:
            printf("\n\t\t输入错误\n");
        }//switch
        
    }//while
    
}
void InistPoly  (Sqlist *L)//初始化
{
    *(L->data) = (int *)malloc(sizeof(int) * MAXSIZE);
    if (!L->data)/*判断空间是否申请成功*/
        exit(-1);
    for (int i = 0; i < MAXSIZE; i++)
        L->data[i] = 0;
    L->HighPower = 0;/*空表最高次项为0*/

}
void CreetPoly  (Sqlist *L)//创建多项式
{
    int xishu,zhishu;//系数和指数
    for (int i = 0; i < MAXSIZE; i++)
    {
        printf("\n请输入第 %d 个系数和指数，空格隔开，指数输入-1 结束",i+1);
        scanf("%d %d",&xishu,&zhishu);
        if (zhishu != -1)
        {
            L->data[zhishu] = xishu;
            if (zhishu > L->HighPower)
            {
                L->HighPower = zhishu;
            }
        }else
        break;
    }    
}
void PrintPoly  (Sqlist *L)//打印多项式
{
    if (L->data[0] !=0)//当指数为0时 系数有数则打印
    {
        printf("%d",L->data[0]);
        if (L->data[1]>0)
        {
            printf("+%dx",L->data[1]);
        }else if (L->data[1]<0)
        {
            printf("%dx",L->data[1]);
        }
    }
    if (L->data[0] == 0)//当指数为0时 系数无数则打印
    {
        printf("%dx",L->data[1]);
    }
    if (L->data[0] == 0 &&L->data[1] == 0)//第一项和第二项都是0时 打印 0
    {
        printf("0");
    }

    for (int i = 2; i <= L->HighPower ;i++)//前面打印完了，从指数为2开始打印
    {
        if (L->data[i] > 0 )
        {
            printf("+%dx^%d",L->data[i], i);  
        }else if (L->data[i] < 0)//小于0自带负号
        {
            printf("%dx^%d",L->data[i], i);
        }
    }
}
void AddPoly    (Sqlist L1, Sqlist L2, Sqlist *L3)//相加
{
    if (L1.HighPower > L2.HighPower)
    {
        L3->HighPower = L1.HighPower;
    }else
    {
        L3->HighPower = L2.HighPower;
    }//L3 的最高次项是他俩之间最高的
    for (int i = 0; i <= L3->HighPower; i++)
    {
        L3->data[i] = L1.data[i] + L2.data[i];//每项都相加
    }
}
void SubtractPoly    (Sqlist L1, Sqlist L2, Sqlist *L3)//相减
{
    if (L1.HighPower > L2.HighPower)
    {
        L3->HighPower = L1.HighPower;
    }else
    {
        L3->HighPower = L2.HighPower;
    }//L3 的最高次项是他俩之间最高的
    for (int i = 0; i <= L3->HighPower; i++)
    {
        L3->data[i] = L1.data[i] - L2.data[i];//每项都相减
    }
}
void MultiplyPoly    (Sqlist L1, Sqlist L2, Sqlist *L3)//相乘
{
    L3->HighPower = L2.HighPower + L1.HighPower;//相乘后最大次序是两个最大次序相加
    if (L3->HighPower >MAXSIZE)
    {
        printf("\n错误！相乘后的的次序超过最大次序，越界\n");
        return;//如果最大越界了则退出
    }
    for (int i = 0; i < L3->HighPower ; i++)
    {
        for (int j = 0; j < L3->HighPower ; j++)
        {
            L3->data[i+j] += L1.data[i] * L2.data[j];
        }
    }
    
    
}