#include <stdio.h>
#include <string.h>
#include <ctype.h>

void Add_space(char *buff)//ฟังก์ชันเพิ่มช่องว่างให้กับเครื่องหมาย
{
    char str[255];//ประกาศ Array str
    int i, j;//ประกาศตัวเเปรสำหรับ loop for
    for (i = 0, j = 0; i < strlen(buff); i++)//วน loop หาความยาวของตัวอักษร
    {
        if (strchr("+-/*^()", buff[i]) != NULL)//ถ้าเป็นเครื่องหมายเเละไม่ได้เว้นช่องว่างในทำเงื่อนไขใน if
        {
            str[j++] = ' ';//เว้นช่องว่าง
            str[j++] = buff[i];//เครื่องหมาย
            str[j++] = ' ';//เว้นช่องว่าง
        }
        else//ถ้าไม่ใช่เครื่องหมายให้เป็นตัวเดิมให้ทำเงื่อนไขใน else
        {
            str[j++] = buff[i];//เป็นตัวเดิม
        }
    }
    strcpy(buff, str);//copy str ไว้ใน buff
}

int check_operator(char *str)//ฟังก์ชันตรวจสอบเครื่องหมาย
{
    if ((strlen(str) == 1) && (strchr("+-*/^()", str[0]) != NULL))//ถ้าความยาวของตัวอักษรเป็น 1 เเละ ตัวอักษรตำเเหน่งที่ 0 เป็น +-*( ) ทำเงื่อนไขใน if
    {
        return 1;//return ค่าเป็น 1
    }
    else//ถ้าไม่เป็นตัวอักษร ทำเงื่อนไขใน else
    {
        return 0;//return ค่าเป็น 0
    }
}

int check_number(char *str, double *n)//ฟังก์ชันตรวจสอบตัวเลข
{
    char ch;//ประกาศตัวอักษร
    if (sscanf(str, "%lf%c", n, &ch) == 1)//อ่านตัวเเปรจาก str ว่าเปลี่ยนเป็น %lf ได้หรือไม่ ถ้าได้ค่าจะเท่ากับ 1 ทำเงื่อนไขใน if
    {
        return 1;//return ค่าเป็น 1
    }
    else//ถ้าไม่สามารถเปลี่ยนเป็น %lf ได้ ทำเงื่อนไขใน else
    {
        return 0;//return ค่าเป็น 0
    }
}

int split(char *buff,char token[][20])//ฟังก์ชันเเบ่งตัวอักษร
{
    char *tok;//ประกาศตัวเเปรตัวอักษร tok เป็น pointer
    int count = 0;//ประกาศ count เป็น 0
    tok = strtok(buff, " ");//ลบ spacebar ใน buff ก่อนเเยก
    while (tok != NULL) //เมื่อเจอช่องว่างของ buff จะออกจาก loop
    {
        strcpy(token[count++], tok);//copy tok ไว้ใน token[count] เเละ เพิ่ม count ทีละ 1
        tok = strtok(NULL, " ");//เเปลง spacebar เป็นช่องว่าง
    }
    return count;//return count
}

int check_function(char *str)//ฟังก์ชันตรวจสอบฟังก์ชัน
{
    char fname[15][10] = {"sin", "cos", "tan", "asin", "acos", "atan", "sqrt", "pow", "log", "exp", "abs"};//ประกาศชื่อฟังก์ชัน
    int fcount = 11, i = 0;//ประกาศให้ fcount เป็น 0 เเละ i เป็น 0
    char buff[20];//ประกาศ Array buff
    strcpy(buff, str);//copy str ไว้ใน str
    strlwr(buff);//เปลี่ยน buff เป็นตัวเล็ก
    while (i < fcount && strcmp(fname[i], buff))//ถ้าค่า i ยังน้อยกว่า fcount เเละ buff ยังไม่เหมือน fname[i]ทำใฟ้ไม่เท่ากับ 0
    {
        i++;//ไล่หาไปเรื่อยๆ จนครบ 11 ตัว
    }
    if (i < fcount)//ถ้า i น้อยกว่า fcount ทำเงื่อนไขใน if
    {
        return 1;// return ค่าเป็น 1
    }
    else//ถ้า i มากกว่าเท่ากับ fcount ทำเงื่อนไขใน else
    {
        return 0;//return ค่าเป็น 0
    }
}

int check_identifier(char *str)//ฟังก์ชันตรวจสอบ identifier
{
    int flag = 1, i;//ประกาศตัวเเปร flag เท่ากับ 1 เเละ ตัวเเปร i สำหรับ loop for
    if ((isalpha(str[0])) || str[0] == '_')//ตรวจสอบว่าตัวเเรกเป็นตัวอักษร A-Z หรือ  _ ทำเงื่อนไขใน if
    {
        for (i = 1; i < strlen(str); i++)//ตรวจสอบตัวที่ 2 ถึง ตัวสุดท้าย
        {
            if (!(isalpha(str[i]) || isdigit(str[i]) || str[i] == '_'))//ถ้ามีตัวใดตัวหนึ่งไม่ใช่ A-Z หรือ 0-9 หรือ _ ทำเงื่อนไขใน if
            {
                flag = 0;//ให้ flag เท่ากับ 0
            }
        }
        return flag;//return ค่าเป็น flag
    }
    else//ถ้าไม่ใช่ตั้งเเต่ตัวเเรก ทำเงื่อนไขใน else
    {
        return 0;//return ค่าเป็น 0
    }
}

int check_end(int count,char *token)//ฟังก์ชันตรวจสอบ end exit
{
 if(count==1&&(strcmp("end",token)==0||count==1&&(strcmp("exit",token))==0))//ถ้าจำนวนมีค่าเป็น 1 เเละ เปรียบเทียบ string ว่าเป็น end หรือ exit ทำเงื่อนไขใน if
 {
 	return 1;//returm ค่าเป็น 1
 }
 else//ถ้าจำนวนไม่ได้มีค่าเป็น 1 ทำเงื่อนไขใน else
 {
   return 0;//return ค่าเป็น 0
 }
}

int main()//ฟังก์ชันหลัก
{
    char str[255], buff[255], token[40][20],operater[40][20],number[40][20],function[40][20],iden[40][20],err[40][20];//ประกาศตัวเเปรที่เป็นตัวหนังสือ
    int count, i;//ประกาศตัวเเปรที่เป็นจำนวนเต็ม
    double n;//ประกาศตัวเเปรที่เป็นได้ทั้งจำนวนเต็มเเละทศนิยม
    do
   {
    int count1=0,count2=0,count3=0,count4=0,count5=0;//ประกาศตัวเเปร count เป็นจำนวนเต็ม
    printf("command>");//UI
    gets(str);//เรียกงใช้ฟังงก์ชันเพื่อรับค่า string
    strcpy(buff, str);//เรียกใช้ฟังก์ชัน copy str ไว้ใน buff
    strlwr(buff);//เรียกใช้ฟังก์ชันเลี่ยน buff เป็นตัวอักษรพิมพ์เล็ก
    Add_space(buff);//เรียกใช้ฟังก์ชันเพิ่มช่องว่างให้กับเครื่องหมาย
    while (buff[strlen(buff)] == ' ')//ถ้า buff เป็น spacebar
    {
        buff[strlen(buff)] = '\0';//ให้เปลี่ยน buff เป็นช่องว่าง
    }
    printf("\"%s\"\n", buff);//UI
    count = split(buff,token);//ให้ count เท่ากับ ฟังก์ชันเเบ่งตัวอักษร
    if(check_end(count,*token)==1)//ถ้าฟังก์ชันตรวจสอบ end exit เท่ากับ 1 ทำเงื่อนไขใน if
    {
     printf("End Program\n");//เเสดงผลเป็น End Program
	}
	else//ฟังก์ชันตรวจสอบ end exit ไม่เท่ากับ 1 ทำเงื่อนไขใน else
  {
    for (i = 0; i < count; i++)//loop เเสดงประเภทของข้อมูลที่ใส่เข้าไป
    {
        printf("%d) ",(i+1));//เเสดงผล จำนวนข้อมูลที่ใส่
        if (check_operator(token[i]) == 1)//ถ้าฟังก์ขันตรวจสอบเครื่องหมาย มีค่าเป็น 1 ทำเงื่อนไขใน if
        {
          printf("%s is operator\n", token[i]);//เเสดงผลว่าเป็นเครื่องหมาย
          count1++;//เพิ่ม count1 ทีละ 1
          strcpy(operater[count1],token[i]);//copy token[i] ไว้ใน operater[count1]
        }
        else if (check_number(token[i], &n) == 1)//ถ้าฟังก์ชันตรวจสอบตัวเลข มีค่าเป็น 1 ทำเงื่อนไขใน else if
        {
          printf("%s is number %lf\n", token[i], n);//เเสดงผลว่าเป็นตัวเลข
          count2++;//เพิ่ม coun2 ทีละ 1
          strcpy(number[count2],token[i]);//copy token[i] ไว้ใน number[count2]
        }
        else if (check_function(token[i]) == 1)//ถ้าฟังก์ชันตรวจสอบฟังก์ชัน มีค่าเป็น 1 ทำเงื่อนไขใน else if
        {
          printf("%s is function\n", token[i]);//เเสดงผลว่าเป็นฟังก์ชัน
          count3++;//เพิ่ม count3 ทีละ 1
          strcpy(function[count3],token[i]);//copy token[i] ไว้ใน function[count3]
        }
        else if (check_identifier(token[i]) == 1)//ถ้าฟังก์ชันตรวจสอบ identifier มีค่าเป็น 1 ทำเงื่อนไขใน else if
        {
          printf("%s is identifier\n", token[i]);//เเสดงผลว่าเป็น identifier
          count4++;//เพิ่ม count4 ทีละ 1
          strcpy(iden[count4],token[i]);//copy token[i] ไว้ใน iden[count4]
        }
        else//ถ้าเป็น error ทำเงื่อนไขใน else
        {
          printf("%s is error\n", token[i]);//เเสดงผลว่าเป็น error
          count5++;//เพิ่ม count5 ทีละ1
          strcpy(err[count5],token[i]);//copy token[i] ไว้ใน err[count5]
		}
    }
    printf("Token = %d\n",count);//เเสดงจำนวนtoken ที่พบ
    printf("Opereter[%d] : ",count1);//เเสดงจำนวนของเครื่องหมาย ที่พบ
    for(i=1;i<=count1;i++)//ตรวจสอบเป็นรอบๆ ว่ามีเครื่องหมายอะไรบ้าง
    {
     printf("%s ",operater[i]);//เเสดงผลว่ามีเครื่องหมายอะไรบ้าง ที่พบ
	}
	printf("\nNumber[%d] : ",count2);//เเสดงจำนวนของตัวเลข ที่พบ
    for(i=1;i<=count2;i++)//ตรวจสอบเป็นรอบๆ ว่ามีตัวเลขอะไรบ้าง
    {
     printf("%s ",number[i]);//เเสดงผลว่ามีตัวเลขอะไรบ้าง ที่พบ
	}
	printf("\nFunction[%d] : ",count3);//เเสดงจำนวนของฟังก์ชัน ที่พบ
    for(i=1;i<=count3;i++)//ตรวจสอบเป็นรอบๆ ว่ามีฟังก์ชันอะไรบ้าง
    {
     printf("%s ",function[i]);//เเสดงผลว่ามีฟังก์ชันอะไรบ้าง ที่พบ
	}
	printf("\nIdentifier[%d] : ",count4);//เเสดงจำนวนของ identifier ที่พบ
    for(i=1;i<=count4;i++)//ตรวจสอบเป็นรอบๆ ว่ามี identifier อะไรบ้าง
    {
     printf("%s ",iden[i]);//เเสดงผลว่ามี identifier อะไรบ้าง ที่พบ
	}
	printf("\nError[%d] : ",count5);//เเสดงจำนวนของ Error ที่พบ
    for(i=1;i<=count5;i++)//ตรวจสอบเป็นรอบๆว่ามี error อะไรบ้าง
    {
     printf("%s ",err[i]);//เเสดงผลว่ามี error อะไรบ้าง ที่พบ
	}
	printf("\n");//enter
  }
   }while(check_end(count,*token)==0);//ออกจาก do เมื่อ ฟังก์ชันตรวจสอบ end exit มีค่าไม่เท่ากับ 0
    return 0;//จบการทำงานของโปรเเกรม
}






