#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<math.h>
#define INIT_SIZE 100   //初始分配最大空间量
#define STACKINCREMENT 10   //（默认）增补空间量
//数字栈
typedef struct
{
    float *base;
    float *top;
    int stacksize;
} Stack_f;
//操作符栈
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
        printf("               |                   表达式求值                   |\n");
        printf("               |---------程序支持实数的加减乘除乘方运算---------|\n");
        printf("               |           请输入算术表达式,以'='结束           |\n");
        printf("               |------------------------------------------------|\n");
        gets(str);
        strcpy(strk,str);
        if(!Judge(str))
            printf("表达式无结束符“=”或结束符位置不合法!\n");
        else if(InitStack_f(&stack))
        {
            if(Translate(str))
            {
                printf("转化后的后缀表达式为：\n");
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
        printf("你想继续吗？'Y'或'y'为继续，其余任意键退出。。。\n");
        c=getchar();
        getchar();//吞噬掉输入判断符后的'\n'
    }
    return 0;
}

//构造一个存储实型的空栈，预设空间为100，分配失败就退出
//return 1:初始化成功  return 0 :初始化失败
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
//构造一个存储字符型的空栈,预设空间为100,分配失败就退出
//return 1:初始化成功  return 0 :初始化失败
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
//若栈s不空，则以e带值返栈顶元素，否则显示错误"ERROR",并退出程序
//return 1:获取成功  return 0 :获取失败
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
//取栈顶，若栈s不空，则删除栈s的栈顶元素，用e带值返回，否则退出程序
//return 1:获取成功  return 0 :获取失败
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
//判断表达式的等号是否合法
//in 中缀表达式
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
//在s的栈顶插入新的栈顶元素e，若栈的当前空间已满，则追加存储空间
//return 1:压入成功  return 0 :压入失败
//in float e
int Push_f(Stack_f *s,float e)
{
    if(s->top-s->base>=s->stacksize)
    {
        s->base=(float *)realloc(s->base,(s->stacksize+STACKINCREMENT)*sizeof(float));
        if(!s->base)
        {
            printf("溢出啦!\n");
            return 0;
        }
        s->top=s->base+s->stacksize;
        s->stacksize+=STACKINCREMENT;
    }
    *s->top++=e;
    return 1;
}
//在s的栈顶插入新的栈顶元素e，若栈的当前空间已满，则追加存储空间
//return 1:压入成功  return 0 :压入失败
//in char e
int Push_c(Stack_c *s,char e)
{
    if(s->top-s->base>=s->stacksize)
    {
        s->base=(char *)realloc(s->base,(s->stacksize+STACKINCREMENT)*sizeof(char));
        if(!s->base)
        {
            printf("栈满，溢出\n");
            return 0;
        }
        s->top=s->base+s->stacksize;
        s->stacksize+=STACKINCREMENT;
    }
    *s->top++=e;
    return 1;
}
//若栈s不空，则删除栈s的栈顶元素，用e带值返回，否则退出程序
//return 1:弹出成功  return 0 :弹出失败
//in Stack_f *s
//out float *e
int Pop_f(Stack_f *s,float *e)
{
    if(s->top==s->base)
        return 0;
    *e=*--s->top;
    return 1;
}
//若栈s不空，则删除栈s的栈顶元素，用e带值返回，否则退出程序
//return 1:弹出成功  return 0 :弹出失败
//in Stack_c *s
//out char *e
int Pop_c(Stack_c *s,char *e)
{

    if(s->top==s->base)
        return 0;
    *e=*--s->top;
    return 1;
}
//比较运算符的优先级
//in char Top_char,char s1_char
//return 1:栈顶运算符优先级大于刚读入的运算符；
//return 0:栈顶运算符优先级小于刚读入的运算符
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
    // i为下面array的横标
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
    // j为下面array的纵标
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
//中缀表达式转换为后缀表达式
//in 中缀表达式
//out 后缀表达式
//return 1转换成功return 0转换失败
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
    //表达式串已结束，栈中的运算符全部输出到s2[i]，并删除栈顶元素
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
//计算
//in 后缀表达式
//out 运算结果
//return 1计算成功return 0计算失败
int Calculate(Stack_f *s,char *s2)
{
    float m,x,y,z;
    int i=0,j=0;
    while(s2[i]!='=')
    {
        // 若为数值和小数点，则将其联合转换为浮点型后进栈
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
            //让栈顶和次顶元素与次运算符进行相应的运算，运算结果打印并进栈
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
                printf("符号不合法!\n");
                return 0;
            }
            }
            Push_f(s,z);
            i++;
        }
    }
    return 1;
}
//写出最终结果
//in中缀表达式，数字栈
//out中缀表达式=最终结果
void result(Stack_f *s,char *str)
{
    float v;
    GetTop_f(s,&v);
    printf("The final result is:%s%g\n",str,v);
}
