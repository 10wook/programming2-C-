#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int read_line(char str[], int n, FILE *a)
{
 int ch, i = 0;
 while ((ch = fgetchar()) != '\n')
 if (i < n)
 str[i++] = ch;
 str[i] = '\0'; /* terminates string */
 return i; /* number of characters stored */
}
int main (void){
    FILE *fp;
    fp=fopen("list.txt","r");
    char ch[13][11]={"","","","","","","","","","","","",""};
    char c[6][11]={"aaaaaaaaaa","aaaaaaaaaa","aaaaaaaaaa","aaaaaaaaaa","aaaaaaaaaa","aaaaaaaaaa"};
    int num[6]={0,};
    char p;
    int n=0,m=0;
        if((fp=fopen("list.txt","r"))==NULL)
        {
        fprintf(stderr,"can't open\n");
        exit(EXIT_FAILURE);
        }
    while ((p= getc(fp)) != EOF) 
    {if (p=='\n')
        {n=n+1;
        m=0;
        continue;}
    ch[n][m]=p;
    m=m+1;}
        
        
        

    for(int i=0;i<13;i=i+1)
        {for (int j=0;j<6;j=j+1)
            {if(strncmp(ch[i],c[j],11)==0)
                num[j]=num[j]+1;
            else if (j==5)
                {for (int k=0;k<6;k=k+1)
                    {if(num[k]==0)
                        {num[k]=1;
                        strncpy(c[k],ch[i],11);
                        break;}
                    }
                
                }
                


            }
        }

for (int i=0;i<6;i=i+1) 
    {printf("%s:%d\n",c[i],num[i]);}

fclose(fp);






}