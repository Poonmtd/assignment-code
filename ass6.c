#include<stdio.h>
#include<math.h>

double get_num()
{
  double num;
  char ch;
  while(scanf("%lf%c",&num,&ch)!=2||ch!='\n')
  {
   rewind(stdin);
   printf("\nError please enter value again: ");
  }
  return num;
}

int Newton_Raphson(double a,double b,double c,double err,double xp,double *xn)
{
 double delta;
 int count=0;
 do
 {
  if((2*a*xp)+b==0)
  {
   xp=xp+0.0000001;
  }
  else
  {
   delta=((a*xp*xp)+(b*xp)+c)/((2*a*xp)+b);
   *xn=xp-delta;
   xp=*xn;
  }
  count++;
 }
 while(fabs(delta)>err&&count<1000);
 if(count<1000)
 {
  return count;
 }
 else
 {
  return 0;
 }
}

void Calculate_Newton_Rapson()
{ double a,b,c,x1,x2;
  int count=0;
  printf("Calculate aX^2+bX+c=0\n");
  printf("Enter value a: ");
  a=get_num();
  printf("\nEnter value b: ");
  b=get_num();
  printf("\nEnter value c: ");
  c=get_num();
  count=Newton_Raphson(a,b,c,0.0000001,-100.123,&x1);
  count=Newton_Raphson(a,b,c,0.0000001,100.123,&x2);
  if(count==0)
  {
   printf("\n! E R R O R !\n");
  }
  else if(fabs(x1-x2)<=0.00001)
  {
   printf("\nx=%g\n",x1);
   printf("\ncount=%d\n",count);
  }
  else
  {
   printf("\nx1=%g\n",x1);
   printf("\nx2=%g\n",x2);
   printf("\ncount=%d\n",count);
  }
}

int main()
{
 char ch;
 do
 {
  Calculate_Newton_Rapson();
  do
  {
   printf("\nEnter y to calculate again or n to exit the program.\n");
   scanf(" %c",&ch);
  }
  while(ch!='n'&&ch!='N'&&ch!='y'&&ch!='Y');
 }
 while(ch=='y'||ch=='Y');
 return 0;
}

