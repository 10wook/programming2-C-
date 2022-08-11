#include<stdio.h>
int main (void)

{
int height, length, width, volume, weight;  
height=8;
length=12;
width=10;
volume=height*length*width;
weight=(volume+165)/166;
printf("volume=%d\n",volume);


printf("Dimensions:%dx%dx%d\n",length, width, volume);
printf("volume (cubic inches):%d\n",weight);
printf("demensional weight(pounds):%d\n", weight);

}