#include <stdio.h>
int get_int(int min,int max)//�ѧ��ѹ��ͧ�ѹ����������żԴ��Ҵ
{
 int ans;//��˹������� ans �Ѻ��ҵ���Ţ
 char ch;//��˹������� ch ��Ǩ�ͺ����� enter
 while((scanf("%d%c",&ans,&ch)!=1 && ch!='\n')||ans<min||ans>max)//��Ǩ�ͺ��ҷ���Ѻ��һ��������ҷ���Ѻ���ҡ�����ҡѺ 1 ���� ����ѡ�������� enter �ж١�纤������������
 {
  rewind(stdin);//������纤�ҷ���͹���ç�������͹�
  printf("Error input again.");//��ʴ����������������ա����
 }
 return ans;//�纤�� ans
}

int get_manu()//�ѧ��ѹ����
{
 int select;//��˹������� select �������¡��ѧ��ѹ get_int(int min,int max)
 printf("###########################################\n");//UI
 printf("#                Manu Test                #\n");//UI
 printf("###########################################\n");//UI
 printf("#            1.Test_Function 1            #\n");//UI
 printf("#            2.Test_Function 2            #\n");//UI
 printf("#            3.Test_Function 3            #\n");//UI
 printf("#            4.Test_Function 4            #\n");//UI
 printf("#            5.Test_Function 5            #\n");//UI
 printf("###########################################\n");//UI
 printf("Enter your number :");//��ʴ������������Ţ 0-5 �������͡����
 select=get_int(0,5);//��˹���� selest=get_int �¤�ҵ���ش�������� ��� 1 ���� ����٧�ش�������� ��� 5
 return select;//�纤�� select
}

double sigma1(int n)//�ѧ��ѹ͹ء���Ţ ( ��� )test#1
{
 int i;//��˹������� i �Ѻ����繨ӹǹ��� ����Ѻ loop for
 double ans;//��˹������� ans �����纼źǡ�ͧ͹ء���Ţ
 for(i=1,ans=0;i<=n;i++)//ans �������=0 �������ѵԡ�úǡ �ҡ i���¡�����ҡѺ n �������͹�� loop ��������
 {
  ans=ans+2*i;//��� ans �纼źǡ͹ء���Ţ 2i �������ͺ
 }
 return ans;//�纤�� ans
}

double sigma2(int n)//�ѧ��ѹ͹ء���Ţ ( ��ǹ ) test#1
{
 int i;//��˹������� i �Ѻ����繨ӹǹ��� ����Ѻ loop for
 double ans;//��˹������� ans �����纼źǡ�ͧ͹ء���Ţ
 for(i=1,ans=1;i<=n;i++)//ans �������=1 �������ѵԡ�äٳ �ҡ i���¡�����ҡѺ n �������͹�� loop ��������
 {
  ans=ans*i;//��� ans �纼źǡ͹ء���Ţ i �������ͺ
 }
 return ans;//�纤�� ans
}

void Test_Function1(int n,double termR[],double dataR[],int *count)//�ѧ��ѹ test#1
{
 double term1,data1=0;//��˹������� term1 �纤��sigma1(i)/sigma2(i) ����  data1 �纼�����������ͺ
 int i;//��˹������� i ����Ѻ loop for
 for(i=1;i<=n;i++)//�ҡ i ���¡�����ҡѺ n ���ӹǳ� loop ��������
 {
  term1=sigma1(i)/sigma2(i);//��˹���� term1=sigma1(i)/sigma2(i)
  data1=term1+data1;//��˹���� data1=term1+data1 �纼�����������ͺ
  termR[i]=term1;//�纤�� tern1 �  array termR[]
  dataR[i]=data1;//�纤�� data1 � array dataR[]
  *count=i;//��˹� pointer count=i
 }
}

void printTest_Function1(double termR[],double dataR[],int count)//�ѧ��ѹ��ʴ��ŷҧ˹�Ңͧ�ѧ��ѹ test#1
{
 printf("Test Function #1\n");//UI
 printf("*************************************\n");//UI
 printf("*  i   *      fi      *     sum     *\n");//UI
 printf("*************************************\n");//UI
 for(int i=1;i<=count;i++)//�ӡ����ʴ���ҵ������ͺ 1-count
 {
  printf("* %2d   *%10.6lf    * %10.6lf  *\n",i,termR[i],dataR[i]);//��ʴ���� i,termR[i],dataR[i]
 }
 printf("*************************************\n");//UI
 printf("ans = %lf\n",dataR[count]);//�ʴ��Ťӵͺ
}

int get_Fibo(int n)//�ѧ��ѹ��⺹ѡ��
{
 int fi=0,fc=1,ft=0,i;//��˹������� i �繵����á  ���� fc �繵�Ƿ�� 2 �ͧ�Ţ��⺹ѡ��
  for(i=2;i<=n;i++)//�ӹǳ�������ͺ 2-n
      {
       fi=fc+ft;//f(n)=f(n-2)+f(n-1)
       ft=fc;//f(n-2)=f(n-1) ����͹���
       fc=fi;//f(n-1)=f(n) ����͹���
      }
 return fi;//�纤�� fi
}

void Test_Function2(int n,int termI[],int dataI[],int *count)//�ѧ��ѹ test#2
{
 int i,data2;//��˹�������  i ����Ѻ loop for ����  data2 �纼�����������ͺ
 for(i=2,*count=0;*count<n;i++)//�ӹǳ�������ͺ 2-n �Ѻ�ͺ�����������͹�� if
 {
  data2=get_Fibo(i);//��˹���� data2=gat_Fibo(i)
  if(data2%2==0)//��� data2 ��� 2 ŧ��� �����Ţ��� �ͧ��⺹ѡ��
  {
   *count=*count+1;//��˹���� count+1
   termI[*count]=i;//�纤�� i �  Array termI[*count]
   dataI[*count]=data2;//�纤�� data2 �  Array dataI[*count]
  }
 }
}

void printTest_Function2(int termI[],int dataI[],int count)//�ѧ��ѹ��ʴ��ŷҧ˹�Ңͧ�ѧ��ѹ test#2
{
 printf("\nTest Function #2\n");//UI
 printf("***********************************\n");//UI
 printf("* count *    i    *     fi    *\n");//UI
 printf("***********************************\n");//UI
 for(int i=1;i<=count;i++)//�ӡ����ʴ���ҵ������ͺ 1-count
 {
  printf("*  %2d   *   %2d    *  %7d      *\n",i,termI[i],dataI[i]);//��ʴ���� i,termI[i],dataI[i]
 }
 printf("***********************************\n");//UI
 printf("count = %d, ans = %d\n",count,dataI[count]);//��ʴ��Ťӵͺ
}

int get_Prime(int n)//�ѧ��ѹ�ӹǹ੾��
{
 int i,check=1;//��˹������� i ����Ѻ loop for ���е����� check �����纤�� 0,1
 for(i=2;i<n;i++)//�ӹǳ�������ͺ 2-n
 {
  if(n%i==0)//��� n ��� i ŧ��Ǩ�������͹�� if
  {
   check=0;//��� check=0
  }
 }return check;//�纤�� ckeck
}

void Test_Function3(int min,int max,int termI[],int dataI[],int *count)//�ѧ��ѹ test#3
{
 int i,n,sum;//��˹������� i ����Ѻ loop for,n ����Ѻ�纤�Ңͧ�ѧ��ѹ Prime,sum ����Ѻ�纤�Ҽ����
 for(i=min+1,*count=0,sum=0;i<max;i++)//��� i ��� ��ҷ�����·���ش(min) ��� min ������ҷ��� 1 ���֧��ҷ���ҡ����ش(max)
 {
  n = get_Prime(i);//��� n �纤�Ң᧿ѧ��ѹ Prime ����繨ӹǹ੾�� n=1 ������ n=0
  if(n==1)//����繨ӹǹ੾�Ш�������͹�� if
  {
   *count=*count+1;//��˹���� count+1
   termI[*count]=i;//�纤�� i �  Array termI[*count]
   sum=sum+termI[*count];//sum �纤�Ҽ�����ͧ  termI[*count]
   dataI[*count]=sum;//�纤�� sum � Array dataI[*count]
  }
 }
}

void printTest_Function3(int termI[],int dataI[],int count)//�ѧ��ѹ��ʴ��ŷҧ˹�Ңͧ�ѧ��ѹ test#3
{
 printf("\nTest Function #3\n");//UI
 printf("********************************\n");//UI
 printf("*  no  *    i     *     sum    *\n");//UI
 printf("********************************\n");//UI
 for(int i=1;i<=count;i++)//�ӡ����ʴ���ҵ������ͺ 1-count
 {
  printf("* %2d   *   %2d     *   %3d      *\n",i,termI[i],dataI[i]);//��ʴ���� i,termI[i],dataI[i]
 }
 printf("********************************\n");//UI
 printf("count = %d, sum = %d\n",count,dataI[count]);//��ʴ��Ťӵͺ
}

void Test_Function4(int max,int termI[],int dataI[],int *count)//�ѧ��ѹ test#4
{
 int i=1,j=40,sum=0;//��˹������� sum ����Ѻ�纼����,i ����Ѻ loop while,j ���� i �繾�����á
 *count=0;//������ͺ��� 0
 sum=i*j;//��˹���� sum=i*j
 while(sum<max&&i<40&&j>1)//��� sum ���¡��� max ���� i ���¡��� 40 ���� j �ҡ���� 1 �������͹�� while
 {
  *count=*count+1;//��˹���� count+1
  termI[*count]=i*j;//�纤�� i*j � Array termI[*count]
  dataI[*count]=sum;//�纤�� sum � Array dataI[*count]
  i=i+2;//i ������鹷��� 2 �������ͺ
  j=j-2;//j Ŵŧ���� 2 �������ͺ
  sum=sum+(i*j);//sum ������鹷��� i*j �������ͺ
 }
}

void printTest_Function4(int termI[],int dataI[],int count)//�ѧ��ѹ��ʴ��ŷҧ˹�Ңͧ�ѧ��ѹ test#4
{
 printf("\nTest Function #4\n");//UI
 printf("********************************\n");//UI
 printf("*   i  *    fi     *     sum   *\n");
 printf("********************************\n");//UI
 for(int i=1;i<=count;i++)//�ӡ����ʴ���ҵ������ͺ 1-count
 {
  printf("*  %2d  *   %3d     *     %4d  *\n",i,termI[i],dataI[i]);//��ʴ���� i,termI[i],dataI[i]
 }
 printf("********************************\n");//UI
 printf("n = %d, ans = %d\n",count,dataI[count]);//��ʴ��Ťӵͺ
}

void Test_Function5(int n,int dataI[],int *count)//�ѧ��ѹ test#5
{
 int i,ans,check;//��˹������� i ����Ѻ loop for,ans ����Ѻ�纤�� a ������ n,check ����Ѻ��Ǩ�ͺ�������ͧ���
 *count=0;//������ͺ��� 0
 for(i=1;*count<n;i++)//�ӹǳ�������ͺ��� 1-n
 {
  ans=1+((i-1)*3);//an ������⨷���˹����
  check=ans%5;//��Ǩ�ͺ�������ͧ�����ô��� 5 ���������������
  if(check==1)//�����ɨҡ������=1 �����͹�� if
  {
   *count=*count+1;//��˹���� count+1
   dataI[*count]=ans;//�纤�� sum � Array dataI[*count]
  }
 }
}

void printTest_Function5(int dataI[],int count)//�ѧ��ѹ��ʴ��ŷҧ˹�Ңͧ�ѧ��ѹ test#5
{
 printf("\nTest Function #5\n");//UI
 printf("*******************\n");//UI
 printf("*  no  *   term   *\n");//UI
 printf("*******************\n");//UI
 for(int i=1;i<=count;i++)//�ӡ����ʴ���ҵ������ͺ 1-count
 {
  printf("* %2d   *    %3d   *\n",i,dataI[i]);//��ʴ���� i,dataI[i]
 }
 printf("*******************\n");//UI
 printf("count = %d\n",count);//��ʴ��Ťӵͺ
}


int main()//�ѧ��ѹ��ѡ
{
 double termR[20],dataR[20];//��˹� Array ����� double(�ȹ���) �����纼���������ͺ
 int termI[20],dataI[20];//��˹� Array ����� int(�ӹǹ���) �����纼���������ͺ
 int count,select,n=0,max=0,min=0;//��˹�������  count ���Ѻ *count,select ���Ѻ get_manu(),n,max min ���Ѻ��ҷ���͹
 char ch;//��˹� ch ���Ѻ �����ŷ���繵��˹ѧ���
 do
 {
  select=get_manu();//select �Ѻ��� get_manu()����͹
   if(select==1)//select=1
   {do
    {
     printf("FUNCTION_1\n");//UI
     printf("Enter number:");//UI
     n=get_int(1,10);//�Ѻ����������� 1-10
   	 Test_Function1(n,termR,dataR,&count);//���¡��ѧ��ѹ test#1
   	 printTest_Function1(termR,dataR,count);//���¡��ѧ��ѹ��ʴ��ŷҧ˹�Ңͧ�ѧ��ѹ test#1
        {
         printf("\nEnter y to run again or to n exit.\n");//�ҡ �� y/Y ���������ѹ�����ա���� ,�� n/N �͡�ҡ������
         scanf(" %c",&ch);//�Ѻ����ѡ��
        }
        while(ch!='y' && ch!='Y' && ch!='n' && ch!='N');//�ҡ������ѡ�÷������� y,Y,n,N �����������������ա����
       }
       while(ch=='y');//�������ѹ�����ա����
   }
   else if(select==2)//select=2
   {do
    {
     printf("FUNCTION_2\n");//UI
     printf("Enter  number:");//UI
     n = get_int(1,10);//�Ѻ����������� 1-10
   	 Test_Function2(n,termI,dataI,&count);//���¡��ѧ��ѹ test#2
   	 printTest_Function2(termI,dataI,count);//���¡��ѧ��ѹ��ʴ��ŷҧ˹�Ңͧ�ѧ��ѹ test#2
     do
        {
         printf("\nEnter y to run again or to n exit.\n");//�ҡ �� y/Y ���������ѹ�����ա���� ,�� n/N �͡�ҡ������
         scanf(" %c",&ch);//�Ѻ����ѡ��
        }
        while(ch!='y' && ch!='Y' && ch!='n' && ch!='N');//�ҡ������ѡ�÷������� y,Y,n,N �����������������ա����
       }
       while(ch=='y');//�������ѹ�����ա����
   }
   else if(select==3)//select=3
   {do
    {
     printf("FUNCTION_3\n");//UI
     printf("Enter min number: ");//UI
     min=get_int(1,100);//�Ѻ����������� 1-100
     if(min==1)//���  min=1 �������͹�� if
     {
      min=2;//����¹  min=2
     }
     printf("Enter max number: ");//UI
     max=get_int(1,100);//�Ѻ����������� 1-100
   	 Test_Function3(min,max,termI,dataI,&count);//���¡��ѧ��ѹ test#3
   	 printTest_Function3(termI,dataI,count);//���¡��ѧ��ѹ��ʴ��ŷҧ˹�Ңͧ�ѧ��ѹ test#3
     do
        {
         printf("\nEnter y to run again or to n exit.\n");//�ҡ �� y/Y ���������ѹ�����ա���� ,�� n/N �͡�ҡ������
         scanf(" %c",&ch);//�Ѻ����ѡ��
        }
        while(ch!='y' && ch!='Y' && ch!='n' && ch!='N');//�ҡ������ѡ�÷������� y,Y,n,N �����������������ա����
       }
       while(ch=='y');//�������ѹ�����ա����
   }
   else if(select==4)//select=4
   {do
    {
     printf("FUNCTION_4\n");//UI
     printf("Input max number:");//UI
     max=get_int(1,5000);//�Ѻ����������� 1-5000
   	 Test_Function4(max,termI,dataI,&count);//���¡��ѧ��ѹ test#4
   	 printTest_Function4(termI,dataI,count);//���¡��ѧ��ѹ��ʴ��ŷҧ˹�Ңͧ�ѧ��ѹ test#4
     do
        {
         printf("\nEnter y to run again or to n exit.\n");//�ҡ �� y/Y ���������ѹ�����ա���� ,�� n/N �͡�ҡ������
         scanf(" %c",&ch);//�Ѻ����ѡ��
        }
        while(ch!='y' && ch!='Y' && ch!='n' && ch!='N');//�ҡ������ѡ�÷������� y,Y,n,N �����������������ա����
       }
       while(ch=='y');//�������ѹ�����ա����
   }
   else if(select==5)//select=5
   {do
    {
     printf("FUNCTION_5\n");//UI
     printf("Enter number:");//UI
     n=get_int(1,15);//�Ѻ����������� 1-15
   	 Test_Function5(n,dataI,&count);//���¡��ѧ��ѹ test#5
   	 printTest_Function5(dataI,count);//���¡��ѧ��ѹ��ʴ��ŷҧ˹�Ңͧ�ѧ��ѹ test#5
      do
        {
         printf("\nEnter y to run again or n to exit.\n");//�ҡ �� y/Y ���������ѹ�����ա���� ,�� n/N �͡�ҡ������
         scanf(" %c",&ch);//�Ѻ����ѡ��
        }
        while(ch!='y' && ch!='Y' && ch!='n' && ch!='N');//�ҡ������ѡ�÷������� y,Y,n,N �����������������ա����
       }
       while(ch=='y');//�������ѹ�����ա����
   }
 } while(select!=0);
}





