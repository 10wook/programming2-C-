#include<stdio.h>
int main (void)
{
    
    short int first, seceond, third, result; 
printf("Put tree integers");
scanf("%hd,%hd,%hd",&first, &seceond, &third);
/*이부분에 사용된 int는 short int로 -32,767에서 +32,767의 범위의 숫자만 인식할 수 있어서 이 값을 넘어가게 되면 오류가 날 수 있다.*/
result=first+seceond+third;
printf("The result is %hd",result);


 }