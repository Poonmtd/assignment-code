#include <stdio.h>
int get_int(int min,int max)//ฟังก์ชันป้องกันการใส่ข้อมูลผิดพลาด
{
 int ans;//กำหนดตัวเเปร ans รับค่าตัวเลข
 char ch;//กำหนดตัวเเปร ch ตรวจสอบว่าเป็น enter
 while((scanf("%d%c",&ans,&ch)!=1 && ch!='\n')||ans<min||ans>max)//ตรวจสอบค่าที่รับว่าประเภททค่าที่รับมาหากไม่เท่ากับ 1 เเละ ตัวอักษรไม่ใช่่ enter จะถูกเก็บค่าไว้ไม่นำไปใช้
 {
  rewind(stdin);//คำสั่งเก็บค่าที่ป้อนไม่ตรงตามมเงื่อนไข
  printf("Error input again.");//เเสดงผลให้ใส่ค่าใหม่อีกครั้ง
 }
 return ans;//เก็บค่า ans
}

int get_manu()//ฟังก์ชันเมนู
{
 int select;//กำหนดตัวเเปร select เพื่อเรียกใช้ฟังก์ชัน get_int(int min,int max)
 printf("###########################################\n");//UI
 printf("#                Manu Test                #\n");//UI
 printf("###########################################\n");//UI
 printf("#            1.Test_Function 1            #\n");//UI
 printf("#            2.Test_Function 2            #\n");//UI
 printf("#            3.Test_Function 3            #\n");//UI
 printf("#            4.Test_Function 4            #\n");//UI
 printf("#            5.Test_Function 5            #\n");//UI
 printf("###########################################\n");//UI
 printf("Enter your number :");//เเสดงผลให้ใส่ตัวเลข 0-5 เพื่อเลือกเมนู
 select=get_int(0,5);//กำหนดให้ selest=get_int โดยค่าต่ำสุดที่ใส่ได้ คือ 1 เเละ ค่าสูงสุดที่ใส่ได้ คือ 5
 return select;//เก็บค่า select
}

double sigma1(int n)//ฟังก์ชันอนุกรมเลข ( เศษ )test#1
{
 int i;//กำหนดตัวเเปร i รับค่าเป็นจำนวนเต็ม สำหรับ loop for
 double ans;//กำหนดตัวเเปร ans เพื่อเก็บผลบวกของอนุกรมเลข
 for(i=1,ans=0;i<=n;i++)//ans เริ่มต้น=0 เพราะสมบัติการบวก หาก iน้อยกว่าเท่ากับ n ให้ทำเงื่อนไขใน loop ไปเรื่อยๆ
 {
  ans=ans+2*i;//ให้ ans เก็บผลบวกอนุกรมเลข 2i ในเเต่ละรอบ
 }
 return ans;//เก็บค่า ans
}

double sigma2(int n)//ฟังก์ชันอนุกรมเลข ( ส่วน ) test#1
{
 int i;//กำหนดตัวเเปร i รับค่าเป็นจำนวนเต็ม สำหรับ loop for
 double ans;//กำหนดตัวเเปร ans เพื่อเก็บผลบวกของอนุกรมเลข
 for(i=1,ans=1;i<=n;i++)//ans เริ่มต้น=1 เพราะสมบัติการคูณ หาก iน้อยกว่าเท่ากับ n ให้ทำเงื่อนไขใน loop ไปเรื่อยๆ
 {
  ans=ans*i;//ให้ ans เก็บผลบวกอนุกรมเลข i ในเเต่ละรอบ
 }
 return ans;//เก็บค่า ans
}

void Test_Function1(int n,double termR[],double dataR[],int *count)//ฟังก์ชัน test#1
{
 double term1,data1=0;//กำหนดตัวเเปร term1 เก็บค่าsigma1(i)/sigma2(i) เเละ  data1 เก็บผลรวมในเเต่ละรอบ
 int i;//กำหนดตัวเเปร i สำหรับ loop for
 for(i=1;i<=n;i++)//หาก i น้อยกว่าเท่ากับ n ให้คำนวณใน loop ไปเรื่อยๆ
 {
  term1=sigma1(i)/sigma2(i);//กำหนดให้ term1=sigma1(i)/sigma2(i)
  data1=term1+data1;//กำหนดให้ data1=term1+data1 เก็บผลรวมในเเต่ละรอบ
  termR[i]=term1;//เก็บค่า tern1 ใน  array termR[]
  dataR[i]=data1;//เก็บค่า data1 ใน array dataR[]
  *count=i;//กำหนด pointer count=i
 }
}

void printTest_Function1(double termR[],double dataR[],int count)//ฟังก์ชันเเสดงผลทางหน้าของฟังก์ชัน test#1
{
 printf("Test Function #1\n");//UI
 printf("*************************************\n");//UI
 printf("*  i   *      fi      *     sum     *\n");//UI
 printf("*************************************\n");//UI
 for(int i=1;i<=count;i++)//ทำการเเสดงค่าตั้งเเต่รอบ 1-count
 {
  printf("* %2d   *%10.6lf    * %10.6lf  *\n",i,termR[i],dataR[i]);//เเสดงค่า i,termR[i],dataR[i]
 }
 printf("*************************************\n");//UI
 printf("ans = %lf\n",dataR[count]);//แสดงผลคำตอบ
}

int get_Fibo(int n)//ฟังก์ชันฟิโบนักชี
{
 int fi=0,fc=1,ft=0,i;//กำหนดตัวเเปร i เป็นตัวเเรก  เเละ fc เป็นตัวที่ 2 ของเลขฟิโบนักชี
  for(i=2;i<=n;i++)//คำนวณตั้งเเต่รอบ 2-n
      {
       fi=fc+ft;//f(n)=f(n-2)+f(n-1)
       ft=fc;//f(n-2)=f(n-1) เลื่อนค่า
       fc=fi;//f(n-1)=f(n) เลื่อนค่า
      }
 return fi;//เก็บค่า fi
}

void Test_Function2(int n,int termI[],int dataI[],int *count)//ฟังก์ชัน test#2
{
 int i,data2;//กำหนดตัวเเปร  i สำหรับ loop for เเละ  data2 เก็บผลรวมในเเต่ละรอบ
 for(i=2,*count=0;*count<n;i++)//คำนวณตั้งเเต่รอบ 2-n นับรอบเมื่อเข้าเงื่อนไขใน if
 {
  data2=get_Fibo(i);//กำหนดให้ data2=gat_Fibo(i)
  if(data2%2==0)//ถ้า data2 หาร 2 ลงตัว จะเป็นเลขคู่ ของฟิโบนักชี
  {
   *count=*count+1;//กำหนดให้ count+1
   termI[*count]=i;//เก็บค่า i ใน  Array termI[*count]
   dataI[*count]=data2;//เก็บค่า data2 ใน  Array dataI[*count]
  }
 }
}

void printTest_Function2(int termI[],int dataI[],int count)//ฟังก์ชันเเสดงผลทางหน้าของฟังก์ชัน test#2
{
 printf("\nTest Function #2\n");//UI
 printf("***********************************\n");//UI
 printf("* count *    i    *     fi    *\n");//UI
 printf("***********************************\n");//UI
 for(int i=1;i<=count;i++)//ทำการเเสดงค่าตั้งเเต่รอบ 1-count
 {
  printf("*  %2d   *   %2d    *  %7d      *\n",i,termI[i],dataI[i]);//เเสดงค่า i,termI[i],dataI[i]
 }
 printf("***********************************\n");//UI
 printf("count = %d, ans = %d\n",count,dataI[count]);//เเสดงผลคำตอบ
}

int get_Prime(int n)//ฟังก์ชันจำนวนเฉพาะ
{
 int i,check=1;//กำหนดตัวเเปร i สำหรับ loop for เเละตัวเเปร check เพื่อเก็บค่า 0,1
 for(i=2;i<n;i++)//คำนวณตั้งเเต่รอบ 2-n
 {
  if(n%i==0)//ถ้า n หาร i ลงตัวจะเข้าเงื่อนไขใน if
  {
   check=0;//ให้ check=0
  }
 }return check;//เก็บค่า ckeck
}

void Test_Function3(int min,int max,int termI[],int dataI[],int *count)//ฟังก์ชัน test#3
{
 int i,n,sum;//กำหนดตัวเเปร i สำหรับ loop for,n สำหรับเก็บค่าของฟังก์ชัน Prime,sum สำหรับเก็บค่าผลรวม
 for(i=min+1,*count=0,sum=0;i<max;i++)//ให้ i คือ ค่าที่้น้อยที่สุด(min) ให้ min เพิ่มค่าทีละ 1 จนถึงค่าที่มากที่สุด(max)
 {
  n = get_Prime(i);//ให้ n เก็บค่าขแงฟังก์ชัน Prime ถ้าเป็นจำนวนเฉพาะ n=1 ถ้าไม่ n=0
  if(n==1)//ถ้าเป็นจำนวนเฉพาะจะเข้าเงื่อนไขใน if
  {
   *count=*count+1;//กำหนดให้ count+1
   termI[*count]=i;//เก็บค่า i ใน  Array termI[*count]
   sum=sum+termI[*count];//sum เก็บค่าผลรวมของ  termI[*count]
   dataI[*count]=sum;//เก็บค่า sum ใน Array dataI[*count]
  }
 }
}

void printTest_Function3(int termI[],int dataI[],int count)//ฟังก์ชันเเสดงผลทางหน้าของฟังก์ชัน test#3
{
 printf("\nTest Function #3\n");//UI
 printf("********************************\n");//UI
 printf("*  no  *    i     *     sum    *\n");//UI
 printf("********************************\n");//UI
 for(int i=1;i<=count;i++)//ทำการเเสดงค่าตั้งเเต่รอบ 1-count
 {
  printf("* %2d   *   %2d     *   %3d      *\n",i,termI[i],dataI[i]);//เเสดงค่า i,termI[i],dataI[i]
 }
 printf("********************************\n");//UI
 printf("count = %d, sum = %d\n",count,dataI[count]);//เเสดงผลคำตอบ
}

void Test_Function4(int max,int termI[],int dataI[],int *count)//ฟังก์ชัน test#4
{
 int i=1,j=40,sum=0;//กำหนดตัวเเปร sum สำหรับเก็บผลรวม,i สำหรับ loop while,j เเละ i เป็นพจน์เเรก
 *count=0;//เริ่มรอบที่ 0
 sum=i*j;//กำหนดให้ sum=i*j
 while(sum<max&&i<40&&j>1)//ถ้า sum น้อยกว่า max เเละ i น้อยกว่า 40 เเละ j มากกว่า 1 ให้ทำเงื่อนไขใน while
 {
  *count=*count+1;//กำหนดให้ count+1
  termI[*count]=i*j;//เก็บค่า i*j ใน Array termI[*count]
  dataI[*count]=sum;//เก็บค่า sum ใน Array dataI[*count]
  i=i+2;//i เพิ่มขึ้นทีละ 2 ในเเต่ละรอบ
  j=j-2;//j ลดลงทีละ 2 ในเเต่ละรอบ
  sum=sum+(i*j);//sum เพิ่มขึ้นทีละ i*j ในเเต่ละรอบ
 }
}

void printTest_Function4(int termI[],int dataI[],int count)//ฟังก์ชันเเสดงผลทางหน้าของฟังก์ชัน test#4
{
 printf("\nTest Function #4\n");//UI
 printf("********************************\n");//UI
 printf("*   i  *    fi     *     sum   *\n");
 printf("********************************\n");//UI
 for(int i=1;i<=count;i++)//ทำการเเสดงค่าตั้งเเต่รอบ 1-count
 {
  printf("*  %2d  *   %3d     *     %4d  *\n",i,termI[i],dataI[i]);//เเสดงค่า i,termI[i],dataI[i]
 }
 printf("********************************\n");//UI
 printf("n = %d, ans = %d\n",count,dataI[count]);//เเสดงผลคำตอบ
}

void Test_Function5(int n,int dataI[],int *count)//ฟังก์ชัน test#5
{
 int i,ans,check;//กำหนดตัวเเปร i สำหรับ loop for,ans สำหรับเก็บค่า a พจน์ที่ n,check สำหรับตรวจสอบพจน์ที่ต้องการ
 *count=0;//เริ่มรอบที่ 0
 for(i=1;*count<n;i++)//คำนวณตั้งเเต่รอบที่ 1-n
 {
  ans=1+((i-1)*3);//an ตามที่โจทย์กำหนดให้
  check=ans%5;//ตรวจสอบพจน์ที่ต้องการหารด้วย 5 เหลือเศษเท่าไหร่
  if(check==1)//ถ้าเศษจากการหาร=1 ทำเงื่อนไขใน if
  {
   *count=*count+1;//กำหนดให้ count+1
   dataI[*count]=ans;//เก็บค่า sum ใน Array dataI[*count]
  }
 }
}

void printTest_Function5(int dataI[],int count)//ฟังก์ชันเเสดงผลทางหน้าของฟังก์ชัน test#5
{
 printf("\nTest Function #5\n");//UI
 printf("*******************\n");//UI
 printf("*  no  *   term   *\n");//UI
 printf("*******************\n");//UI
 for(int i=1;i<=count;i++)//ทำการเเสดงค่าตั้งเเต่รอบ 1-count
 {
  printf("* %2d   *    %3d   *\n",i,dataI[i]);//เเสดงค่า i,dataI[i]
 }
 printf("*******************\n");//UI
 printf("count = %d\n",count);//เเสดงผลคำตอบ
}


int main()//ฟังก์ชันหลัก
{
 double termR[20],dataR[20];//กำหนด Array ที่เป็น double(ทศนิยม) เพื่อเก็บผมรวมเเละรอบ
 int termI[20],dataI[20];//กำหนด Array ที่เป็น int(จำนวนเต็ม) เพื่อเก็บผลรวมเเละรอบ
 int count,select,n=0,max=0,min=0;//กำหนดตัวเเปร  count มารับ *count,select มารับ get_manu(),n,max min มารับค่าที่ป้อน
 char ch;//กำหนด ch มารับ ข้อมูลที่เป็นตัวหนังสือ
 do
 {
  select=get_manu();//select รับค่า get_manu()ที่ป้อน
   if(select==1)//select=1
   {do
    {
     printf("FUNCTION_1\n");//UI
     printf("Enter number:");//UI
     n=get_int(1,10);//รับค่าได้ตั้งเเเต่ 1-10
   	 Test_Function1(n,termR,dataR,&count);//เรียกใช้ฟังก์ชัน test#1
   	 printTest_Function1(termR,dataR,count);//เรียกใช้ฟังก์ชันเเสดงผลทางหน้าของฟังก์ชัน test#1
        {
         printf("\nEnter y to run again or to n exit.\n");//หาก กด y/Y โปรเเกรมจะรันใหม่อีกครั้ง ,กด n/N ออกจากโปรเเกรม
         scanf(" %c",&ch);//รับตัวอักษร
        }
        while(ch!='y' && ch!='Y' && ch!='n' && ch!='N');//หากกดตัวอักษรที่ไม่ใช่ y,Y,n,N ให้โปรเเกรมถามใหม่อีกครั้ง
       }
       while(ch=='y');//โปรเเกรมรันใหม่อีกครั้ง
   }
   else if(select==2)//select=2
   {do
    {
     printf("FUNCTION_2\n");//UI
     printf("Enter  number:");//UI
     n = get_int(1,10);//รับค่าได้ตั้งเเเต่ 1-10
   	 Test_Function2(n,termI,dataI,&count);//เรียกใช้ฟังก์ชัน test#2
   	 printTest_Function2(termI,dataI,count);//เรียกใช้ฟังก์ชันเเสดงผลทางหน้าของฟังก์ชัน test#2
     do
        {
         printf("\nEnter y to run again or to n exit.\n");//หาก กด y/Y โปรเเกรมจะรันใหม่อีกครั้ง ,กด n/N ออกจากโปรเเกรม
         scanf(" %c",&ch);//รับตัวอักษร
        }
        while(ch!='y' && ch!='Y' && ch!='n' && ch!='N');//หากกดตัวอักษรที่ไม่ใช่ y,Y,n,N ให้โปรเเกรมถามใหม่อีกครั้ง
       }
       while(ch=='y');//โปรเเกรมรันใหม่อีกครั้ง
   }
   else if(select==3)//select=3
   {do
    {
     printf("FUNCTION_3\n");//UI
     printf("Enter min number: ");//UI
     min=get_int(1,100);//รับค่าได้ตั้งเเเต่ 1-100
     if(min==1)//ถ้า  min=1 ให้ทำเงื่อนไขใน if
     {
      min=2;//เปลี่ยน  min=2
     }
     printf("Enter max number: ");//UI
     max=get_int(1,100);//รับค่าได้ตั้งเเเต่ 1-100
   	 Test_Function3(min,max,termI,dataI,&count);//เรียกใช้ฟังก์ชัน test#3
   	 printTest_Function3(termI,dataI,count);//เรียกใช้ฟังก์ชันเเสดงผลทางหน้าของฟังก์ชัน test#3
     do
        {
         printf("\nEnter y to run again or to n exit.\n");//หาก กด y/Y โปรเเกรมจะรันใหม่อีกครั้ง ,กด n/N ออกจากโปรเเกรม
         scanf(" %c",&ch);//รับตัวอักษร
        }
        while(ch!='y' && ch!='Y' && ch!='n' && ch!='N');//หากกดตัวอักษรที่ไม่ใช่ y,Y,n,N ให้โปรเเกรมถามใหม่อีกครั้ง
       }
       while(ch=='y');//โปรเเกรมรันใหม่อีกครั้ง
   }
   else if(select==4)//select=4
   {do
    {
     printf("FUNCTION_4\n");//UI
     printf("Input max number:");//UI
     max=get_int(1,5000);//รับค่าได้ตั้งเเเต่ 1-5000
   	 Test_Function4(max,termI,dataI,&count);//เรียกใช้ฟังก์ชัน test#4
   	 printTest_Function4(termI,dataI,count);//เรียกใช้ฟังก์ชันเเสดงผลทางหน้าของฟังก์ชัน test#4
     do
        {
         printf("\nEnter y to run again or to n exit.\n");//หาก กด y/Y โปรเเกรมจะรันใหม่อีกครั้ง ,กด n/N ออกจากโปรเเกรม
         scanf(" %c",&ch);//รับตัวอักษร
        }
        while(ch!='y' && ch!='Y' && ch!='n' && ch!='N');//หากกดตัวอักษรที่ไม่ใช่ y,Y,n,N ให้โปรเเกรมถามใหม่อีกครั้ง
       }
       while(ch=='y');//โปรเเกรมรันใหม่อีกครั้ง
   }
   else if(select==5)//select=5
   {do
    {
     printf("FUNCTION_5\n");//UI
     printf("Enter number:");//UI
     n=get_int(1,15);//รับค่าได้ตั้งเเเต่ 1-15
   	 Test_Function5(n,dataI,&count);//เรียกใช้ฟังก์ชัน test#5
   	 printTest_Function5(dataI,count);//เรียกใช้ฟังก์ชันเเสดงผลทางหน้าของฟังก์ชัน test#5
      do
        {
         printf("\nEnter y to run again or n to exit.\n");//หาก กด y/Y โปรเเกรมจะรันใหม่อีกครั้ง ,กด n/N ออกจากโปรเเกรม
         scanf(" %c",&ch);//รับตัวอักษร
        }
        while(ch!='y' && ch!='Y' && ch!='n' && ch!='N');//หากกดตัวอักษรที่ไม่ใช่ y,Y,n,N ให้โปรเเกรมถามใหม่อีกครั้ง
       }
       while(ch=='y');//โปรเเกรมรันใหม่อีกครั้ง
   }
 } while(select!=0);
}





