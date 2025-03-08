// Define Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define List structure
typedef struct List {
    Node* head;
    Node* tail;
} List;

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Initialize the list 
void initList(List* list) {
    list->head = NULL;
    list->tail = NULL;
}

// Function to push an element to the front of the list
void push_front(List* list, int val) {
    Node* newNode = createNode(val);
    if (list->head == NULL) {
        list->head = list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
    }
}

// Function to push an element to the back of the list
void push_back(List* list, int val) {
    Node* newNode = createNode(val);
    if (list->head == NULL) {
        list->head = list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}
// Function to push the elemen after the given postion
void insert(List* list,int val, int pos){

    if(pos>0){
        Node* newNode = createNode(val);
        Node * temp = list->head;
        for(int i = 0; i<pos-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
}
// Function to print the linked list
void printLL(List* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
// Function to remove/delete an element to the front of the list

void pop_front(List* list){
    if(list->head != NULL){
        Node *temp = list->head;
        list->head =  list->head->next;
        temp->next = NULL;
        free(temp);
    }
}

// Function to remove/delete an element to the last of the list

void pop_back(List* list){
    if(list->tail != NULL){
        Node * temp = list->head;
        while(temp->next != list->tail) temp = temp->next;
        temp->next = NULL;
        free(list->tail);
        list->tail = temp;
    }
}

// Function to free allocated memory
void freeList(List* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = list->tail = NULL;
}
