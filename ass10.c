#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <time.h>

int comparator(const void *a,const void *b)
{
    return(*(int*)a-*(int*)b);
}

void Load_TXT_File(char *filename,int data1[],int *count1)
{
    FILE *fp;
    *count1=0;
    int a;
    fp=fopen(filename,"r");
    while(fscanf(fp,"%d",&a)==1)
    {
        data1[*count1]=a;
        *count1=*count1+1;
    }
    fclose(fp);
}

void Load_BIN_File(char *filename,int data2[],int *count2)
{
    FILE *fp;
    *count2=0;
    int a;
    fp=fopen(filename,"rb");
    while(!feof(fp))
    {
        if(fread(&a,sizeof(int),1,fp)==1)
        {
            data2[*count2]=a;
            *count2=*count2+1;
        }
    }
    fclose(fp);
}

double solution1(int data1[],int data2[],int count1,int count2)
{
    int count=1;
    double total;
    clock_t start,end;
    start=clock();
    for (int i=0;i<count1;i++)
    {
        for(int j=0;j<count2;j++)
        {
            if(data1[i]==data2[j])
            {
                printf("\nFound[%d]=%d",count,data2[j]);
                count++;
            }
        }
    }
    end=clock();//เวลาหลังเปรียบเทียบเสร็จ
    total=(double)(end-start)/CLOCKS_PER_SEC;//เวลของการเปรียบเทียบวิธีนี้
    return total;//รีเทิร์นเวลาที่วัดได้
}

double solution2(int data1[],int data2[],int count1,int count2)
{
    int count=1;
    double total;
    clock_t start,end;
    start=clock();
    for (int i=0;i<count1;i++)
    {
        if((int*)bsearch(&data1[i],data2,count2,sizeof(int),comparator)!= NULL)
        {
            printf("\nFound[%d]=%d",count,data1[i]);
            count++;
        }
    }
    end=clock();//เวลาหลังเปรียบเทียบเสร็จ
    total=(double)(end-start)/CLOCKS_PER_SEC;//เวลของการเปรียบเทียบวิธีนี้
    return total;//รีเทิร์นเวลาที่วัดได้
}

double solution3(int data1[],int data2[],int count1,int count2)
{
    int count=1,i=0,j=0;
    double total;
    clock_t start,end;
    start=clock();
    while(i<count1&&count2)
    {
        if(data1[i]<data2[j])
        {
            i++;
        }
        else if(data1[i]>data2[j])
        {
            j++;
        }
        else
        {
            printf("\nFound[%d]=%d",count,data2[j]);
            count++;
            i++;
            j++;
        }
    }
    end=clock();//เวลาหลังเปรียบเทียบเสร็จ
    total=(double)(end-start)/CLOCKS_PER_SEC;//เวลของการเปรียบเทียบวิธีนี้
    return total;//รีเทิร์นเวลาที่วัดได้
}

int main()
{
    double time1,time2,time3;
    int data1[100001],data2[100001],count1,count2;
    Load_TXT_File("txt100000.txt",data1,&count1);
    Load_BIN_File("bin100000.bin",data2,&count2);
    printf("\nREAD TEST FILE txt100000.txt &d RECORDD COMPLETE",count1);
    printf("\nREAD TEST FILE bin100000.bin &d RECORDD COMPLETE",count2);

    printf("\nMethod 1 scan direct\n");
    time1=solution1(data1,data2,count1,count2);
    printf("\n\nTime of Method #1=%g second\n\n",time1);

    printf("\nMethod 2 sort only array 2\n");
    qsort(data2,count2,sizeof(int),comparator);
    time2=solution2(data1,data2,count1,count2);
    printf("\n\nTime of Method #2=%g second\n\n",time2);

    printf("\nMethod 3 sort array 1 and array 2\n");
    qsort(data1,count1,sizeof(int),comparator);
    time3=solution3(data1,data2,count1,count2);
    printf("\n\nTime of Method #3=%g second\n\n",time3);
}
