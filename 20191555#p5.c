#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
enum _shape {LINE=1, RECT=2,circle=3};
struct shape {int Shape;
int point[4];};

int printp (int paper[200][200])
    {FILE *fp;
    fp=fopen("print.txt","w");
    for (int c=0;c<200;c=c+1)
        {for (int r=0;r<200;r=r+1)
            {if (paper[c][r]==0)
                {fputc(' ',fp);
                fputc(' ',fp);
                }
            else if (paper[c][r]==1)
                {fputc('*',fp);
                fputc(' ',fp);
                }
            }
        fputc('\n',fp);
        }
    fclose(fp);

    
    
    return 0;
    }

int out_range(int x)//특정 점이 0~200 사이의 값인지 확인한다. 범위 내면 0 그 밖에면 1 리턴
    {if (x<200&&x>=0)
        return 0;
    else return 1;}

int can_paint(struct shape figure) /*색칠 가능한 범위의 도형인지 확인한다. 가능하면 1을 리턴 불가능 하면 0리턴*/
    {if (figure.Shape==1)           
        {for (int i=0;i<4;i=i+1)
            if (out_range(figure.point[i])==1)
                return 0;
            else return 1;
        }
    else if (figure.Shape==2)
        {for (int i=0;i<4;i=i+1)
            if (out_range(figure.point[i])==1)
                return 0;
            else return 1;
        }
    else if (figure.Shape==3)
        {if (out_range(figure.point[0]+figure.point[2])==1)
            return 0;
        else if (out_range(figure.point[0]-figure.point[2])==1)
             return 0;
        else if (out_range(figure.point[1]+figure.point[2])==1)
            return 0;
        else if (out_range(figure.point[1]-figure.point[2])==1)
            return 0;
        else return 1;
            }
    return 0;
    }

int Rounds(float a) /*유사한 점에 점을 찍기 위해서는 반올림을 하는 작업이 꼭 필요하다*/
    {a=a+0.5;
    floor(a);
    return a;
    }

int ADD_figure(struct shape array[20])//도형 추가 함수
    {int num;
    int sh;
    printf("Enter the figure id:");
    scanf("%d",&num);
    printf("Enter shape (1: Line, 2: Rect, 3:Circle):");
    scanf("%d",&sh);
    array[num].Shape=sh;
    if (sh==3)
        {printf("Enter the (r,c) coordinate of P1():");
        scanf("%d",&array[num].point[0]);
        scanf("%d",&array[num].point[1]);
        printf("Enter the R1:");
        scanf("%d",&array[num].point[2]);
        printf("Circle (id: %d) with the center (%d,%d) and the radius (%d) is added.\n"
        ,num,array[num].point[0],array[num].point[1],array[num].point[2]);
        }
    else if (sh==2)
        {printf("Enter the (r,c) coordinate of P1:");
        scanf("%d",&array[num].point[0]);
        scanf("%d",&array[num].point[1]);
        printf("Enter the (r,c) coordinate of P2:");
        scanf("%d",&array[num].point[2]);
        scanf("%d",&array[num].point[3]);
        printf("Rectangle (id: %d) from (%d,%d) to (%d,%d) is added\n."
        ,num,array[num].point[0],array[num].point[1],array[num].point[2],array[num].point[3]);
        }
    else if (sh==1)
        {printf("Enter the (r,c) coordinate of P1:");
        scanf("%d",&array[num].point[0]);
        scanf("%d",&array[num].point[1]);
        printf("Enter the (r,c) coordinate of P2:");
        scanf("%d",&array[num].point[2]);
        scanf("%d",&array[num].point[3]);
        printf("Line (id: %d) from (%d,%d) to (%d,%d) is added.\n"
        ,num,array[num].point[0],array[num].point[1],array[num].point[2],array[num].point[3]);
        }
    else
        {printf("Please in put correct number.\n");}
    return num;
    }

int remove_figure(struct shape array[20])//도형 삭제 함수
    {int num;
    printf("Enter the figure id:");
    scanf("%d",&num);
    if (array[num].Shape==1)
        printf("Line (id: %d) from (%d,%d) to (%d,%d) is removed.\n"
        ,num,array[num].point[0],array[num].point[1],array[num].point[2],array[num].point[3]);
    else if (array[num].Shape==2)
        printf("Rectangle (id: %d) from (%d,%d) to (%d,%d) is removed.\n"
        ,num,array[num].point[0],array[num].point[1],array[num].point[2],array[num].point[3]);
    else if (array[num].Shape==3)
        printf("Circle (id: %d) with the center (%d,%d) and the radius (%d) is removed.\n"
        ,num,array[num].point[0],array[num].point[1],array[num].point[2]);
    array[num].Shape=0;
    return num;
    }

int Adjust(struct shape array[20])//도형 수정함수
    {int num;
    int sh;
    printf("Enter the figure id:");
    scanf("%d",&num);
    if (array[num].Shape==3)
        {printf("Enter the (r,c) coordinate of P1:");
        scanf("%d",&array[num].point[0]);
        scanf("%d",&array[num].point[1]);
        printf("Enter the R1:");
        scanf("%d",&array[num].point[2]);
        printf("Circle (id: %d) with the center (%d,%d) and the radius (%d) is adjusted.\n"
        ,num,array[num].point[0],array[num].point[1],array[num].point[2]);
        }
    else if (array[num].Shape==2)
        {printf("Enter the (r,c) coordinate of P1:");
        scanf("%d",&array[num].point[0]);
        scanf("%d",&array[num].point[1]);
        printf("Enter the (r,c) coordinate of P2:");
        scanf("%d",&array[num].point[2]);
        scanf("%d",&array[num].point[3]);
        printf("Rectangle (id: %d) from (%d,%d) to (%d,%d) is adjusted.\n"
        ,num,array[num].point[0],array[num].point[1],array[num].point[2],array[num].point[3]);
        }
    else if (array[num].Shape==1)
        {printf("Enter the (r,c) coordinate of P1:");
        scanf("%d",&array[num].point[0]);
        scanf("%d",&array[num].point[1]);
        printf("Enter the (r,c) coordinate of P2:");
        scanf("%d",&array[num].point[2]);
        scanf("%d",&array[num].point[3]);
        printf("Line (id: %d) from (%d,%d) to (%d,%d) is adjusted.\n"
        ,num,array[num].point[0],array[num].point[1],array[num].point[2],array[num].point[3]);
        }
    else
        {printf("Please in put correct number.\n");}
    return num;
    }

int exports (struct shape array[20],int paper[200][200])//도형 그리기 함수
    /*얘는 뭘 해야 할까?? 크게 두가지가 있다.
    1. 구조체를 입력 받아서 분석한다(도형을 분석한다. 선, 원, 직사각형)
    2. 출력이 가능한 값인지 확인한다
    3. 가능하면 그게 맞게 그림을 그린다.(어레이의 값을 수정해 준다)
    4. 마지막에 페인트를 해준다.*/
   {for (int i=0;i<200;i=i+1)//종이 초기화
        {for (int j=0;j<200;j=j+1)
            paper[i][j]=0;
        }  
    for (int i=0;i<20;i=i+1)
        {if (array[i].Shape==1)//선 그리기
            {if (can_paint(array[i])==0)
                {printf("You cannot paint shape id %d",i);
                continue;}
            else 
                { 
                if (array[i].point[1]==array[i].point[3])
                    {if (array[i].point[0]>array[i].point[2])
                        {for (int j=array[i].point[2];j<=array[i].point[0];j=j+1)
                            {paper[j][array[i].point[1]]=1;
                            }
                        }
                    else
                        { for (int j=array[i].point[0];j<=array[i].point[2];j=j+1)
                            {paper[j][array[i].point[1]]=1;
                            }
                        }
                    }
                else if (array[i].point[0]==array[i].point[2])
                    {if (array[i].point[1]>array[i].point[3])
                        {for (int j=array[i].point[3];j<=array[i].point[1];j=j+1)
                            {paper[array[i].point[0]][j]=1;}
                        }
                    else 
                        {for (int j=array[i].point[1];j<=array[i].point[3];j=j+1)
                            {paper[array[i].point[0]][j]=1;}
                        }
                    }
                //경우 3==우하향 직선
                else if (array[i].point[1]<array[i].point[3])
                    {float nums[4];
                    for (int j=0;j<4;j=j+1)
                        nums[j]=array[i].point[j];
                    if (array[i].point[0]>array[i].point[2])//p1이 왼쪽에 있는 우하향 직선 
                        {float b=0;
                        for (int j= array[i].point[1];j<=array[i].point[3];j=j+1)
                            {float a;
                            a=(nums[2]-nums[0])/(nums[3]-nums[1]);
                            a=Rounds(a*b);
                            int t=a;
                            paper[array[i].point[0]+t][j]=1;
                            b=b+1;
                            }
                        }
                    else //p1이 왼쪽에있는 우상향 곡선
                        {float b=0;
                        for (int j= array[i].point[1];j<=array[i].point[3];j=j+1)
                            {float a;
                            a=(nums[2]-nums[0])/(nums[3]-nums[1]);
                            a=Rounds(a*b);
                            int t=a;
                            paper[array[i].point[0]+t][j]=1;
                            b=b+1;
                            }
                        }
                    }
                else 
                    {float nums[4];
                    for (int j=0;j<4;j=j+1)
                        nums[j]=array[i].point[j];
                    if (array[i].point[0]>array[i].point[2])//p2이 왼쪽에 있는 우상향 직선 
                        {float b=0;
                        for (int j= array[i].point[1];j<=array[i].point[3];j=j+1)
                            {float a;
                            a=(nums[2]-nums[0])/(nums[3]-nums[1]);
                            a=Rounds(a*b);
                            int t=a;
                            paper[array[i].point[0]+t][j]=1;
                            b=b+1;
                            }
                        }
                    else //p2이 왼쪽에있는 우하향 곡선
                        {float b=0;
                        for (int j= array[i].point[1];j<=array[i].point[3];j=j+1)
                            {float a;
                            a=(nums[2]-nums[0])/(nums[3]-nums[1]);
                            a=Rounds(a*b);
                            int t=a;
                            paper[array[i].point[0]+t][j]=1;
                            b=b+1;
                            }
                        }
                    }
                }
            }
        else if (array[i].Shape==2) //직사각형 그리기
            {if (can_paint(array[i])==0)
                {printf("You cannot paint shape id %d\n",i);
                continue;}
            else 
                {for (int j=array[i].point[1];j<array[i].point[3];j=j+1)
                    {paper[array[i].point[0]][j]=1;}
                for (int j=array[i].point[0];j<array[i].point[2];j=j+1)
                    {paper[j][array[i].point[1]]=1;}
                for (int j=array[i].point[1];j<array[i].point[3];j=j+1)
                    {paper[array[i].point[2]][j]=1;} 
                for (int j=array[i].point[0];j<(array[i].point[2]+1);j=j+1)
                    {paper[j][array[i].point[3]]=1;}
                }
            }
        else if (array[i].Shape==3)//원 그리기.
            {if (can_paint(array[i])==0)
                {printf("You cannot paint shape id %d\n",i);
                continue;}
            else
                {// 원을 어떻게 만들어야 할까. 
                for (int x=array[i].point[1]-array[i].point[2];x<=array[i].point[1]+array[i].point[2];x=x+1)
                    {for (int y=array[i].point[0]-array[1].point[2];y<=array[i].point[0]+array[1].point[2];y=y+1)
                        {if (((x-array[i].point[1])*(x-array[i].point[1])+(y-array[i].point[0])*(y-array[i].point[0]))==(array[i].point[2])*(array[i].point[2]))
                            paper[y][x]=1;
                        }
                    }
                for (int x=array[i].point[1]-array[i].point[2];x<=array[i].point[1]+array[i].point[2];x=x+1)
                    {int y=Rounds (sqrt(((array[i].point[2])*(array[i].point[2]))-((x-array[i].point[1])*(x-array[i].point[1]))))+array[i].point[0];
                    paper[y][x]=1;
                    }
                for (int y=array[i].point[0]-array[1].point[2];y<=array[i].point[0]+array[1].point[2];y=y+1)
                    {int x=Rounds(sqrt(((array[i].point[2])*(array[i].point[2]))-((y-array[i].point[0])*(y-array[i].point[0]))))+array[i].point[1];
                     }
                }
            
            }
        }
    printp (paper);
    return 0;
   }

int prints(struct shape array[20])//어떤 도형이 있나 알려주는 함수
    {for (int i=0;i<20;i=i+1)
        {if (array[i].Shape!=0)
            {if (array[i].Shape==1)
                {printf("Line (id: %d) from (%d,%d) to (%d,%d).\n"
                ,i,array[i].point[0],array[i].point[1],array[i].point[2],array[i].point[3]);}
            else if (array[i].Shape==2)
                {printf("Rectangle (id: %d) from (%d,%d) to (%d,%d).\n"
                ,i,array[i].point[0],array[i].point[1],array[i].point[2],array[i].point[3]);}
            else if (array[i].Shape==3)
                {printf("Circle (id: %d) with the center (%d, %d) and the radius (%d).\n"
                ,i,array[i].point[0],array[i].point[1],array[i].point[2]);}
            }
        }
    return 0;
    }

int main(void)
    {int operate;
    struct shape array[20];/*입력 받은 도형들을 저장하는 하는 배열*/
    int paper[200][200];
    for (int i=0;i<20;i=i+1)//이를 통해서 일단 모든 도형의 값을 0으로 만들어주고 프린트를 할 때에는 1,2,3 값을 가진 친구들을 그려준다.
        {array[i].Shape=0;}
    while (1)
        {printf("Enter a command (1: Add, 2:Remove, 3: Ajdust, 4:Export, 5:Print, 0:Exit):");
        scanf("%d",&operate);
        if (operate==0)
            {printf("exit program");
            break;
            }
        else if (operate==1)
            {ADD_figure(array);}
        else if (operate==2)
            {remove_figure(array);}
        else if (operate==3)
            {Adjust(array);}
        else if (operate==4)
            {exports(array,paper);}
        else if (operate==5)
            {prints(array);}
        else 
            {printf("please enter right number\n");}
        }
}