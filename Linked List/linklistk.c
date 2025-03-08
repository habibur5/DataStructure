#include <stdio.h>
#include <stdlib.h>

// Define a new node
struct Node{
    int data;
    struct Node *next;
};

/// create a node function
struct Node *createNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert data at the end
void push_back(struct Node* *LinkList, int data){
    struct Node *newNode = createNode(data);
    if (*LinkList == NULL){
        *LinkList = newNode;
    }
    else{
        struct Node *temp = *LinkList;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void push_front(struct Node* *LinkList, int data){
    struct Node* newNode = createNode(data);
    if(*LinkList== NULL){
        *LinkList = newNode;
    }else{
        //struct Node *temp = *LinkList;
        newNode->next = *LinkList;
        *LinkList = newNode;
    }
}


// print the linkedList value

void printLinkedList(struct Node* *linkList){
    struct Node* temp = *linkList;
    
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct Node *LinkList = NULL;

    
    push_back(&LinkList, 20);
    push_back(&LinkList, 10);
    push_back(&LinkList, 40);
    push_front(&LinkList, 40);
    push_front(&LinkList, 60);
    printLinkedList(&LinkList);

    return 0;
}