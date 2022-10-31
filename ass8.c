#include<stdio.h>
#include<math.h>

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

int get_menu()//ฟังก์ชันเมนู
{
 int select;//กำหนดตัวเเปร select เพื่อเรียกใช้ฟังก์ชัน get_int(int min,int max)
 printf("###########################################\n");//UI
 printf("#                Menu Test                #\n");//UI
 printf("###########################################\n");//UI
 printf("#            1.Test_Function 1            #\n");//UI
 printf("#            2.Test_Function 2            #\n");//UI
 printf("#            3.Test_Function 3            #\n");//UI
 printf("#            0.Exit                       #\n");//UI
 printf("###########################################\n");//UI
 printf("Enter your number :");//เเสดงผลให้ใส่ตัวเลข 0-3 เพื่อเลือกเมนู
 select=get_int(0,3);//กำหนดให้ select=get_int โดยค่าต่ำสุดที่ใส่ได้ คือ 1 เเละ ค่าสูงสุดที่ใส่ได้ คือ 3
 return select;//เก็บค่า select
}

void Add_data(double data[],int *count)//ฟังก์ชันเพิ่มตัวเลข
{
 int i=0;//ประกาศตัวเเปร i สำหรับการตรวจสอบการรับค่า
 double a;//ประกาศตัวเเปร a สำหรับรับค่าเลข
 char ch;//ประกาศตัวเเปร ch สำหรับรับตัวอักษร
 printf("Enter number of data : ");//บอกผู้ใช้ให้ใส่เลขที่จะมีอยู่ใน data
 do {
     i=scanf("%lf%c",&a,&ch);//ให้ i เป็นจำนวนชนิดของการรับค่า
    if(i>0&&a>0)//ถ้าชนิดของค่าตัวเลขที่รับมากกว่า 0 เเละ เป็นจำนวนเต็มบวก เข้าเงื่อนไข if
     {
      data[*count]=a;//ให้ data[*count]เป็น a
      *count=*count+1;//ให้ *count เพิ่มค่าทีละ 1
     }
    }while(i!=0&&ch!='\n');//รับค่าผิดประเภท
     rewind(stdin);//clear ค่าที่รับผิดประเภท
 }

 void Print_data(double data[],int count)//ฟังก์ชันเเสดงผลตัวเลขที่อยู่ใน data
 {
   int i;//ประกาศตัวเเปร i สำหรับ loop for
   for(i=0;i<count;i++)//วนลูปตั้งเเต่รอบที่ 0-count เพิ่มทีละ 1
   {
    printf("data[%d]=%lf\n",i,data[i]);//เเสดงค่า
   }
   printf("****************************\n");//UI
 }

 void Delete_data(double data[],int *count,int id)//ฟังก์ชันลบตัวเลข
 {
   int i;//ประกาศตัวเเปร i สำหรับ loop for
   for(i=id;i<*count-1;i++)//วนลูปตั้งเเต่รอบที่ 0-count เพิ่มทีละ 1
   {
    data[i]=data[i+1];//เลื่อนค่าตัวถัดมา เพื่อลบค่าที่ต้องการ
   }
   *count=*count-1;//ลดจำนวนตัวเลขที่ต้องการลบ
 }

 void Calculate_data(double data[],int count,double *mean,double *sd,double *min,double *max)//ฟังก์ชันคำนวณหา ค่าเฉลี่ย,ส่วนเบี่ยงเบนมาตรฐาน,ค่าต่ำสุด,ค่าสูงสุด
 {
   int i;//ประกาศตัวเเปร i สำหรับ loop for
   double sum,sum2;//ประกาศตัวเเปร sum สำหรับเก็บค่าผลรวม, , sum2 สำหรับเก็บค่าผลรวมกำลังสอง
   *min=data[0];//เลขตัวเเรก
   for(i=0,sum=0,sum2=0;i<count;i++)//วนลูปตั้งเเต่รอบที่ 0-count เพิ่มทีละ 1
   {
     sum=sum+data[i];//sum เก็บผลบวกของเลขทั้งหมด
     sum2=sum2+data[i]*data[i];//sum2 เก็บผลบวกกำสองของตัวเลขทั้งหมด
     if(data[i]<*min)//ถ้า data มีค่าน้อยกว่า min
     {
      *min=data[i];//ให้ data เป็น min เเทน
     }
     if(data[i]>*min)//ถ้า data มีค่ามากกว่า min
     {
      *max=data[i];//ให้ data เป็น max เเทน
     }
   }
   *mean=sum/count;//สูตรคำนวณหาค่าเฉลี่ย
   *sd=sqrt(sum2/count-*mean**mean);//สูตรคำนวณหาค่าส่วนเบี่ยงเบนมาตรฐาน
 }

 int main()
 {
  double data[200],del=0,mean,sd,min,max;//ประกาศตัวเเปร Array data[100] สำหรับรับค่าตัวเลข ,mean สำหรับค่าเฉลี่ย ,sd สำหรับส่วนเบี่ยงเบนมาตรฐาน  ,  min สำหรับค่าต่ำสุด , max สำหรับค่าสูงสุด , del สำหรับตัวเลขที่ต้องการลบ
  int count=0,select=0,i;//ประกาศ count สำหรับเก็บจำนวนตัวเลขใน data , select สำหรับค่าใช้ในฟังก์ชัน get_manu()
  char ch;//ประกาศ ch สำหรับตัวอักษร
  do
  {
   select=get_menu();//เรียกใช้ฟังก์ชัน get_manu()
   if(select==1)//เลือกเมนู 1 เมนูเพิ่มตัวเลข
   {
    Add_data(data, &count);//เรียกใช้ฟังก์ชันเพิ่มตัวเลข
    if(count>=1)//จำนวนตัวเลขที่รับมีค่ามากกว่าเท่ากับ 1 เข้าเงื่อนไขใน if
    {
     Print_data(data, count);//เรียกใช้ฟังก์ชันเเสดงผลตัวเลขที่อยู่ใน data
    }
    else//ไม่มีตัวเลข เข้าเงื่อไข else
    {
     printf("ERROR INPUT WRONG TYPE\n");//ตัวเลขที่ป้อนผิดเงื่อนไข
    }
    printf("Press any key to exit\n");//บอกผู้ใช้ว่ากดปุ่มใดก็ได้เพื่อไปหน้าเมนูหลัก
    getchar();//กดปุ่มใดก็ได้เพื่อทำงานต่อ
   }

   else if(select==2&&count!=0)//เลือกเมนู 2 เมนูลบตัวเลข
   {
    Print_data(data, count);//เรียกใช้ฟังก์ชันเเสดงผลตัวเลขที่อยู่ใน data
    printf("Input number you want to delete : \n");//บอกผู้ใช้ให้ป้อนตัวเลขที่อยากลบ
    scanf("%lf",&del);//เก็บค่า del มาคิดในระบบ
    for(i=0;i<count;i++)//วน loop for ตั้งเเต่รอบที่ 0-count
    {
     if(data[i]==del)//ถ้า dal=data[i] เข้าเงื่อนไขใน if
     {
      printf("Delete Sure? If you sure press y/Y\n");//ถามผู้ใช้ว่าลบเเน่ใช่หรือไม่
      scanf(" %c",&ch);//รับค่าตัวอักษร
      if(ch=='y'||ch=='Y')//ถ้าตัวอักษรที่รับมาเป็น y/Y เข้าเงื่อนไข if
      {
       Delete_data(data, &count,i);//เรียกใช้ฟังก์ชันลบตัวเลข
      }
      else//กดปุ่มอื่น
        {printf("Cancle Delete Number\n");}//บอกผู้ใช้ว่ายกเลิกการลบตัวเลข
      if(count==0)//ไม่มีตัวเลข เข้าเงื่อนไข if
      {
       printf("Not have any number in data\n");//บอกผู้ในว่าไม่มีตัวเลขใน data
      }
      else{Print_data(data, count);}//เรียกใช้ฟังก์ชันเเสดงผลตัวเลขที่อยู่ใน data
     }
    }
    printf("Press any key to exit\n");//บอกผู้ใช้ว่ากดปุ่มใดก็ได้เพื่อไปหน้าเมนูหลัก
    getchar();//กดปุ่มใดก็ได้เพื่อทำงานต่อ
   }

   else if(select==3&&count!=0)//เลือกเมนู 3 เมนูคำนวณหาค่าเฉลี่ย ส่วนเบี่ยงเบนมาตรฐาน
   {
    Print_data(data, count);//เรียกใช้ฟังก์ชันเเสดงผลตัวเลขที่อยู่ใน data
    if(count>1)//จำนวนตัวเลขที่รับมีค่ามากกว่า 1 เข้าเงื่อนไข if
    {
     Calculate_data(data, count, &mean, &sd, &min, &max);//เรียกใช้ฟังก์ชันคำนวณหา ค่าเฉลี่ย,ส่วนเบี่ยงเบนมาตรฐาน,ค่าต่ำสุด,ค่าสูงสุด
     printf("Mean= %g,SD= %g,Min= %g,Max= %g\n",mean,sd,min,max);//เเสดงผล
    }
    else//จำนวนตัวเลขที่มีอยู่น้อยกว่าเท่ากับ 1
    {
     printf("Error can not calculate\nShould input number more than 2 numbers\n");//บอกผู้ใช้ว่าไม่สามารถคำนวณได้ ต้องมีตัวเลขมากกว่า 2 จำนวน
    }
    printf("Press any key to exit\n");//บอกผู้ใช้ว่ากดปุ่มใดก็ได้เพื่อไปหน้าเมนูหลัก
    getchar();//กดปุ่มใดก็ได้เพื่อทำงานต่อ
   }

   else if(count==0&&select!=0)//ไม่มีข้อมูล
   {
    printf("Not have number in data\n");//บอกผู้ใช้ว่าไม่มีข้อมูล
    printf("Press any key to menu\n");//บอกผู้ใช้ว่ากดปุ่มใดก็ได้เพื่อไปหน้าเมนูหลัก
    getchar();//กดปุ่มใดก็ได้เพื่อทำงานต่อ
   }

  } while(select!=0);
  printf("End Program\n");//select=0
  return 0;
 }

