#include <stdio.h>
#include <math.h>
int main()
{
 double deg,rad,tx,sy,sx,t0,deltax,x,u,g=-9.81;
  char ch,p;
  char bub[80];
  printf("Hello,This program is calculate shot the ball into the goal.\n");
  do
  {
  printf("Enter velocity\n");
 while(scanf("%lf%c",&u,&p)==0||p!='\n')
  {
  gets(bub);
   printf("Invalid Please enter velocity again\n");
  }
  printf("Enter angle\n");
while(scanf("%lf%c",&deg,&p)==0||p!='\n')
  {
   gets(bub);
   printf("Invalid Please enter angle again\n");
  }
  printf("Enter distance\n");
while(scanf("%lf%c",&x,&p)==0||p!='\n')
  {
   gets(bub);
   printf("Invalid Please enter distance again\n");
  }

  rad=(deg*M_PI)/180;
  tx=x/(u*cos(rad));
  sy=(x*tan(rad)+((g*x*x/pow(u*cos(rad),2))/2));
  sx=-(u*u*sin(2*rad))/g;
  t0=-(2*u*sin(rad))/g;
  deltax=x+(u*u*sin(2*rad))/g;
  if(sx<x)
  {
   printf("T_T !!Fail ball!!\nThe ball lands before it reaches the gate %.2lf meter\nusing time %.2lf seconds\n",deltax,t0);
  }
  else if(sy>=2.44)
  {
   printf("T_T !!Overshoot!!\nThe ball height the fall %.2lf meter\nusing time %.2lf seconds\n",sy,tx);
  }
  else if(tx>0.5)
  {
   printf("T_T !!Save ball!!\nThe ball height the fall %.2lf meter\nusing time %.2lf seconds\n",sy,tx);
  }
  else
  {
   printf("!!!!!G O A L!!!!!\nThe ball height the fall %.2lf meter\nusing time %.2lf seconds\n",sy,tx);
  }
  do
  {
   printf("Enter y to play program again or n to exit the program.\n");
   scanf(" %c",&ch);
  }while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
  }while(ch=='y'||ch=='Y');
  printf("End program");
}
