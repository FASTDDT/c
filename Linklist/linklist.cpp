#include "basic.h"
Node *init(T e){
    Node *p=(Node *)malloc(sizeof(Node));
    p->element=e;
    p->next=NULL;
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
Node *showAll(Node *head){
    Node *p=head;
    do{
        printf("%d\t",p->element);

    }while(p=p->next);
    printf("\n");
}
Node *push(T e,Node *head){
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
Node *Pop_head(Node *head){
    Node *p=head->next;
    head->next=NULL;
    free(head);
    return p;
}
Node *Pop_tail(Node *head){
    Node *p=head;
    while(p->next->next!=NULL){
        p=p->next;
    }
    printf("p->next->next:%s\n",p->next->next);
    free(p->next);
    p->next=NULL;
    return head;
}
Node* delete_one(Node *head, int num){
    Node *rear,*p=head;
    if(num==0){
        return Pop_head(head);
    }
    for(int i=0;i<num-1;i++){
        if(!(p=p->next)){
             printf("error!");
            return head;
        }
    }
    rear=p->next;
    p->next=p->next->next;
    free(rear);
    return  head;
}
Node *push_head(T e,Node *head){
    Node *p=(Node *)malloc(sizeof(Node));
    p->element=e;
    p->next=head;
    return p;
}
int main(){
    Node *p=init(10);
    for(int i=0;i<10;i++){
        printf("\n");
        p=push(i,p);
    }
    printf("\n");
    showAll(p);
    printf("\n");
    p=Pop_head(p);
    showAll(p);
    p=Pop_tail(p);
    showAll(p);
    p=delete_one(p,0);
    showAll(p);
    p=push_head(100,p);
    printf("\n");
    showAll(p);
    return 0;
}

