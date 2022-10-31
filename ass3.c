#include <stdio.h>
#include <time.h>
int main()
{
   int x,y,count;
   char name[30],ch;
   printf("NUMBER GUESSING PROGRAM\n");
   printf("Let's play!!!\n");
   printf("Enter your name \n");
   scanf("%s",&name);
 do
   {
    printf("Hello %s. Let's play!\n",name);
    srand(time(NULL));
    x=rand()%100+1;
    count=0;
    printf("%d\n",x);
      do
       {
        count=count+1;
        printf("Round %d\n",count);
        printf("Enter the number your like \n");
        scanf("%d",&y);
        if(x==y)
        {
         printf("!!You can guess the number correctly!!\n");
        }
        else if(x<y)
        {
         printf("Your number is too high\n");
        }
        else
        {
         printf("Your number is too low\n");
        }
        if(count==7 && x!=y)
        {
         printf("You are loser but you don't give up\n");
         printf("The correct number is %d\n",x);
        }
       }
     while(count!=7 && y!=x);

    do
      {
        printf("Enter y to play again or n to exit the game.\n");
        scanf(" %c",&ch);
      }
       while(ch!='y'&& ch !='Y'&& ch!='n');
    }
     while (ch == 'y'|| ch == 'Y');
     printf("\nEnd game bye eiei\n");
     return 0;
}
