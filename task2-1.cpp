#include<stdio.h>
int main (void)

{
int height, length, width, volume, weight;  
height=9;
length=9;
width=9;
volume=height*length*width;
weight=(volume+165)/166;


printf("volume (cubic inches):%d\n",volume);
printf("demensional weight(pounds):%d\n", weight);

}