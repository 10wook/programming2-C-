#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main (void)
{
srand(time(NULL));
int rand_num,input_num,cnt;
rand_num=rand()%1001;
cnt=1;
while(1)
    {printf("Put your guess:");
    scanf("%d",&input_num);
    if(rand_num==input_num)
        {if(cnt==1)
            {printf("Feeling lucky! the number was %d",rand_num);}
        else
            {if(rand_num==1000)
                {printf("You got the extreme number! the number was %d",rand_num);}
            else if(rand_num==0)
                {printf("You got the extreme number! the number was %d",rand_num);}
            else
                {printf("Player won! the number was %d",rand_num);}
            }
        break;
        }
    else 
        {if(cnt<10)     
            {if(input_num < rand_num)
                {printf("The key is higher than %d\n",input_num);}
            else
                {printf("The key is lower than %d\n",input_num);}
            if((rand_num%input_num)==0)
                {printf("The key is a multiple of %d\n",input_num);}
            cnt=cnt+1;}
        else  
            {printf("Computer won! the number was %d",rand_num);
            break;} 
            
        }
    }




}