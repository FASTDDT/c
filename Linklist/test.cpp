#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<math.h>
#define INIT_SIZE 100   //��ʼ�������ռ���
#define STACKINCREMENT 10   //��Ĭ�ϣ������ռ���
//����ջ
typedef struct
{
    float *base;
    float *top;
    int stacksize;
} Stack_f;
//������ջ
typedef struct
{
    char *base;
    char *top;
    int stacksize;
} Stack_c;
int Judge(char *s);
int InitStack_f(Stack_f *s);
int InitStack_c(Stack_c *s);
int GetTop_f(Stack_f *s,float *e);
int GetTop_c(Stack_c *s,char *e);
int Push_f(Stack_f *s,float e);
int Push_c(Stack_c *s,char e);
int Pop_f(Stack_f *s,float *e);
int Pop_c(Stack_c *s,char *e);
int precede(char Top_char,char s1_char);
int Translate(char *s1);
int Calculate(Stack_f *s,char *s2);
void result(Stack_f *s,char *str);
int main()
{
    Stack_f stack;
    char str[200];
    char strk[200];
    char c='Y';
    while(c=='y' || c=='Y')
    {
        printf("               |------------------------------------------------|\n");
        printf("               |                   ���ʽ��ֵ                   |\n");
        printf("               |---------����֧��ʵ���ļӼ��˳��˷�����---------|\n");
        printf("               |           �������������ʽ,��'='����           |\n");
        printf("               |------------------------------------------------|\n");
        gets(str);
        strcpy(strk,str);
        if(!Judge(str))
            printf("���ʽ�޽�������=���������λ�ò��Ϸ�!\n");
        else if(InitStack_f(&stack))
        {
            if(Translate(str))
            {
                printf("ת����ĺ�׺���ʽΪ��\n");
                puts(str);
                if(Calculate(&stack,str))
                {
                    result(&stack,strk);
                }
                else
                    printf("ERROR !\n");
            }
            else
                printf("ERROR !\n");
        }
        else
            printf("ERROR !\n");
        printf("���������'Y'��'y'Ϊ����������������˳�������\n");
        c=getchar();
        getchar();//���ɵ������жϷ����'\n'
    }
    return 0;
}

//����һ���洢ʵ�͵Ŀ�ջ��Ԥ��ռ�Ϊ100������ʧ�ܾ��˳�
//return 1:��ʼ���ɹ�  return 0 :��ʼ��ʧ��
int InitStack_f(Stack_f *s)
{
    s->base=(float *)malloc(INIT_SIZE*sizeof(float));
    if(s->base)
    {
        s->top=s->base;
        s->stacksize=INIT_SIZE;
        return 1;
    }
    else
        return 0;
}
//����һ���洢�ַ��͵Ŀ�ջ,Ԥ��ռ�Ϊ100,����ʧ�ܾ��˳�
//return 1:��ʼ���ɹ�  return 0 :��ʼ��ʧ��
int InitStack_c(Stack_c *s)
{
    s->base=(char *)malloc(INIT_SIZE*sizeof(char));
    if(s->base)
    {
        s->top=s->base;
        s->stacksize=INIT_SIZE;
        return 1;
    }
    else
        return 0;
}
//��ջs���գ�����e��ֵ��ջ��Ԫ�أ�������ʾ����"ERROR",���˳�����
//return 1:��ȡ�ɹ�  return 0 :��ȡʧ��
//in Stack_f *s
//out float *e
int GetTop_f(Stack_f *s,float *e)
{
    if(s->top!=s->base)
    {
        *e=*(s->top-1);
        return 1;
    }
    else
    {
        printf("ERROR!");
        return 0;
    }
}
//ȡջ������ջs���գ���ɾ��ջs��ջ��Ԫ�أ���e��ֵ���أ������˳�����
//return 1:��ȡ�ɹ�  return 0 :��ȡʧ��
//in Stack_c *s
//out char *e
int GetTop_c(Stack_c *s,char *e)
{
    if(s->top!=s->base)
    {
        *e=*(s->top-1);
        return 1;
    }
    else
    {
        printf("ERROR!\n");
        return 0;
    }
}
//�жϱ��ʽ�ĵȺ��Ƿ�Ϸ�
//in ��׺���ʽ
int Judge(char *s)
{
    int len=strlen(s);
    int j;
    for(j=0; j<len-1; j++)
        if(s[j]=='=')
            return 0;
        else if(s[len-1]=='=')
            return 1;
        else
            return 0;
}
//��s��ջ�������µ�ջ��Ԫ��e����ջ�ĵ�ǰ�ռ���������׷�Ӵ洢�ռ�
//return 1:ѹ��ɹ�  return 0 :ѹ��ʧ��
//in float e
int Push_f(Stack_f *s,float e)
{
    if(s->top-s->base>=s->stacksize)
    {
        s->base=(float *)realloc(s->base,(s->stacksize+STACKINCREMENT)*sizeof(float));
        if(!s->base)
        {
            printf("�����!\n");
            return 0;
        }
        s->top=s->base+s->stacksize;
        s->stacksize+=STACKINCREMENT;
    }
    *s->top++=e;
    return 1;
}
//��s��ջ�������µ�ջ��Ԫ��e����ջ�ĵ�ǰ�ռ���������׷�Ӵ洢�ռ�
//return 1:ѹ��ɹ�  return 0 :ѹ��ʧ��
//in char e
int Push_c(Stack_c *s,char e)
{
    if(s->top-s->base>=s->stacksize)
    {
        s->base=(char *)realloc(s->base,(s->stacksize+STACKINCREMENT)*sizeof(char));
        if(!s->base)
        {
            printf("ջ�������\n");
            return 0;
        }
        s->top=s->base+s->stacksize;
        s->stacksize+=STACKINCREMENT;
    }
    *s->top++=e;
    return 1;
}
//��ջs���գ���ɾ��ջs��ջ��Ԫ�أ���e��ֵ���أ������˳�����
//return 1:�����ɹ�  return 0 :����ʧ��
//in Stack_f *s
//out float *e
int Pop_f(Stack_f *s,float *e)
{
    if(s->top==s->base)
        return 0;
    *e=*--s->top;
    return 1;
}
//��ջs���գ���ɾ��ջs��ջ��Ԫ�أ���e��ֵ���أ������˳�����
//return 1:�����ɹ�  return 0 :����ʧ��
//in Stack_c *s
//out char *e
int Pop_c(Stack_c *s,char *e)
{

    if(s->top==s->base)
        return 0;
    *e=*--s->top;
    return 1;
}
//�Ƚ�����������ȼ�
//in char Top_char,char s1_char
//return 1:ջ����������ȼ����ڸն�����������
//return 0:ջ����������ȼ�С�ڸն���������
int precede(char Top_char,char s1_char)
{
    int i=0,j=0;
    static char array[8][8]=
    {
        '>', '>', '<', '<', '<', '<', '>', '>',
        '>', '>', '<', '<', '<', '<', '>', '>',
        '>', '>', '>', '>', '<','<', '>', '>',
        '>', '>', '>', '>', '<','<', '>', '>',
        '>', '>', '>', '>', '<','<', '>', '>',
        '<', '<', '<', '<', '<','<', '=', '!',
        '>', '>', '>', '>', '<','!', '>', '>',
        '<', '<', '<', '<', '<','<', '!', '='
    };
    switch(Top_char)
    {
    // iΪ����array�ĺ��
    case '+' :
        i=0;
        break;
    case '-' :
        i=1;
        break;
    case '*' :
        i=2;
        break;
    case '/' :
        i=3;
        break;
    case '^' :
        i=4;
        break;
    case '(' :
        i=5;
        break;
    case ')' :
        i=6;
        break;
    case '=' :
        i=7;
        break;
    }
    switch(s1_char)
    {
    // jΪ����array���ݱ�
    case '+' :
        j=0;
        break;
    case '-' :
        j=1;
        break;
    case '*' :
        j=2;
        break;
    case '/' :
        j=3;
        break;
    case '^' :
        j=4;
        break;
    case '(' :
        j=5;
        break;
    case ')' :
        j=6;
        break;
    case '=' :
        j=7;
        break;
    }
    if(array[i][j]=='>')
        return 1;
    else
        return 0;
}
//��׺���ʽת��Ϊ��׺���ʽ
//in ��׺���ʽ
//out ��׺���ʽ
//return 1ת���ɹ�return 0ת��ʧ��
int Translate(char *s1)
{
    char s2[80];
    Stack_c Optr;
    int i=0,j=0;
    char t;
    InitStack_c(&Optr);
    Push_c(&Optr,'(');
    while(s1[i]!='=')
    {
        if(s1[i]>='0' && s1[i]<='9' || s1[i]=='.')
        {
            s2[j++]=s1[i];
            if((s1[i+1]<'0' || s1[i+1]>'9') && s1[i+1]!='.')
                s2[j++]=' ';
        }
        else
            switch(s1[i])
            {
            case'(':
                Push_c(&Optr,s1[i]);
                break;
            case')':
                Pop_c(&Optr,&t);
                break;
                while(t!='(')
                {
                    s2[j++]=t;
                    Pop_c(&Optr,&t);
                }
                break;
            default:
                while(GetTop_c(&Optr,&t),precede(t,s1[i]))
                {
                    Pop_c(&Optr,&t);
                    s2[j++]=t;
                }
                Push_c(&Optr,s1[i]);
            }
        i++;
    }
    Pop_c(&Optr,&t);
    //���ʽ���ѽ�����ջ�е������ȫ�������s2[i]����ɾ��ջ��Ԫ��
    while(t!='(')
    {
        s2[j++]=t;
        Pop_c(&Optr,&t);
    }
    for(i=0; i<j; i++)
        s1[i]=s2[i];
    s1[i]= '=';
    s1[i+1]='\0';
    return 1;
}
//����
//in ��׺���ʽ
//out ������
//return 1����ɹ�return 0����ʧ��
int Calculate(Stack_f *s,char *s2)
{
    float m,x,y,z;
    int i=0,j=0;
    while(s2[i]!='=')
    {
        // ��Ϊ��ֵ��С���㣬��������ת��Ϊ�����ͺ��ջ
        if(s2[i]>='0' && s2[i]<='9' || s2[i]=='.')
        {
            m=0;
            while(s2[i]!=' ' && s2[i]!='.')
                m=m*10+(float)(s2[i++]-'0');
            if(s2[i]=='.')
            {
                j=0;
                i++;
                while(s2[i]!=' ')
                {
                    m=m*10+(float)(s2[i++]-'0');
                    j++;
                }
                while(j>0)
                {
                    m/=10;
                    j--;
                }
            }
            i++;
            Push_f(s,m);
            GetTop_f(s,&m);
            printf("get:%g\n",m);
        }
        else
        {
            Pop_f(s,&x);
            Pop_f(s,&y);
            switch(s2[i])
            {
            //��ջ���ʹζ�Ԫ����������������Ӧ�����㣬��������ӡ����ջ
            case '+':
                z=y+x;
                printf("%g+%g=%g\n",y,x,z);
                break;
            case '-':
                z=y-x;
                printf("%g-%g=%g\n",y,x,z);
                break;
            case '*':
                z=y*x;
                printf("%g*%g=%g\n",y,x,z);
                break;
            case '/':
                if(x==0)
                {
                    printf("ERROR !\n");
                    return 0;
                }
                else
                {
                    z=y/x;
                    printf("%g/%g=%g\n",y,x,z);
                    break;
                }
            case '^':
                z=pow(y,x);
                printf("%g^%g=%g\n",y,x,z);
                break;
            default:
            {
                printf("���Ų��Ϸ�!\n");
                return 0;
            }
            }
            Push_f(s,z);
            i++;
        }
    }
    return 1;
}
//д�����ս��
//in��׺���ʽ������ջ
//out��׺���ʽ=���ս��
void result(Stack_f *s,char *str)
{
    float v;
    GetTop_f(s,&v);
    printf("The final result is:%s%g\n",str,v);
}
