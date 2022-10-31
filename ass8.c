#include<stdio.h>
#include<math.h>

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

int get_menu()//�ѧ��ѹ����
{
 int select;//��˹������� select �������¡��ѧ��ѹ get_int(int min,int max)
 printf("###########################################\n");//UI
 printf("#                Menu Test                #\n");//UI
 printf("###########################################\n");//UI
 printf("#            1.Test_Function 1            #\n");//UI
 printf("#            2.Test_Function 2            #\n");//UI
 printf("#            3.Test_Function 3            #\n");//UI
 printf("#            0.Exit                       #\n");//UI
 printf("###########################################\n");//UI
 printf("Enter your number :");//��ʴ������������Ţ 0-3 �������͡����
 select=get_int(0,3);//��˹���� select=get_int �¤�ҵ���ش�������� ��� 1 ���� ����٧�ش�������� ��� 3
 return select;//�纤�� select
}

void Add_data(double data[],int *count)//�ѧ��ѹ��������Ţ
{
 int i=0;//��С�ȵ����� i ����Ѻ��õ�Ǩ�ͺ����Ѻ���
 double a;//��С�ȵ����� a ����Ѻ�Ѻ����Ţ
 char ch;//��С�ȵ����� ch ����Ѻ�Ѻ����ѡ��
 printf("Enter number of data : ");//�͡������������Ţ����������� data
 do {
     i=scanf("%lf%c",&a,&ch);//��� i �繨ӹǹ��Դ�ͧ����Ѻ���
    if(i>0&&a>0)//��Ҫ�Դ�ͧ��ҵ���Ţ����Ѻ�ҡ���� 0 ���� �繨ӹǹ����ǡ ������͹� if
     {
      data[*count]=a;//��� data[*count]�� a
      *count=*count+1;//��� *count ������ҷ��� 1
     }
    }while(i!=0&&ch!='\n');//�Ѻ��ҼԴ������
     rewind(stdin);//clear ��ҷ���Ѻ�Դ������
 }

 void Print_data(double data[],int count)//�ѧ��ѹ��ʴ��ŵ���Ţ�������� data
 {
   int i;//��С�ȵ����� i ����Ѻ loop for
   for(i=0;i<count;i++)//ǹ�ٻ�������ͺ��� 0-count �������� 1
   {
    printf("data[%d]=%lf\n",i,data[i]);//��ʴ����
   }
   printf("****************************\n");//UI
 }

 void Delete_data(double data[],int *count,int id)//�ѧ��ѹź����Ţ
 {
   int i;//��С�ȵ����� i ����Ѻ loop for
   for(i=id;i<*count-1;i++)//ǹ�ٻ�������ͺ��� 0-count �������� 1
   {
    data[i]=data[i+1];//����͹��ҵ�ǶѴ�� ����ź��ҷ���ͧ���
   }
   *count=*count-1;//Ŵ�ӹǹ����Ţ����ͧ���ź
 }

 void Calculate_data(double data[],int count,double *mean,double *sd,double *min,double *max)//�ѧ��ѹ�ӹǳ�� ��������,��ǹ���§ູ�ҵðҹ,��ҵ���ش,����٧�ش
 {
   int i;//��С�ȵ����� i ����Ѻ loop for
   double sum,sum2;//��С�ȵ����� sum ����Ѻ�纤�Ҽ����, , sum2 ����Ѻ�纤�Ҽ�������ѧ�ͧ
   *min=data[0];//�Ţ�����á
   for(i=0,sum=0,sum2=0;i<count;i++)//ǹ�ٻ�������ͺ��� 0-count �������� 1
   {
     sum=sum+data[i];//sum �纼źǡ�ͧ�Ţ������
     sum2=sum2+data[i]*data[i];//sum2 �纼źǡ���ͧ�ͧ����Ţ������
     if(data[i]<*min)//��� data �դ�ҹ��¡��� min
     {
      *min=data[i];//��� data �� min �෹
     }
     if(data[i]>*min)//��� data �դ���ҡ���� min
     {
      *max=data[i];//��� data �� max �෹
     }
   }
   *mean=sum/count;//�ٵäӹǳ�Ҥ�������
   *sd=sqrt(sum2/count-*mean**mean);//�ٵäӹǳ�Ҥ����ǹ���§ູ�ҵðҹ
 }

 int main()
 {
  double data[200],del=0,mean,sd,min,max;//��С�ȵ����� Array data[100] ����Ѻ�Ѻ��ҵ���Ţ ,mean ����Ѻ�������� ,sd ����Ѻ��ǹ���§ູ�ҵðҹ  ,  min ����Ѻ��ҵ���ش , max ����Ѻ����٧�ش , del ����Ѻ����Ţ����ͧ���ź
  int count=0,select=0,i;//��С�� count ����Ѻ�纨ӹǹ����Ţ� data , select ����Ѻ�����㹿ѧ��ѹ get_manu()
  char ch;//��С�� ch ����Ѻ����ѡ��
  do
  {
   select=get_menu();//���¡��ѧ��ѹ get_manu()
   if(select==1)//���͡���� 1 ������������Ţ
   {
    Add_data(data, &count);//���¡��ѧ��ѹ��������Ţ
    if(count>=1)//�ӹǹ����Ţ����Ѻ�դ���ҡ������ҡѺ 1 ������͹�� if
    {
     Print_data(data, count);//���¡��ѧ��ѹ��ʴ��ŵ���Ţ�������� data
    }
    else//����յ���Ţ �������� else
    {
     printf("ERROR INPUT WRONG TYPE\n");//����Ţ����͹�Դ���͹�
    }
    printf("Press any key to exit\n");//�͡�������ҡ�����㴡��������˹��������ѡ
    getchar();//������㴡������ͷӧҹ���
   }

   else if(select==2&&count!=0)//���͡���� 2 ����ź����Ţ
   {
    Print_data(data, count);//���¡��ѧ��ѹ��ʴ��ŵ���Ţ�������� data
    printf("Input number you want to delete : \n");//�͡���������͹����Ţ�����ҡź
    scanf("%lf",&del);//�纤�� del �ҤԴ��к�
    for(i=0;i<count;i++)//ǹ loop for �������ͺ��� 0-count
    {
     if(data[i]==del)//��� dal=data[i] ������͹�� if
     {
      printf("Delete Sure? If you sure press y/Y\n");//�����������ź������������
      scanf(" %c",&ch);//�Ѻ��ҵ���ѡ��
      if(ch=='y'||ch=='Y')//��ҵ���ѡ�÷���Ѻ���� y/Y ������͹� if
      {
       Delete_data(data, &count,i);//���¡��ѧ��ѹź����Ţ
      }
      else//���������
        {printf("Cancle Delete Number\n");}//�͡��������¡��ԡ���ź����Ţ
      if(count==0)//����յ���Ţ ������͹� if
      {
       printf("Not have any number in data\n");//�͡�����������յ���Ţ� data
      }
      else{Print_data(data, count);}//���¡��ѧ��ѹ��ʴ��ŵ���Ţ�������� data
     }
    }
    printf("Press any key to exit\n");//�͡�������ҡ�����㴡��������˹��������ѡ
    getchar();//������㴡������ͷӧҹ���
   }

   else if(select==3&&count!=0)//���͡���� 3 ���٤ӹǳ�Ҥ������� ��ǹ���§ູ�ҵðҹ
   {
    Print_data(data, count);//���¡��ѧ��ѹ��ʴ��ŵ���Ţ�������� data
    if(count>1)//�ӹǹ����Ţ����Ѻ�դ���ҡ���� 1 ������͹� if
    {
     Calculate_data(data, count, &mean, &sd, &min, &max);//���¡��ѧ��ѹ�ӹǳ�� ��������,��ǹ���§ູ�ҵðҹ,��ҵ���ش,����٧�ش
     printf("Mean= %g,SD= %g,Min= %g,Max= %g\n",mean,sd,min,max);//��ʴ���
    }
    else//�ӹǹ����Ţ�����������¡�����ҡѺ 1
    {
     printf("Error can not calculate\nShould input number more than 2 numbers\n");//�͡���������������ö�ӹǳ�� ��ͧ�յ���Ţ�ҡ���� 2 �ӹǹ
    }
    printf("Press any key to exit\n");//�͡�������ҡ�����㴡��������˹��������ѡ
    getchar();//������㴡������ͷӧҹ���
   }

   else if(count==0&&select!=0)//����բ�����
   {
    printf("Not have number in data\n");//�͡������������բ�����
    printf("Press any key to menu\n");//�͡�������ҡ�����㴡��������˹��������ѡ
    getchar();//������㴡������ͷӧҹ���
   }

  } while(select!=0);
  printf("End Program\n");//select=0
  return 0;
 }

