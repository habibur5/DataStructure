#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct List{
    Node* head;
    Node* top;
}List;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void initList(List* list) {
    list->head = NULL;
    list->top = NULL;
}

void push(List* list, int data){
    Node * newNode = createNode(data);

    if(list->head == NULL){
        list->head = newNode;
        list->top = newNode;
    }else{
        list->top->next = newNode;
        list->top = newNode;
    }
}



int top(List * list){
    return list->top->data;
}
void pop(List *list){
    Node * temp = list->head;
    while(temp->next->next != NULL ){
        temp = temp->next;
    }
    
    temp->next = NULL;
    free(list->top);
    list->top = temp;
    
    
}
void PrintLL(List* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main(){
    List ll;
    initList(&ll);

    push(&ll,10);
    push(&ll,20);
    push(&ll,50);
    pop(&ll);
    push(&ll,10);
    push(&ll,20);
    push(&ll,50);
    pop(&ll);
    push(&ll,600);
    push(&ll,440);
    push(&ll,55660);
    pop(&ll);
    PrintLL(&ll);
    printf("%d", top(&ll));
    return 0;
}