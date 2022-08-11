#include<stdio.h>
# include <stdlib.h>
#include<time.h>
#define N 9 /*가로세로 길이*/

int print (int a[N][N])/*게임보드를 출력하는 함수*/
    {printf("    1 2 3 4 5 6 7 8 9\n    _ _ _ _ _ _ _ _ _\n");
    for(int i=0; i<N;i=i+1)
        {printf("%d  ",i+1);
        for(int j=0;j<N;j=j+1)
            {if (a[i][j]==0)
                {printf("|_");}
            else if (a[i][j]==1)
                {printf("|O");}
            else if (a[i][j]==2)
                {printf("|@");} 
            }           
        printf("|\n");
        }
    return 0;
    }
int call_block(int a,int pb[3][3],int rand_num)/*해당 턴 플레이어의 블록을 불러오는 함수*/
    {
    rand_num=rand()%14;
    int b1[3][3]={{a,a,a},{0,0,0},{0,0,0}}
    ,b2[3][3]={{a,a,a},{a,0,0},{0,0,0}}
    ,b3[3][3]={{a,a,a},{0,0,a},{0,0,0}}
    ,b4[3][3]={{a,a,a},{0,a,0},{0,0,0}}
    ,b5[3][3]={{0,a,a},{a,a,0},{0,0,0}}
    ,b6[3][3]={{a,a,0},{0,a,a},{0,0,0}}
    ,b7[3][3]={{a,a,0},{a,a,0},{0,0,0}}
    ,b8[3][3]={{a,0,0},{a,a,0},{a,a,0}}
    ,b9[3][3]={{0,a,a},{a,a,0},{a,0,0}}
    ,b10[3][3]={{a,a,0},{0,a,a},{0,a,0}}
    ,b11[3][3]={{0,a,a},{a,a,0},{0,a,0}}
    ,b12[3][3]={{0,0,a},{a,a,a},{a,0,0}}
    ,b13[3][3]={{a,0,0},{a,a,a},{0,0,a}}
    ,b14[3][3]={{0,a,0},{a,a,a},{0,a,0}};
    if(rand_num==0)
    for(int i=0;i<3;i=i+1)
        {for (int j=0;j<3;j=j+1)
            {pb[i][j]=b1[i][j];}
        }
    if(rand_num==1)
    for(int i=0;i<3;i=i+1)
        {for (int j=0;j<3;j=j+1)
            {pb[i][j]=b2[i][j];}
        }
    if(rand_num==2)
    for(int i=0;i<3;i=i+1)
        {for (int j=0;j<3;j=j+1)
            {pb[i][j]=b3[i][j];}
        }
    if(rand_num==4)
    for(int i=0;i<3;i=i+1)
        {for (int j=0;j<3;j=j+1)
            {pb[i][j]=b5[i][j];}
        }
    if(rand_num==5)
    for(int i=0;i<3;i=i+1)
        {for (int j=0;j<3;j=j+1)
            {pb[i][j]=b6[i][j];}
        }
    if(rand_num==6)
    for(int i=0;i<3;i=i+1)
        {for (int j=0;j<3;j=j+1)
            {pb[i][j]=b7[i][j];}
        }
    if(rand_num==7)
    for(int i=0;i<3;i=i+1)
        {for (int j=0;j<3;j=j+1)
            {pb[i][j]=b8[i][j];}
        }
    if(rand_num==8)
    for(int i=0;i<3;i=i+1)
        {for (int j=0;j<3;j=j+1)
            {pb[i][j]=b9[i][j];}
        }
    if(rand_num==9)
    for(int i=0;i<3;i=i+1)
        {for (int j=0;j<3;j=j+1)
            {pb[i][j]=b10[i][j];}
        }
    if(rand_num==10)
    for(int i=0;i<3;i=i+1)
        {for (int j=0;j<3;j=j+1)
            {pb[i][j]=b11[i][j];}
        }
    if(rand_num==11)
    for(int i=0;i<3;i=i+1)
        {for (int j=0;j<3;j=j+1)
            {pb[i][j]=b12[i][j];}
        }
    if(rand_num==12)
    for(int i=0;i<3;i=i+1)
        {for (int j=0;j<3;j=j+1)
            {pb[i][j]=b13[i][j];}
        }
    if(rand_num==13)
    for(int i=0;i<3;i=i+1)
        {for (int j=0;j<3;j=j+1)
            {pb[i][j]=b14[i][j];}
        }

    return 0;
    }
int rotate (int b[3][3])    /*로테이션을 진행해주는 함수*/
        {int save[3][3];
        for (int i=0;i<3;i=i+1) 
            {for (int j=0;j<3;j=j+1)
                save[i][j]=b[i][j];}
        b[0][2]=save[0][0];
        b[1][2]=save[0][1];
        b[2][2]=save[0][2];
        b[2][1]=save[1][2];
        b[2][0]=save[2][2];
        b[1][0]=save[2][1];
        b[0][0]=save[2][0];
        b[0][1]=save[1][0];
        
        return 0;
        }
int print_block (int a[3][3])/*받은 블록의 상태를 출력하는 함수 */

    {printf(" _ _ _\n");
    for(int i=0; i<3;i=i+1)
        {for(int j=0;j<3;j=j+1)
            {if (a[i][j]==0)
                {printf("|_");}
            else if (a[i][j]==1)
                {printf("|O");}
            else if (a[i][j]==2)
                {printf("|@");} 
            }           
        printf("|\n");
        }
    return 0;
    }
/*블럭을 놓을 수 있는 자리인지 아닌지 확인하는 함수
만약 0이 리턴 된다면 해당자리에는 블럭을 놓을 수 없다.
반대로 1이 나온다면 블럭을 놓을 수 있는 자리이다.*/
int block_input_possible(int block[3][3],int board[N][N],int row,int col)
    {for (int i=0;i<3;i=i+1)
        {for (int j=0;j<3;j=j+1)
            {if (block[i][j]!=0)
                {if (board[col+i][row+j]!=0)
                    {return 0;}
                }
            else 
                continue;
            }
        }
    return 1;
    }
/*플레이가 원하는 자리에 블럭을 보드에 놓아주는 함수
리턴 값이 0이면 블럭을 놓지 못한 상태이고, 리턴 값이 1이면 블럭을 놓은 상태이다.*/
int put_block(int board[N][N],int b[3][3],int row,int col)
    {int ok=block_input_possible(b,board,row,col);
    if (row>7||row<0)
        {printf("해당자리에는 블럭을 놓을 수 없습니다.\n");
            return 0;}
    else if (col>7||col<0) 
        {printf("해당자리에는 블럭을 놓을 수 없습니다.\n");
            return 0;}

    /*else if(ok==0)
        {printf("해당자리에는 블럭을 놓을 수 없습니다.\n");
            return 0;}*/
    else 
        {for (int i=0;i<3;i=i+1)
            for (int j=0;j<3;j=j+1)
                {if(b[i][j]!=0)
                    board[i+col][j+row]=b[i][j];}
        return 1;   
        }
    }
/*매턴 마다 이 사람이 이겼는지 졌는지 확인하는 함수
리턴 값이 0이면 어디엔가 블럭을 놓을 수 있다. 즉 패배가 아니다.
리턴 값이 1이면 패배를 의미한다.*/
int winner_check(int b[N][N],int block[3][3])
    {for (int k=0;k<7;k=k+1)
        {for (int l=0;l<7;l=l+1)
            {if (block_input_possible(block,b,k,l)==1)
                return 0;}
        }
    return 1;
    }
int main (void)
{
int board[N][N]={{0,},{0,},{0,},{0,},{0,},{0,},{0,},{0,},{0,}};
 int player_block[3][3]={{0,},{0,},{0,}};
 int RN=rand()%14;
 int row,col,turn,win,put;
 srand(time(NULL));
while (win!=1)
    {print(board);  
        RN=rand()%14;
        call_block(1,player_block,RN);
        win=winner_check(board,player_block);
        if (win==1)
            {printf("P1's block:\n");
            print_block(player_block);
            printf("player 2 wins!!\n");
            break;}
        rotate(player_block);
        win=winner_check(board,player_block);
        if (win==1)
            {printf("P1's block:\n");
            print_block(player_block);
            printf("player 2 wins!!\n");
            break;}
        rotate(player_block);
        win=winner_check(board,player_block);
        if (win==1)
            {printf("P1's block:\n");
            print_block(player_block);
            printf("player 2 wins!!\n");
            break;}
        rotate(player_block);
        win=winner_check(board,player_block);
        if (win==1)
            {printf("P1's block:\n");
            print_block(player_block);
            printf("player 2 wins!!\n");
            break;}
        rotate(player_block);
        put=0;
        while (put==0)
            {printf("P1's block:\n");
            print_block(player_block);
            printf("Put your block (r c) or Rotate (0):");
            scanf("%d",&col);
            if (col==0) 
                 {rotate(player_block);}
            else 
                {scanf("%d",&row);
                row=row-1;
                col=col-1;
                if (block_input_possible(player_block,board,row,col)==0)
                    {printf("해당자리에는 블럭을 놓을 수 없습니다.\n");
                    continue;}
                else  
                {put_block(board,player_block,row,col);
                put=put_block(board,player_block,row,col);}
                }
            }
        print(board);
        RN=rand()%14;
        call_block(2,player_block,RN);
        win=winner_check(board,player_block);
        if (win==1)
            {printf("P2's block:\n");
            print_block(player_block);
            printf("player 1 wins!!\n");
                break;}
        rotate(player_block);
        win=winner_check(board,player_block);
        if (win==1)
            {printf("P2's block:\n");
            print_block(player_block);
            printf("player 1 wins!!\n");
                break;}
        rotate(player_block);
        win=winner_check(board,player_block);
        if (win==1)
            {printf("P2's block:\n");
            print_block(player_block);
            printf("player 1 wins!!\n");
            break;}
        rotate(player_block);
        win=winner_check(board,player_block);
        if (win==1)
            {printf("P2's block:\n");
            print_block(player_block);
            printf("player 1 wins!!\n");
            break;}
        rotate(player_block);
        put=0;
        while (put==0)
            {printf("P2's block:\n");
            print_block(player_block);
            printf("Put your block (r c) or Rotate (0):");
            scanf("%d",&col);
            if (col==0) 
                 {rotate(player_block);}
            else 
                {scanf("%d",&row);
                row=row-1;
                col=col-1;
                if (block_input_possible(player_block,board,row,col)==0)
                    {printf("해당자리에는 블럭을 놓을 수 없습니다.\n");
                    continue;}
                put_block(board,player_block,row,col);
                put=put_block(board,player_block,row,col);     
                }
            }
    }
print(board);
}