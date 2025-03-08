#include <stdio.h>
#define N 100 // max size of queue
/* 
    ## Total function
    1. enqueue() / push()
    2. dequeue() / pop()
    3. isEmpty()
    4. front()/ peek()
    5. isFull()


*/


typedef struct Queue
{
    int arr[N];
    int front;
    int back;
} Queue;

void iniQueue(Queue * queue){
    queue->front = queue->back = -1;
}

// isEmpty

int isEmpty(Queue * queue){
    return (queue->front == -1);
}

// isFull
int isFull(Queue* q){
    return (q ->back == N-1);
}

void push(Queue* q, int data){
    if(isFull(q)){
        printf("Queue Overflow! Cannot insert %d\n", data);
    }
    else{
        if(q->front == -1){
            q->front = q->back = 0;
        }else{
            ++(q->back);
        }
        q->arr[q->back] =  data;
    }
}
void pop(Queue *q){
    if(isEmpty(q)){
        printf("Queue Overflow! Cannot delete\n");
    }else{
        q->arr[q->front] = 0;
        ++(q->front);
    }
}
int peek(Queue* q){
    return q->arr[q->front];
}

void printQueue(Queue* q){
    for(int i = q->front; i<= q->back; i++){
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}


int main(){
    Queue q;
    iniQueue(&q);

    push(&q, 10);
    push(&q, 20);
    push(&q, 30);
    push(&q, 40);
    printQueue(&q);
    pop(&q);
    printQueue(&q);
    push(&q, 40);
    printQueue(&q);
    printf("%d\n", peek(&q));
    return 0;
}