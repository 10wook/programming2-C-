//구조체사용해보기
#include<stdio.h>
enum _shape {LINE=1, RECT=2};
int main (void)
{   int input=3;
    struct shape {int Shape;
    int point[4];};
    struct shape array[10];
    int i=0;
    while(input!=0)
        {printf("Put figure shape (1: LINE, 2: RECT, 0: PRINT):");
        scanf("%d",&input);
        if (input==0)
            {for (int j=0;j<i;j=j+1)
                {if (array[j].Shape==1)
                    printf("Figure %d: a line from (%d,%d) to (%d, %d)",j+1,array[j].point[0],array[j].point[1],array[j].point[2],array[j].point[3]);
                else
                    printf("Figure %d: a rectangle from (%d,%d) to (%d, %d)",j+1,array[j].point[0],array[j].point[1],array[j].point[2],array[j].point[3]);
                
                }
            break;}
            else 
            {array[i].Shape=input;
            printf("Put the coordinate of Point1:\n");
            scanf("%d",&array[i].point[0]);
            scanf("%d",&array[i].point[1]);
            printf("Put the coordinate of Point2:\n");
            scanf("%d",&array[i].point[2]);
            scanf("%d",&array[i].point[3]);
            }
        i=i+1;


        }




}