#include<stdio.h>
#define N 7 /*가로*/
#define M 6 /*세로*/
    int winner_check1(int a[M][N])/*플레이어2가 승자인지 확인하는 함수*/
    {for(int i=0;i<M;i=i+1)/*가로의 경우*/
        {for(int j=0;j<N-3;j=j+1)
            {if (a[i][j]==1&& a[i][j+1]==1&& a[i][j+2]==1&& a[i][j+3]==1 )
                {return 1;}
            else 
                continue;
            }
        }
    for (int i=0;i<M-3;i=i+1)/*세로의 경우*/
        {for(int j=0;j<N;j=j+1) 
            {if (a[i][j]==1 && a[i+1][j]==1 &&a[i+2][j]==1 &&a[i+3][j]==1 )
                {return 1;}
            else
                continue;
            }
        }
    for (int i=0;i<M-3;i=i+1)/*대각선 우하향*/
        {for(int j=0;j<N-3;j=j+1) 
            {if (a[i][j]==1 && a[i+1][j+1]==1 &&a[i+2][j+2]==1 &&a[i+3][j+3]==1 )
                {return 1;}
            else 
                continue;
            }
        }
    for (int i=0;i<M;i=i+1)/*대각선 우상향*/
        {for(int j=3;j<N;j=j+1) 
            {if (a[i][j]==1 && a[i+1][j-1]==1 &&a[i+2][j-2]==1 &&a[i+3][j-3]==1 )
                {return 1;}
            else 
                continue;
            }
        }
    return 0;
    }

    int winner_check2(int a[M][N])/*플레이어2가 승자인지 확인하는 함수*/
    {for(int i=0;i<M;i=i+1)/*가로의 경우*/
        {for(int j=0;j<N-3;j=j+1)
            {if (a[i][j]==2&& a[i][j+1]==2&& a[i][j+2]==2&& a[i][j+3]==2 )
                {return 2;}
            else 
                continue;
            }
        }
    for (int i=0;i<M-3;i=i+1)/*세로의 경우*/
        {for(int j=0;j<N;j=j+1) 
            {if (a[i][j]==2 && a[i+1][j]==2 &&a[i+2][j]==2 &&a[i+3][j]==2 )
                {return 2;}
            else
                continue;
            }
        }
    for (int i=0;i<M-3;i=i+1)/*대각선 우하향*/
        {for(int j=0;j<N-3;j=j+1) 
            {if (a[i][j]==2 && a[i+1][j+1]==2 &&a[i+2][j+2]==2 &&a[i+3][j+3]==2 )
                {return 2;}
            else 
                continue;
            }
        }
    for (int i=0;i<M;i=i+1)/*대각선 우상향*/
        {for(int j=3;j<N;j=j+1) 
            {if (a[i][j]==2 && a[i+1][j-1]==2 &&a[i+2][j-2]==2 &&a[i+3][j-3]==2 )
                {return 2;}
            else 
                continue;
            }
        }
    return 0;
    }

int print (int a[M][N])/*게임보드를 출력하는 함수*/
    {printf("  1   2   3   4   5   6   7\n");
    for(int i=0; i<M;i=i+1)
        {for(int j=0;j<N;j=j+1)
            {if (a[i][j]==0)
                {printf("|___");}
            else if (a[i][j]==1)
                {printf("|_O_");}
            else if (a[i][j]==2)
                {printf("|_@_");}
            else if (a[i][j]==3)
                {printf("|_X_");}   
            }           
        printf("|\n");
        }
    return 0;
    }

int Play_turn(int a/*입력 받은 줄*/, int player/*어떤 플레이어의 돌??*/,int b/*보드*/[M][N])  /*특정 자리에 돌을 넣는 함수*/
    {for(int i=M-1;i>=0;i=i-1)
        {if (b[i][a]==0)
            {b[i][a]=player;
            break;}
        else continue;
        }
    return 0;
    }
    
int add_block(int block, int b[M][N])
    {if (block==0)
        {return 0;}    
    for(int i=M-1;i>=0;i=i-1)
        {if (b[i][block-1]==0)
            {b[i][block-1]=3;
            break;}
        else continue;
        }
    return 0;
    }

int draw_check(int b [M][N]) 
/*진짜 대망의 마지막 함수 작성!!
무승부 확인기!!
아니 근데 무승부를 어떻게 확인하면 좋죠...??
일단 내가 생각한건 남은 0들을 1또는 2로 전부 채워 넣어서 위너체크를 돌린다.
만약 이기는 경우의 수가 둘다 안 나올경우 이를 무승부라고 칭하라고 하셨으니 
함수안에 다가 배열을 두개 새로 만들고 한개는 0에다가 1을 채워서 승리확인, 
나머지 한개는 0에다가 2를 채워서 승리확인을 수행한다. 둘다 리턴 값이 0일 경우에
무승부라고 출력!! */
    {int b_1[M][N];
    int b_2[M][N];
    for(int i=0;i<M;i=i+1)
        {for (int j=0;j<N;j=j+1)
            {if (b[i][j]==0)
                {b_1[i][j]=1;
                b_2[i][j]=2;}
            else
                {b_1[i][j]=b[i][j];
                b_2[i][j]=b[i][j];
                }
            }
        }/*여기까지 하면 일단 보드를 베끼고, 0인 부분에 1또는 2를 채우는 작업이 끝이 난거 맞지??*/
    /*그럼 이제 여기서 부터는 각각 승자확인하고 둘다 0이 출력되면 무승부로 처리*/
    if(winner_check1(b_1)==0&&winner_check2(b_2)==0)
        {return 1;}/*무승부 라는 뜻!!*/
    return 0;
    }

int main (void)
    {int board[M][N]={{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0}};
    int cnt=0;
    int game1=0;
    int game2=0;
    int play;
    int block;
    int draw=0;
    print(board);
    while (block!=0)
        {printf("For initialization, add block:");
        scanf("%d",&block);
        add_block(block,board);
        }
    print(board);
    while (game1==0&&game2==0&&draw==0)
        {if (cnt%2==0)
            {printf("P1's marker is O, P2's marker is @\n P1's turn, Enter the column number:");
            scanf("%d",&play);
            play=play-1;
            Play_turn(play,1,board);
            }
        else if (cnt%2==1)
            {printf("P1's marker is O, P2's marker is @\n P2's turn, Enter the column number:");
            scanf("%d",&play);
            play=play-1;
            Play_turn(play,2,board);
            }
        print(board);
        cnt=cnt+1;
        game1=winner_check1(board);
        game2=winner_check2(board);
        draw=draw_check(board);
        }
    if(winner_check1(board))
        {printf("P1 wins!");}
    else if (winner_check2(board))
        {printf("P2 wins!");}
    else if (draw==1)  
        {printf("Game ended in a draw.");}
    }

