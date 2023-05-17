#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define STRINGMAX 100
typedef struct 
{
    char vec[STRINGMAX];
    int len;
}str;

int StrAssign (str *s);//输入
int Long (str *s);//求长
void StrCat (str*s,str *t);//连接
int DelStr (str*s,int y,str*m);//删除和取出 y为1取出，0是删除
void ShowStr (str*s);//展示
void SerchStr (str *s,str *t);//搜索
void compare (str *s,str *t);//比较
str * plus (str *s,str *t,int n);//插入


int main ()
{
    str *s;//主串
    str *t;//工作串
    str *m;//取出串
    t = (str *)malloc(sizeof(str));
    s = (str *)malloc(sizeof(str));
    m = (str *)malloc(sizeof(str));
    s->vec[0] = '\0'; //初始化
    s->len = 0;
    int flag = 1;   //继续运行的标志
    int i;char c;int choice;   //i是序列；c是字符；choice 是选项
   while (flag)
    {
        printf("\n        菜单（链表）      ");
        printf("\n***************************");
        printf("\n  1.输入 ");
        printf("\n  2.连接 ");
        printf("\n  3.取出 ");
        printf("\n  4.删除 ");
        printf("\n  5.插入 ");
        printf("\n  6.查找 ");
        printf("\n  7.比较 ");
        printf("\n  8.显示 ");
        printf("\n  0.返回 ");
        printf("\n***************************");
        printf("\n");
        scanf("%d",&choice);
        getchar();
        if (choice == 1)
        {
            int e = StrAssign (s);//e作为标志来判断是否创建成功;
            if (e == 1)
            {
                printf("\n创建成功");
            }else if(e == 0)
            {
                printf("\n创建失败");
            }else if(e == 2)
            {
                printf("\n创建失败，原因：重复。");
            }
            
           
        }else if(choice ==2)
        {
            
            StrCat (s,t);
            
        }else if (choice == 3)
        {
           DelStr (s,1,m);
        }else if (choice == 4)
        {
            DelStr (s,0,m);
        }else if (choice == 5)
        {
            int n;
            printf("请输入插入位置");
            scanf("%d",&n);
            s = plus(s,t,n);
           
        }else if (choice == 6)
        {
            SerchStr (s,t);

        }else if (choice == 7)
        {
            compare (s,t);
        }
        else if (choice == 8)
        {
             ShowStr (s);
        }else if (choice == 0)
        {
            flag = 0;
        }
    }
    
}

int StrAssign (str *s) //输入
{   
    if (s->len>0)
    {
        return 2;
    }
    
    int flag;
    printf("\n请输入字符 ");
    gets(s->vec);
    s->len = Long(s);
    if(s->len>0){//判断创建是否成功
		flag = 1; 
	}else{
		flag = 0;
    }
    return flag;

}
int Long (str *s)//求长
{
    int i =0;
    while (s->vec[i] != '\0')
    {
        i++;
    }
    s->len = i;
    return(s->len);
    
}
void StrCat (str*s,str*t) //连接
{
    if (s->len == 0)
    {
        printf("\n失败,主函数为空");
        return;
    }
    
        int i =0;
        printf("\n创建连接串(字符数最大为100) ");
            int e = StrAssign (t);//e作为标志来判断是否创建成功;
            if (e == 1)
            {
                printf("\n创建成功");
            }else if(e == 0)
            {
                printf("\n创建失败");
            }
    if (t->len +s->len <= STRINGMAX )
    {
        for ( i = s->len; i <s->len +t->len; i++)
        {
            s->vec[i] = t->vec[i-s->len];
        }
        s->vec[i] = '\0';
        s->len = s->len +t->len;
        printf ("\n链接后的串 ");
        printf("%s",s->vec);
    }else if (t->len +s->len > STRINGMAX &&s->len<STRINGMAX)
    {
        for(i=s->len;i<STRINGMAX;i++){
			s->vec[i]=t->vec[i-s->len];
		}
        s->len = STRINGMAX;
        printf ("\n链接后的串 ");
        printf("%s",s->vec);
    }else
    {
        printf ("\n连接出错了 ");
    }
    free(t);
}
int DelStr (str*s,int y,str*m)  //删除和取出
{
    int j,k,l,x;
	printf("输入子串的位置：");
	scanf("%d",&j);
	printf("\n输入子串的长度：");
	scanf("%d",&l);
	x=s->len;//把串长赋值给X变量 
    int len = j+l-1;//删除的最末位置
	if(len>x){//删除的位置加上删除子串的长度如果大于主串则报错退出程序 
		printf("\n子串越界！！"); 
		return 0;
	}else{
        if (y ==1)
        {
            m->len = l;
            int q =j;
            for (int i = 0; i < m->len; i++,q++)
            {
                m->vec[i] = s->vec[q];
            }
            printf("\n取出成功");//取出成功，输出取出后的串 
		    printf("\n取出后的串"); 
            printf("%s",m);
            
        }
        

		for(len;len<s->len;len++,j++){//从第j个位置开始删除长度l的子串 
			s->vec[j-1]=s->vec[len];
		} 
        s->len = s->len - l;
        
		s->vec[s->len]='\0';//尾部结束标志 
	}
	if(s->len>x){//如果串长大于删除之前的串长则报错，退出程序 
		printf("\n删除错误！！");
		return 0;
	}else if(m == 0)
    {
		printf("\n删除成功。");//删除成功，输出删除后的串 
		printf("\n删除后的串："); 
        printf("%s",s);
		
	}
}

void ShowStr (str*s)//展示
{
     if (s->len==0)
    {
        printf("\n失败,主函数为空");
        return;
    }
    printf("\n%s",s->vec);
    
}
void SerchStr (str *s,str *t)//搜索
{
    if (s->len==0)
    {
        printf("\n失败,主函数为空");
        return;
    }
    printf("\n请输入要搜索的字符串 ");
    int e = StrAssign (t);//e作为标志来判断是否创建成功;
    if (e == 1)
    {
        printf("\n创建成功");
    }else if(e == 0)
    {
        printf("\n创建失败");
    }


    int start = 0;//开始位置
    int i = 0;//主串位置
    int j = 0;//工作串位置
    int flag =1;//是否继续搜索的标志
    i = start;
    while (i<s->len && j<t->len)
    {
        if (s->vec[i]==t->vec[j])
        {
            i++;
            j++;
        }else
        {
            i++;
            j = 0;
        }
    }
    if (j>=t->len)
    {
        printf("\n找到了，在第 %d 个",i-t->len);
    }else
    {
        printf("\n找不到");
    }
}
void compare (str *s,str *t)//比较
{
    if (s->len==0)
    {
        printf("\n失败,主函数为空");
        return;
    }
    printf("\n请输入要比较的字符串 ");
    int e = StrAssign (t);//e作为标志来判断是否创建成功;
    if (e == 1)
    {
        printf("\n创建成功");
    }else if(e == 0)
    {
        printf("\n创建失败");
    }
    int m;//差值
    m = s->len - t->len;
    if (m == 0)
    {
        printf("\n相等");
    }else if (m<0)
    {
        printf("\n工作串大");
    }else if (m>0)
    {
        printf("\n主串大");
    }
    free(t);
}
str * plus(str*s,str*t,int n) //插入
{
    getchar();//清空缓存
    if (s->len == 0)
    {
        printf("\n失败,主函数为空");
        return s;
    }
    
    int i =0;
        printf("\n创建链接串(字符数最大为100) ");
            int e = StrAssign (t);//e作为标志来判断是否创建成功;
            if (e == 1)
            {
                printf("\n创建成功");
            }else if(e == 0)
            {
                printf("\n创建失败");
            }
    if (t->len +s->len <= STRINGMAX )
    {
        str *p ;
        p = (str *)malloc(sizeof(str));//临时
        int i = 0;
        for (p->len = 0; p->len < n; p->len++,i++)
        {
            p->vec[p->len]= s->vec[i];           
        }
        int j = 0;
        for ( p->len; j < t->len; p->len++,j++)
        {
            p->vec[p->len] = t->vec[j];
        }
        for (i; i <s->len +1; p->len++,i++)
        {
            p->vec[p->len]= s->vec[i];           
        }

        p->len = s->len + t->len;
        s = p;
        printf ("\n链接后的串 ");
        printf("%s",s->vec);
        return s;
    }else if (t->len +s->len > STRINGMAX &&s->len<STRINGMAX)
    {
        printf ("\n错误，超长！ ");
    }else
    {
        printf ("\n连接出错了 ");
    }
    free(t);
}
