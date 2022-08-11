#include<stdio.h>
#include <string.h>
const char *planets[] = {"Mercury", "Venus", "Earth",

                     "Mars", "Jupiter", "Saturn",

                     "Uranus", "Neptune", "Pluto"};

int check_printer(char str[])
    {int j=0;
    for(j=0;j<9;j=j+1)
        {if (strcmp(str,planets[j])==0)
            {printf("%s is a planet \n",str);
            break;}
        else 
            {if (j==8)
                printf("%s is Not a planet \n",str);}}
    return j;
    }
int main( int argc, char *argv[] )
    {
    int ch,i=0;
    char str[8];
    int p;
    printf("Enter names:");
    while ((ch=getchar())!='\n')
        {if (i<8)
            {if (ch==' ')
                {str[i]='\0';
                check_printer(str);
                str[8]='\0';
                str[7]='\0';
                str[6]='\0';
                str[5]='\0';
                str[4]='\0';
                str[3]='\0';
                str[2]='\0';
                str[1]='\0';
                str[0]='\0';
                i=0;
                }
            else
                {str[i++]=ch;}
            }
        str[i]='\0';
        }
    check_printer(str);}