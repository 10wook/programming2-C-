#include<stdio.h>
int main (void)
#define N 10
{
int a[N], i,hap,big;
printf("enter %d numbers :",N);
for (i = 0; i < N; i++)
    {scanf("%d", &a[i]);}
hap=0;
for (i = 0; i < N; i++)
    { hap =hap+a[i];}
hap=hap/N;
printf("average is %d\n",hap);
big=a[0];
for (i = 0; i < N; i++)
    {if(big<a[i])
        {big=a[i];}
    }
printf("Max value is %d",big);








}