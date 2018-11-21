#include "basic.h"
Stack* init(Stack *s,int maxsize)
{
    s->MaxStack=maxsize;
    s->Top=-1;
    return s;
}
bool Is_empty(Stack *s)
{
    if(s->Top==-1)
        return true;
    return false;
}
bool Is_full(Stack *s)
{
    if(s->MaxStack==s->Top+1)
        return true;
    return false;
}
Stack *push(Stack *s,T e)
{
    if(Is_full(s))
    {
        printf("full.....\n");
        return s;
    }
    s->elements[++s->Top]=e;
    printf("%d\t",s->elements[s->Top]);
    return s;
}
Stack *pop(Stack *s)
{
    if(Is_empty(s))
    {
        printf("empty.......\n");
        return s;
    }
    printf("%d\n",s->elements[s->Top--]);
    return s;
}
main()
{
    Stack *s=(Stack *)malloc(sizeof(Stack));
    s=init(s,20);
    for(int i=0; i<15; i++)
    {
        s=push(s,i);
    }
    printf("\n");

    for(int i=0; i<10; i++)
    {
        s=pop(s);
    }
    printf(",,,,,,,,,,,,,,\n");
    return 0;
}
