#include <stdio.h>
void get_avgsum(int a[], int n, int *aver, int *big)
    {*big=a[0];
     *aver=a[0];
    for (int i = 1
    ; i < n; i=i+1)
        {if (a[i]>*big)
            {*big=a[i];}
        *aver=*aver+a[i];
        }
    *aver=*aver/n;
    }
void rotate(int *p,int *q, int *r)
    {
    int p2,q2,r2;
    p2=*p;
    q2=*q;
    r2=*r;
    *p=r2;
    *q=p2;
    *r=q2;
    }


int main (void)
{
   int arr[10] = {10,20,30,40,50,60,70,80,90,100};

   int avg, max;

   get_avgsum(arr, 10, &avg, &max);

   rotate(&arr[2], &arr[3], &arr[4]);

   printf("Array");

   for (int i=0; i<10; i++)

     printf(" %d", arr[i]);

   printf ("\nAvg: %d, Max: %d\n", avg, max);



}