#include <stdio.h>
#include <string.h>
#include <ctype.h>

void Add_space(char *buff)//�ѧ��ѹ������ͧ��ҧ���Ѻ����ͧ����
{
    char str[255];//��С�� Array str
    int i, j;//��С�ȵ���������Ѻ loop for
    for (i = 0, j = 0; i < strlen(buff); i++)//ǹ loop �Ҥ�����Ǣͧ����ѡ��
    {
        if (strchr("+-/*^()", buff[i]) != NULL)//���������ͧ���������������鹪�ͧ��ҧ㹷����͹�� if
        {
            str[j++] = ' ';//��鹪�ͧ��ҧ
            str[j++] = buff[i];//����ͧ����
            str[j++] = ' ';//��鹪�ͧ��ҧ
        }
        else//������������ͧ��������繵������������͹�� else
        {
            str[j++] = buff[i];//�繵�����
        }
    }
    strcpy(buff, str);//copy str ���� buff
}

int check_operator(char *str)//�ѧ��ѹ��Ǩ�ͺ����ͧ����
{
    if ((strlen(str) == 1) && (strchr("+-*/^()", str[0]) != NULL))//��Ҥ�����Ǣͧ����ѡ���� 1 ���� ����ѡ�õ���˹觷�� 0 �� +-*( ) �����͹�� if
    {
        return 1;//return ����� 1
    }
    else//�������繵���ѡ�� �����͹�� else
    {
        return 0;//return ����� 0
    }
}

int check_number(char *str, double *n)//�ѧ��ѹ��Ǩ�ͺ����Ţ
{
    char ch;//��С�ȵ���ѡ��
    if (sscanf(str, "%lf%c", n, &ch) == 1)//��ҹ�����èҡ str �������¹�� %lf ��������� ������Ҩ���ҡѺ 1 �����͹�� if
    {
        return 1;//return ����� 1
    }
    else//����������ö����¹�� %lf �� �����͹�� else
    {
        return 0;//return ����� 0
    }
}

int split(char *buff,char token[][20])//�ѧ��ѹ��觵���ѡ��
{
    char *tok;//��С�ȵ����õ���ѡ�� tok �� pointer
    int count = 0;//��С�� count �� 0
    tok = strtok(buff, " ");//ź spacebar � buff ��͹��¡
    while (tok != NULL) //������ͪ�ͧ��ҧ�ͧ buff ���͡�ҡ loop
    {
        strcpy(token[count++], tok);//copy tok ���� token[count] ���� ���� count ���� 1
        tok = strtok(NULL, " ");//��ŧ spacebar �繪�ͧ��ҧ
    }
    return count;//return count
}

int check_function(char *str)//�ѧ��ѹ��Ǩ�ͺ�ѧ��ѹ
{
    char fname[15][10] = {"sin", "cos", "tan", "asin", "acos", "atan", "sqrt", "pow", "log", "exp", "abs"};//��С�Ȫ��Ϳѧ��ѹ
    int fcount = 11, i = 0;//��С����� fcount �� 0 ���� i �� 0
    char buff[20];//��С�� Array buff
    strcpy(buff, str);//copy str ���� str
    strlwr(buff);//����¹ buff �繵�����
    while (i < fcount && strcmp(fname[i], buff))//��Ҥ�� i �ѧ���¡��� fcount ���� buff �ѧ�������͹ fname[i]���������ҡѺ 0
    {
        i++;//������������� ���ú 11 ���
    }
    if (i < fcount)//��� i ���¡��� fcount �����͹�� if
    {
        return 1;// return ����� 1
    }
    else//��� i �ҡ������ҡѺ fcount �����͹�� else
    {
        return 0;//return ����� 0
    }
}

int check_identifier(char *str)//�ѧ��ѹ��Ǩ�ͺ identifier
{
    int flag = 1, i;//��С�ȵ����� flag ��ҡѺ 1 ���� ������ i ����Ѻ loop for
    if ((isalpha(str[0])) || str[0] == '_')//��Ǩ�ͺ��ҵ����á�繵���ѡ�� A-Z ����  _ �����͹�� if
    {
        for (i = 1; i < strlen(str); i++)//��Ǩ�ͺ��Ƿ�� 2 �֧ ����ش����
        {
            if (!(isalpha(str[i]) || isdigit(str[i]) || str[i] == '_'))//����յ��㴵��˹������� A-Z ���� 0-9 ���� _ �����͹�� if
            {
                flag = 0;//��� flag ��ҡѺ 0
            }
        }
        return flag;//return ����� flag
    }
    else//�����������������á �����͹�� else
    {
        return 0;//return ����� 0
    }
}

int check_end(int count,char *token)//�ѧ��ѹ��Ǩ�ͺ end exit
{
 if(count==1&&(strcmp("end",token)==0||count==1&&(strcmp("exit",token))==0))//��Ҩӹǹ�դ���� 1 ���� ���º��º string ����� end ���� exit �����͹�� if
 {
 	return 1;//returm ����� 1
 }
 else//��Ҩӹǹ������դ���� 1 �����͹�� else
 {
   return 0;//return ����� 0
 }
}

int main()//�ѧ��ѹ��ѡ
{
    char str[255], buff[255], token[40][20],operater[40][20],number[40][20],function[40][20],iden[40][20],err[40][20];//��С�ȵ����÷���繵��˹ѧ���
    int count, i;//��С�ȵ����÷���繨ӹǹ���
    double n;//��С�ȵ����÷�������駨ӹǹ������зȹ���
    do
   {
    int count1=0,count2=0,count3=0,count4=0,count5=0;//��С�ȵ����� count �繨ӹǹ���
    printf("command>");//UI
    gets(str);//���¡���ѧ���ѹ�����Ѻ��� string
    strcpy(buff, str);//���¡��ѧ��ѹ copy str ���� buff
    strlwr(buff);//���¡��ѧ��ѹ����¹ buff �繵���ѡ�þ�������
    Add_space(buff);//���¡��ѧ��ѹ������ͧ��ҧ���Ѻ����ͧ����
    while (buff[strlen(buff)] == ' ')//��� buff �� spacebar
    {
        buff[strlen(buff)] = '\0';//�������¹ buff �繪�ͧ��ҧ
    }
    printf("\"%s\"\n", buff);//UI
    count = split(buff,token);//��� count ��ҡѺ �ѧ��ѹ��觵���ѡ��
    if(check_end(count,*token)==1)//��ҿѧ��ѹ��Ǩ�ͺ end exit ��ҡѺ 1 �����͹�� if
    {
     printf("End Program\n");//��ʴ����� End Program
	}
	else//�ѧ��ѹ��Ǩ�ͺ end exit �����ҡѺ 1 �����͹�� else
  {
    for (i = 0; i < count; i++)//loop ��ʴ��������ͧ�����ŷ���������
    {
        printf("%d) ",(i+1));//��ʴ��� �ӹǹ�����ŷ�����
        if (check_operator(token[i]) == 1)//��ҿѧ��ѹ��Ǩ�ͺ����ͧ���� �դ���� 1 �����͹�� if
        {
          printf("%s is operator\n", token[i]);//��ʴ������������ͧ����
          count1++;//���� count1 ���� 1
          strcpy(operater[count1],token[i]);//copy token[i] ���� operater[count1]
        }
        else if (check_number(token[i], &n) == 1)//��ҿѧ��ѹ��Ǩ�ͺ����Ţ �դ���� 1 �����͹�� else if
        {
          printf("%s is number %lf\n", token[i], n);//��ʴ�������繵���Ţ
          count2++;//���� coun2 ���� 1
          strcpy(number[count2],token[i]);//copy token[i] ���� number[count2]
        }
        else if (check_function(token[i]) == 1)//��ҿѧ��ѹ��Ǩ�ͺ�ѧ��ѹ �դ���� 1 �����͹�� else if
        {
          printf("%s is function\n", token[i]);//��ʴ�������繿ѧ��ѹ
          count3++;//���� count3 ���� 1
          strcpy(function[count3],token[i]);//copy token[i] ���� function[count3]
        }
        else if (check_identifier(token[i]) == 1)//��ҿѧ��ѹ��Ǩ�ͺ identifier �դ���� 1 �����͹�� else if
        {
          printf("%s is identifier\n", token[i]);//��ʴ�������� identifier
          count4++;//���� count4 ���� 1
          strcpy(iden[count4],token[i]);//copy token[i] ���� iden[count4]
        }
        else//����� error �����͹�� else
        {
          printf("%s is error\n", token[i]);//��ʴ�������� error
          count5++;//���� count5 ����1
          strcpy(err[count5],token[i]);//copy token[i] ���� err[count5]
		}
    }
    printf("Token = %d\n",count);//��ʴ��ӹǹtoken ��辺
    printf("Opereter[%d] : ",count1);//��ʴ��ӹǹ�ͧ����ͧ���� ��辺
    for(i=1;i<=count1;i++)//��Ǩ�ͺ���ͺ� ���������ͧ�������ú�ҧ
    {
     printf("%s ",operater[i]);//��ʴ������������ͧ�������ú�ҧ ��辺
	}
	printf("\nNumber[%d] : ",count2);//��ʴ��ӹǹ�ͧ����Ţ ��辺
    for(i=1;i<=count2;i++)//��Ǩ�ͺ���ͺ� ����յ���Ţ���ú�ҧ
    {
     printf("%s ",number[i]);//��ʴ�������յ���Ţ���ú�ҧ ��辺
	}
	printf("\nFunction[%d] : ",count3);//��ʴ��ӹǹ�ͧ�ѧ��ѹ ��辺
    for(i=1;i<=count3;i++)//��Ǩ�ͺ���ͺ� ����տѧ��ѹ���ú�ҧ
    {
     printf("%s ",function[i]);//��ʴ�������տѧ��ѹ���ú�ҧ ��辺
	}
	printf("\nIdentifier[%d] : ",count4);//��ʴ��ӹǹ�ͧ identifier ��辺
    for(i=1;i<=count4;i++)//��Ǩ�ͺ���ͺ� ����� identifier ���ú�ҧ
    {
     printf("%s ",iden[i]);//��ʴ�������� identifier ���ú�ҧ ��辺
	}
	printf("\nError[%d] : ",count5);//��ʴ��ӹǹ�ͧ Error ��辺
    for(i=1;i<=count5;i++)//��Ǩ�ͺ���ͺ������ error ���ú�ҧ
    {
     printf("%s ",err[i]);//��ʴ�������� error ���ú�ҧ ��辺
	}
	printf("\n");//enter
  }
   }while(check_end(count,*token)==0);//�͡�ҡ do ����� �ѧ��ѹ��Ǩ�ͺ end exit �դ�������ҡѺ 0
    return 0;//����÷ӧҹ�ͧ������
}






