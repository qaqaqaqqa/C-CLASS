#include <stdio.h>
void printn (int N);
int main ()
{
    int m;
    scanf("%d",&m);
    printn (m); 
}
void printn (int N)
{
    if(N){
        printn (N -1);
        printf("%d\n",N);
    }
    return ;
}