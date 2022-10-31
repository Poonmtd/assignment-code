#include<stdio.h>
#include<math.h>
#include<time.h>
long int fibonacci(int n)
{
 long int ans=1,fi,fc=1,ft=0,i;
 if(n<=1)
 ans=n;
 else
 {
  for(i=2;i<=n;i++)
      {
       fi=fc+ft;
       ft=fc;
       fc=fi;
      }
      ans=fi;
 }
 return ans;
}
long int factorial(int n)
{
  long int ans=1,i;
  i=n;
  while(i>0)
  {
   ans=ans*i;
   i=i-1;
  }
  return ans;
}

long int nCr(int n,int r)
{
 long int ans;
 ans=factorial(n)/(factorial(r)*factorial(n-r));
 return ans;
}
long int GCD(int n,int r)
{
 int ans;
 while((n%ans || r%ans)!=0)
 ans--;
 return ans;
}
int get_int(int min,int max)
{
 int ans;
 char ch;
 while((scanf("%d%c",&ans,&ch)!=1 && ch!='\n')||ans<min||ans>max)
 {
  rewind(stdin);
  printf("Error input again.");
 }
 return ans;
}
void shot_ball()
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
  printf("\nEnd program\n");
}
int get_manu()
{
 int select;
 printf("########################################\n");
 printf("#           Manu of Calculate          #\n");
 printf("########################################\n");
 printf("#      1.Fibonacci function            #\n");
 printf("#      2.Combinaton number             #\n");
 printf("#      3.Find GCD (n,r)                #\n");
 printf("#      4.Shot the ball into the goal   #\n");
 printf("########################################\n");
 printf("Enter your number :");
 select=get_int(0,4);
 return select;
}
int main()
 {
  int select,n,r,x,y,count;
  long int ans;
  char ch;
   do{
      select=get_manu();
      if(select==1)
      {
       do
       {
        printf("Fibonacci function\n");
        printf("Enter n=");
        n=get_int(0,10);
        ans=fibonacci(n);
        printf("\n ans of fibonacci(%d) = %d\n",n,ans);
        do
        {
         printf("\nEnter y to play again or n to exit.\n");
         scanf(" %c",&ch);
        }
        while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
       }
       while(ch=='y'||ch=='Y');
      }
      else if(select==2)
      { do
        {printf("Combinaton number\n");
         printf("Enter n=");
         n=get_int(1,10);
         printf("Enter r=");
         r=get_int(1,n);
         ans=nCr(n,r);
         printf("\n ane of %dC%d = %d\n",n,r,ans);
         do
        {
         printf("\nEnter y to play again or n to exit.\n");
         scanf(" %c",&ch);
        }
        while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
       }
       while(ch=='y'||ch=='Y');
      }
      else if(select==3)
      { do
        {printf("Find GCD (n,r)\n");
         printf("Enter n=");
         n=get_int(1,100000);
         printf("Enter r=");
         r=get_int(1,100000);
         ans=GCD(n,r);
         printf("\n ans of GCD(%d,%d) = %d\n",n,r,ans);
         do
        {
         printf("\nEnter y to play again or n to exit.\n");
         scanf(" %c",&ch);
        }
        while(ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
       }
       while(ch=='y'||ch=='Y');
      }
      else if(select==4)
      {
        shot_ball();
      }
 }while(select!=0);
 printf("\nEnd Program\n");
 return 0;
 }
