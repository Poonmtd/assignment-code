#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int acount,bpcount,bcount,cpcount,ccount,dpcount,dcount,fcount;
double min,max,mean,sd,minmid,maxmid,meanmid,sdmid,minfi,maxfi,meanfi,sdfi,minatten,maxatten,meanatten,sdatten;

typedef struct grade_info
{
    long long id;
    char name[40];
    double mid,fi,atten,total,qpoint;
    char grade[3];
}gradetype;

void Load_Student_File (char *name,gradetype st[],int *stcount)
{
  FILE *fp; //�ͧ�������������Դ���
  gradetype x;//�ͧ���������͹��ҹ������ 1 ���
  if ((fp = fopen(name, "r")) != NULL )//����ͺ����Դ�������ҹ��������͹�� if
   { *stcount=0;//��˹����������Ѻ�ӹǹ������
     while (fscanf(fp,"%llu ,%[^,] ,%lf ,%lf ,%lf", &x.id, x.name,&x.mid,&x.fi,&x.atten)==5)//�Ѻ���
      { x.total = x.mid+x.fi+x.atten;//�ӹǳ���๹���
        st[*stcount] = x;//�Ӣ����ŷ����ҹ������ st
        *stcount = *stcount+1; }//�Ѻ���������Ũӹǹ�����ҹ��
    fclose(fp);//�Դ���
   printf("\nTotal read %2d records. ",*stcount);//UI
}
else //��ҹ��������
printf("\nError Can't Read File SCORE.CSV\n");//UI

}

void print_data(gradetype x)//�ѧ��ѹ��ʴ������� 1 ��
{
    printf("%llu %-40s %5.1lf %5.1lf %5.1lf %5.1lf %s\n",x.id,x.name,x.mid,x.fi,x.total,x.qpoint,x.grade);//UI ��ʴ���
}

void Show_All_Data(gradetype st[],int stcount)//�ѧ��ѹ��ʴ������Ţͧ�ء��
{
    int i;
    for(i=0;i<stcount;i++)
    {
        printf("%d)",i+1);
        print_data(st[i]);
    }
}

void Sort_by_id(gradetype st[],int stcount)//�ѧ��ѹ���§������ʻ�Ш�ǵ��(id)����--->�ҡ
{
    int i,j;
    gradetype x;
    for(i=0;i<stcount;i++)
    {
        for(j=i+1;j<stcount;j++)
        {
            if(st[j].id<st[i].id)
            {
                x=st[i];
                st[i]=st[j];
                st[j]=x;
            }
        }
    }
}

void Sort_by_total(gradetype st[],int stcount)//�ѧ��ѹ���§������๹(score)�ҡ--->����
{
    int i,j;
    gradetype x;
    for(i=0;i<stcount-1;i++)
    {
        for(j=i+1;j<stcount;j++)
        {
            if(st[j].total>st[i].total)
            {
                x=st[i];
                st[i]=st[j];
                st[j]=x;
            }
        }
    }
}

void Search_Score(gradetype st[],int stcount)//�ѧ��ѹ����������ʴ��Ť��������๹�����ҧ min �֧ max
{
   double min,max;
   int i,count;
   char ch;
   do
   {
       printf("\nEnter Range of min score and max score");
       scanf("%lf %lf",&min,&max);
       count=0;
       for(i=0;i<stcount;i++)
       {
           if(st[i].total>=min&&st[i].total<=max)
           {
               count=count+1;
               printf("%d",count);
               print_data(st[i]);
           }
       }printf("\n\n Do you want to search again ? ");
        ch = getchar();
   }while (ch == 'y');
}

void Search_Grade(gradetype st[],int stcount)//�ѧ��ѹ����������ʴ��Ť�������ô�������͹
{
    char key[3];
    int i,count;
    do
    {
        printf("\nSearch Grade (A,B+,B,C+,C,F or 0=Exif");
        scanf("%2s",key);
        count=0;
        if(strcmp(key,"0")!=0)
        {
            for(i=0;i<stcount;i++)
            {
               if(strcmp(st[i].grade,key)==0)
               {
                count=count+1;
                printf("%2d",count);
                print_data(st[i]);
               }
            }
        }
    }
    while(strcmp(key,"0")!=0);
}

void Search_Name(gradetype st[],int stcount)//����������ʴ��Ť�����ʹ���ͧ�Ѻ���������
{
    char key[16];
    int i,count;
    do
    {
        printf("\nEnter Search key(0=Exit)");
        scanf("%15s",key);
        count=0;
        if(strcmp(key,"0")!=0)
        {
            for(i=0;i<stcount;i++)
            {
                if(strstr(st[i].name,key)!=NULL)
                {
                    count=count+1;
                    printf("%d",count);
                    print_data(st[i]);
                }
            }
        }
    }
    while(strcmp(key,"0")!=0);
}

int cmpname(const void *a,const void *b)
{
    char x[40],y[40];
    int i;
    strcpy(x,((gradetype *)a)->name);
    strcpy(y,((gradetype *)a)->name);
    i=strcmp(x,y);
    return i;
}

void Sort_by_name(gradetype st[],int stcount)//�ѧ��ѹ���§�ӴѺ�������(name)�ҡ-->����
{
    qsort(st,stcount,sizeof(gradetype),cmpname);
}

void Grade_setting(gradetype st[],int stcount,double *a,double *bp,double *b,double *cp,double *c,double *dp,double *d)
{
    int i;
    for(i=0;i<stcount;i++)
    {
        if(st[i].total>=*a)
        {
            strcpy(st[i].grade,"A");
            st[i].qpoint=4.0;
            acount++;
        }
        else if(st[i].total>=*bp)
        {
            strcpy(st[i].grade,"B+");
            st[i].qpoint=3.5;
            bpcount++;
        }
        else if(st[i].total>=*b)
        {
            strcpy(st[i].grade,"B");
            st[i].qpoint=3;
            bcount++;
        }
        else if(st[i].total>=*cp)
        {
            strcpy(st[i].grade,"C+");
            st[i].qpoint=2.5;
            cpcount++;
        }
        else if(st[i].total>=*c)
        {
            strcpy(st[i].grade,"C");
            st[i].qpoint=2;
            ccount++;
        }
        else if(st[i].total>=*dp)
        {
            strcpy(st[i].grade,"D+");
            st[i].qpoint=1.5;
            dpcount++;
        }
        else if(st[i].total>=*d)
        {
            strcpy(st[i].grade,"D");
            st[i].qpoint=1;
            dcount++;
        }
        else
        {
            strcpy(st[i].grade,"F");
            st[i].qpoint=0;
            fcount++;
        }
    }
}



void Find_Statistic(gradetype st[],int stcount,double *min,double *max,double *mean,double *sd,
                                   double *minmid,double *maxmid,double *meanmid,double *sdmid,
                                   double *minfi,double *maxfi,double *meanfi,double *sdfi,
                                   double *minatten,double *maxatten,double *meanatten,double *sdatten)
{
    int i;
    double sum=0,sumsqr=0,summid=0,sumsqrmid=0,sumfi=0,sumsqrfi=0,sumatten=0,sumsqratten=0;
    *min=*max=st[0].total;
    *minmid=*maxmid=st[0].mid;
    *minfi=*maxfi=st[0].fi;
    *minatten=*maxatten=st[0].atten;
    for(i=0;i<stcount;i++)
    {
        if(st[i].total<*min)
        {
          *min=st[i].total;
        }
        if(st[i].total>*max)
        {
          *max=st[i].total;
        }
        if(st[i].mid<*minmid)
        {
          *minmid=st[i].mid;
        }
        if(st[i].mid>*maxmid)
        {
          *maxmid=st[i].mid;
        }
        if(st[i].fi<*minfi)
        {
          *minfi=st[i].fi;
        }
        if(st[i].fi>*maxfi)
        {
          *maxfi=st[i].fi;
        }
        if(st[i].atten<*minatten)
        {
          *minatten=st[i].atten;
        }
        if(st[i].atten>*maxatten)
        {
          *maxatten=st[i].atten;
        }
        sum=sum+st[i].total;
        sumsqr=sumsqr+pow(st[i].total,2);
        summid=summid+st[i].mid;
        sumsqrmid=sumsqrmid+pow(st[i].mid,2);
        sumfi=sumfi+st[i].fi;
        sumsqrfi=sumsqrfi+pow(st[i].fi,2);
        sumatten=sumatten+st[i].atten;
        sumsqratten=sumsqratten+pow(st[i].atten,2);
    }
    *mean=sum/stcount;
    *sd=sqrt(sumsqr/stcount-pow(*mean,2));
    *meanmid=summid/stcount;
    *sdmid=sqrt(sumsqrmid/stcount-pow(*meanmid,2));
    *meanfi=sumfi/stcount;
    *sdfi = sqrt(sumsqrfi/stcount - pow(*meanfi,2));
    *meanatten= sumatten/stcount;
    *sdatten = sqrt(sumsqratten/stcount - pow(*meanatten,2));
}

void Show_Stat(gradetype st[],int stcount)
{
    int i;
    double gpa=0;
    Find_Statistic(st,stcount,&min,&max,&mean,&sd,&minmid,&maxmid,&meanmid,&sdmid,&minfi,&maxfi,&meanfi,&sdfi,&minatten,&maxatten,&meanatten,&sdatten);
    for(i=0;i<stcount;i++)
    {
        gpa=gpa+st[i].qpoint;
    }
    gpa=gpa/stcount;
    printf("\n**************************************************************\n");
    printf("*   Score   *    mid    *    final   *    atten   *    total   *\n");
    printf("****************************************************************\n");
    printf("*   min     *   %6.2lf  *   %6.2lf   *   %6.2lf   *   %6.2lf   *\n", minmid,minfi,minatten,min);
    printf("*   max     *   %6.2lf  *   %6.2lf   *   %6.2lf   *   %6.2lf   *\n", maxmid,maxfi,maxatten,max);
    printf("*   mean    *   %6.2lf  *   %6.2lf   *   %6.2lf   *   %6.2lf   *\n", meanmid,meanfi,meanatten,mean);
    printf("*   sd      *   %6.2lf  *   %6.2lf   *   %6.2lf   *   %6.2lf   *\n", sdmid,sdfi,sdatten,sd);
    printf("****************************************************************\n");
    printf("\n");
    printf("****************************************************************\n");
    printf("*   score   *   A *  B+ *   B *  C+ *   C *  D+ *  D  *  F  *\n");
    printf("*   count   *  %2d *  %2d *  %2d *  %2d *  %2d *  %2d *  %1d  *  %2d *\n", acount, bpcount, bcount, cpcount, ccount, dpcount, dcount, fcount);
    printf("****************************************************************\n");
    printf("\nGPA : %.2lf\n", gpa);

}

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
 printf("\n###################################################\n");//UI
 printf("##                    Manu Test                  ##\n");//UI
 printf("###################################################\n");//UI
 printf("##       1.Enter file name                       ##\n");//UI
 printf("##       2.Enter criterion of each grade         ##\n");//UI
 printf("##       3.Calculate and show of each grade      ##\n");//UI
 printf("##       4.Show all data                         ##\n");//UI
 printf("##       5.Show data desscending sort by total   ##\n");//UI
 printf("##       6.Show data ascending sort by ID        ##\n");//UI
 printf("##       7.Search score (min-max)                ##\n");//UI
 printf("##       8.Search grade                          ##\n");//UI
 printf("##       9.Search key name                       ##\n");//UI
 printf("##       0.Exit                                  ##\n");//UI
 printf("###################################################\n");//UI
 printf("Enter your number(0-9) :");//��ʴ������������Ţ 0-5 �������͡����
 select=get_int(0,9);//��˹���� selest=get_int �¤�ҵ���ش�������� ��� 1 ���� ����٧�ش�������� ��� 5
 return select;//�纤�� select
}

int main()
{
    gradetype st[100];
    int stcount,i;
    int select,count=0;
    double a,bp,b,cp,c,dp,d;
    char filename[100];
    double A,Bp,B,Cp,C,Dp,D;
    double sum_gpa;
    double min,max,mean,sd,minmid,maxmid,meanmid,sdmid,minfi,maxfi,meanfi,sdfi,minatten,maxatten,meanatten,sdatten;
    do
    {
        select=get_manu();
        if(select==1)
        {
            system("cls");
            Load_Student_File("SCORE.CSV",st,&stcount);
            /*if(stcount==0)
            {
                printf("Reading file error\n");
            }
            else
            {
                printf("Reading file complete\n");
                printf("TOTAL : %d \n",stcount);
                count=1;
            }*/
            printf("\nPress any key to menu");
            getch();
        }
        else if(select==2&&stcount>0)
        {
            system("cls");
            printf("Enter grade : \n");
            scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf",&a,&bp,&b,&cp,&c,&dp,&d);
            Grade_setting(st,stcount,&a,&bp,&b,&cp,&c,&dp,&d);
            Show_Stat(st,stcount);
            printf("\nPress any key to menu");
            getch();
        }
        else if(select==3&&stcount>0)
        {
            Show_Stat(st,stcount);
            printf("\nPress any key to menu");
            getch();
        }
        else if(select==4&&stcount>0)
        {
            Show_All_Data(st,stcount);
            printf("\nPress any key to menu");
            getch();
        }
        else if(select==5&&stcount>0)
        {
            Sort_by_total(st,stcount);
            Show_All_Data(st,stcount);
            printf("\nPress any key to menu");
            getch();
        }
        else if(select==6&&stcount>0)
        {
            Sort_by_id(st,stcount);
            Show_All_Data(st,stcount);
            printf("\nPress any key to menu");
            getch();
        }
        else if(select==7&&stcount>0)
        {
            Search_Score(st,stcount);
            printf("\nPress any key to menu");
            getch();
        }
        else if(select==8&&stcount>0)
        {
            Search_Grade(st,stcount);
            printf("\nPress any key to menu");
            getch();
        }
        else if(select==9&&stcount>0)
        {
            Search_Name(st,stcount);
			Sort_by_name(st,stcount);
            printf("\nPress any key to menu");
            getch();
        }

    }
    while(select!=0);
    printf("\nEND PROGRAM\n");
    return 0;
}
