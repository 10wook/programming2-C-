#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int main (void)
{
int num1,num2,num3,mode,re;/*이 부분의 인티저들은 입력받은 숫자들을 의미합니다. 모드 인티저는 계산기의 형식을 골라줄때 도움을 주는 인티저입니다. re인티저는 결과 값을 저장하는 인티저입니다.*/
int o1p,o1mi,o1mul,o1d,o2p,o2mi,o2mul,o2d;/*이부분의 인티저들은 strcmp를 사용하기 위한 인티저들입니다. */
char o1[3];
char o2[3];
printf("Enter the calculator mode (1:Normal, 2:Extended): ");
scanf("%d",&mode);
if (mode==1)
    {printf("Put two integers:(0,0)");
    scanf("%d,%d",&num1,&num2);
    if (num1>=0&&num1<=1000&&num2>=0&&num2<=1000)
        {printf("Put the operator:");
        scanf("%s",&o1);
        o1p=strcmp(o1,"+");
        o1mi=strcmp(o1,"-");
        o1mul=strcmp(o1,"*");
        o1d=strcmp(o1,"/");
        if (o1d==0)
            {if(num2==0)
                {printf("you can not divide in 0");}
            else
                {re=num1/num2;
                printf("The result is %d",re);}
            }
        else if(o1mul==0)
            {re=num1*num2;
            printf("The result is %d",re);} 
        else if (o1p==0)  
            {re=num1+num2;
            printf("The result is %d",re);}    
        else if (o1mi==0)
            {re=num1-num2;
            printf("The result is %d",re);}
        else 
            {printf("Please enter correct operator");}
        }
    else
        {printf("Pleas enter number between 0 and 1000");}
    }
else if (mode==2)
    {printf("Put three integers:(0,0,0)");
    scanf("%d,%d,%d",&num1,&num2,&num3);
    if (num1>=0&&num1<=1000&&num2>=0&&num2<=1000&&num3>=0&&num3<=1000)
        {printf("Put two operators:");
        scanf("%s %s",&o1,&o2);
        o1p=strcmp(o1,"+,");
        o1mi=strcmp(o1,"-,");
        o1mul=strcmp(o1,"*,");
        o1d=strcmp(o1,"/,");
        o2p=strcmp(o2,"+");
        o2mi=strcmp(o2,"-");
        o2mul=strcmp(o2,"*");
        o2d=strcmp(o2,"/");
        if (o1d==0)
            {if(num2==0)
                {printf("you can not divide in 0");}
            else if (o2p==0)
                {re=num1/num2+num3;
                printf("The result is %d",re);}
            else if (o2mi==0)
                {re=num1/num2-num3;
                printf("The result is %d",re);}
            else if (o2mul==0)
                {re=num1/num2*num3;
                 printf("The result is %d",re);}
            else if (o2d==0)
                {if (num3==0)
                    {printf("you can not divide in 0");}
                else
                    {re=num1/num2/num3;
                     printf("The result is %d",re);}
                }
            else 
                {printf("please enter correct operator");}
            }
        else if (o1mul==0)
            {if (o2p==0)
                {re=num1*num2+num3;
                 printf("The result is %d",re);}
            else if (o2mi==0)
                {re=num1*num2-num3;
                 printf("The result is %d",re);}
            else if (o2mul==0)
                {re=num1*num2*num3;
                 printf("The result is %d",re);}
            else if (o2d==0)
                {if (num3==0)
                    {printf("you can not divide in 0");}
                else
                    {re=num1*num2/num3;
                     printf("The result is %d",re);}
                }
            else 
                {printf("please enter correct operator");}
            }
        else if (o1p==0)
            {if (o2p==0)
                {re=num1+num2+num3;
                printf("The result is %d",re);}
            else if (o2mi==0)
                {re=num1+num2-num3;
                printf("The result is %d",re);}
            else if (o2mul==0)
                {re=num1=num2*num3;
                printf("The result is %d",re);}
            else if (o2d==0)
                {if (num3==0)
                    {printf("you can not divide in 0");}
                else
                    {re=num1*num2/num3;
                     printf("The result is %d",re);}
                }
            else 
                {printf("please enter correct operator");}
            }
        else if (o1mi==0)
            {if(o2p==0)
                {re=num1-num2+num3;
                printf("The result is %d",re);}
            else if (o2mi==0)
                {re=num1-num2-num3;
                printf("The result is %d",re);}
            else if (o2mul==0)
                {re=num1-num2*num3;
                printf("The result is %d",re);}
            else if (o2d==0)
                {if (num3==0)
                    {printf("you can not divide in 0");}
                else
                    {re=num1*num2/num3;
                     printf("The result is %d",re);}
            
                }
            else 
                {printf("please enter correct operator");}
            }
        else 
            {printf("please enter correct operator");}
    }   
    else
        {printf("Pleas enter number between 0 and 1000");}
    }
else{printf("please enter correct mode");} 
return 0;
    }
