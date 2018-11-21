#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define T int
#define Max_Size 50
#define TRUE 1
#define FALSE 0
#define Bool int
typedef struct node{
    T element;
    node *next;
}Node;
typedef struct stack_0{
    int Top,MaxStack;
    T elements[Max_Size];
}Stack;
typedef struct queue_0{
    int former,rear,max_queue;
    T element[Max_Size];
}Queue;
