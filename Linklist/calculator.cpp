#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max_Size 100
typedef char T;
typedef struct stack_0
{
    int Top,MaxStack;
    T elements[Max_Size];
} Stack;
Stack* init(Stack* s,int maxSize){
    s->Top=-1;
    s->MaxStack=maxSize;
}
float calculator(float a,float b,char c)
{
    switch(c)
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;

    }
}
main(){
    char *s="549.3*454-88.78/45";
    double k;

    for(int i=0;i<strlen(s);i++){
        k=atof(s++);
        printf("%lf\n",k);
    }

    return 0;
}
