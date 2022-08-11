#include<stdio.h>

int main (void)

{
float dm, pl, ds, total,avg;


printf("Put the discrete math score:");
scanf("%f",&dm);
printf("Put the programming language score:");
scanf("%f",&pl);
printf("Put the data structure score:");
scanf("%f",&ds);
total=dm+pl+ds;
avg=total/3;


if (avg>95)
printf("The average score is %f and the grade is A+",avg);
else if (avg>90)
 printf("The average score is %f and the grade is A0",avg);
else if (avg>85)
 printf("The average score is %f and the grade is B+",avg);
else if (avg>80)
 printf("The average score is %f and the grade is B0",avg);
else if (avg>75)
  printf("The average score is %f and the grade is C+",avg);
else if (avg>70)
printf("The average score is %f and the grade is C0",avg);
else
printf("The average score is %f and the grade is F",avg);


return 0;
}