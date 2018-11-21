#include<basic.h>
Queue* init(Queue *q,int maxsize){
    q->max_queue=maxsize;
    q->former=q->rear=-1;
    return q;
}
Queue* push(Queue *q,T e){
    q->element[++q->rear]=e;
    return q;
}
T pop(Queue *q){
    return q->element[++q->former];
}

main(){
    Queue *q=(Queue *)malloc(sizeof(Queue));
    q=init(q,20);
    return 0;
}
