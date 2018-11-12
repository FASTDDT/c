#include "basic.h"
Node *init(T e){
    Node *p=(Node *)malloc(sizeof(Node));
    p->element=e;
    p->next=NULL;
    return p;
}
Node *push(Node *p,T e){

    return p;
}
bool Is_empty(Node *p){
    return p==NULL;
}
Node *last(Node *p){
    while(p->next!=NULL){
        printf("%d\t",p->element);
        p=p->next;
    }
    return p;
}
Node *add(T e,Node *head){
    Node *p=head;
    p=last(p);
    Node *n=(Node *)malloc(sizeof(Node));
    n->element=e;
    n->next=NULL;
    p->next=n;
    return head;

}
Node *Insert(T e,Node *head,int place){

    Node *p=head,*rear;
    for(int i=1;i<place;i++){
        p=p->next;
    }
    rear=p->next;
    Node *n=(Node *)malloc(sizeof(Node));
    n->element=e;
    n->next=rear;
    p->next=n;
    return head;
}
int main(){
    Node *p=init(10);
    for(int i=0;i<10;i++){
        printf("\n");
        p=add(i,p);
    }
    p=Insert(666,p,2);
    printf("\n");
    last(p);
    return 0;
}

