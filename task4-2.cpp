#include<stdio.h>

int main (void)
{
int num;
printf("Enter a number(0~9999):");
scanf("%d",&num);

if (num>=0 && num<10)
printf("The number %d has 1 digits",num);
else if (num>=10 && num<100)
printf("The number %d has 2 digits",num);
else if (num>=100 && num<1000)
printf("The number %d has 3 digits",num);
else if (num>=1000 && num<10000)
printf("The number %d has 4 digits",num);
else
{
    printf("형식에 맞게 수를 입력하여주십시오");
}


return 0;







}