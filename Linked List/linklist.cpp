#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = NULL;
        }

        /*         
            ~Node(){
            if( next != NULL){
                
                delete next;
                next = NULL;
            }
        } */
};

class List {
    public:
        Node* head;
        Node *tail;

        List(){
            head = tail = NULL;
        }
/*         ~List(){
            if(head !=NULL){
                delete head;
                head = NULL;
            }
        } */
// push front, push back, pop front, pop back
// problem links:
// leetcode 234, https://leetcode.com/problems/palindrome-linked-list/
// https://www.geeksforgeeks.org/linked-list-set-1-introduction/
    // https://www.geeksforgeeks.org/linked-list-set-2-insertion/
    // https://www.geeksforgeeks.org/linked-list-set-3-deletion/
    // https://www.geeksforgeeks.org/linked-list-set-4-reverse/
    // https://www.geeksforgeeks.org/linked-list-set-5-detect-loop/
    // https://www.geeksforgeeks.org/linked-list-set-6-find-middle-element/
    // https://www.geeksforgeeks.org/linked-list-set-7-intersection/
    // https://www.geeksforgeeks.org/linked-list-set-8-remove-duplicates-from-a-sorted-linked-list/
    // https://www.geeksforgeeks.org/linked-list-set-9-intersection-point-in-y-shapped-linked-lists/
    // https://www.geeksforgeeks.org/linked-list-set-10-flattening-a-linked-list/
    // https://www.geeksforgeeks.org/linked-list-set-11-add-two-numbers-represented-by-linked-lists/
    // https://www.geeksforgeeks.org/linked-list-set-12-pairwise-swap-elements-of-a-given-linked-list/
    // https://www.geeksforgeeks.org/linked-list-set-13-reverse-a-linked-list-in-groups-of-given-size/
    

    void push_front(int val){
        Node* newNode = new Node(val); // dynamic
        if(head == NULL){
            head  = tail = newNode;
            return;
        }else{
            newNode->next = head;
            head  = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head  = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
            
        }
    }
    
    void pop_front(){
        if(head == NULL){
            cout<<"Linked List is empty"<<endl;
        }
        Node * temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void pop_back(){
        Node *temp = head;
        while (temp->next->next != NULL){   
            temp = temp->next;
        }
        
        Node * todelete = temp->next;
        temp->next = NULL;
        tail = temp;
        delete todelete;
    }

    void printLL(){
        Node* temp = head;
        while(temp !=NULL){
            cout<< temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    // get size
    // problem links:
    int getSize(){
        int sz = 0;
        Node * temp = head;
        while (temp != NULL){
            temp = temp->next;
            ++sz;
        }
        return sz;
    }
    // remove nth node from the end
    // problem links:
    // leetcode 19, https://leetcode.com/problems/remove-nth-node-from-end-of-list/
    // https://www.geeksforgeeks.org/remove-n-th-node-from-the-end-of-a-linked-list/
    // https://www.geeksforgeeks.org/remove-n-th-node-from-the-end-of-a-linked-list-in-one-pass/
    // https://www.geeksforgeeks.org/remove-n-th-node-from-the-end-of-a-linked-list-using-two-pointers/
    // https://www.geeksforgeeks.org/remove-n-th-node-from-the-end-of-a-linked-list-using-recursion/
    // https://www.geeksforgeeks.org/remove-n-th-node-from-the-end-of-a-linked-list-using-stack/
    void remove(int n){
        
        int sz = getSize();
        if (n == 0 || abs(n) > sz) {
            cout << "Invalid index.\n";
            return;
        }
        Node* prev = head;
        if(n<0) n = sz+n+1;
        if(n==1) pop_front();
        else{
            for(int i = 2 ; i<n; i++){
                prev = prev->next;
            }
            Node *toDelete = prev->next;
            if(toDelete == tail){
                tail = prev;
                tail->next = NULL;
            }
            else{
                prev->next = toDelete->next;
                toDelete->next = NULL;
            }
            delete toDelete;
        }
        
    }

    void insert(int val, int pos){
        if(pos == 1) {
            push_front(val);
            return;
        }
        Node * newNode = new Node(val);
        
        Node * temp = head;
        for(int i = 2; i<pos; i++){
            if(temp == NULL){
                cout<<"Invalid Position: "<<pos<<endl;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    int searchIt(int key){
        Node* temp = head;
        int idx = 0;
        while(temp!= NULL){
            
            if(temp->data == key){
                return idx;
            }
            temp = temp->next;
            ++idx;
        }
        return -1;
    }
    int searchHelper(Node* head, int key){
        if(head==NULL) return -1;
        if(head->data==key) return 0;
        int idx = searchHelper(head->next, key);
        if(idx == -1) return -1;
        return idx+1;
    }
    int searchRec(int key){
        return searchHelper(head, key);
    }
    // reverse linked list
    // problem links:
    // leetcode 206, https://leetcode.com/problems/reverse-linked-list/
    // https://www.geeksforgeeks.org/reverse-a-linked-list/
    // https://www.geeksforgeeks.org/reverse-a-linked-list-in-groups-of-given-size/
    // https://www.geeksforgeeks.org/reverse-a-linked-list-in-groups-of-given-size-iterative-and-recursive/

    void reverse(){
        Node * prev = NULL;
        Node * current = head;

        tail = current;
        while(current != NULL){
            Node *  next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            
        }
        head = prev;
    }
    
    // reverse between leetcode 92
    //leetcode 92, https://leetcode.com/problems/reverse-linked-list-ii/
    Node* reverseBetween(int left, int right) {
    if (!head || left == right) return head;
    Node* prev = nullptr;
    Node* curr = head;
    for(int i =1; i<left; i++){
        prev = curr;
        curr = curr->next;
    }
    Node* leftPrevious = prev;
    Node* tail = curr;
    for(int i = left; i<=right; i++){
        Node* next = curr->next;
        curr->next = prev;
        prev= curr;
        curr= next;

    }

    if(leftPrevious!=NULL) leftPrevious->next = prev;
    else head = prev;
    tail->next = curr;
    return head;
}
    // detect cycle in linked list
    // problem links:
    // leetcode 141, https://leetcode.com/problems/linked-list-cycle/
    // https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/

    // Floyd's Cycle-> PQ: leetcode 141
    bool isCycle(){
        Node* slow =head;
        Node* fast = head;
        while(fast != NULL && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
    // remove cycle in linked list
    // problem links:
    // leetcode 142, https://leetcode.com/problems/linked-list-cycle-ii/
    // https://www.geeksforgeeks.org/remove-loop-in-linked-list/
    // Floyd's Cycle-> PQ: leetcode 142

    void removeCycle(){
        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;
        while(fast != NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                isCycle = true;
                break;
            }
        }

        if(isCycle == false) {
            return;
        }
        cout<<"cycle exits"<<endl;
        slow = head;
        if(slow == fast){
            while(fast->next != slow) {
                fast = fast->next;
            }
            fast->next = NULL;
        }else{
            Node * prev = fast;
            while(slow != fast){
                slow = slow->next;
                prev = fast;
                fast = fast->next;
            }
            prev->next = NULL;
        }
        
    }


};

void printLL(Node * head){
        Node* temp = head;
        while(temp !=NULL){
            cout<< temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }


// split linked list at mid
// problem links:
// leetcode 876, https://leetcode.com/problems/middle-of-the-linked-list/
// https://www.geeksforgeeks.org/write-a-function-to-get-the-middle-of-a-linked-list/

Node* splitAtMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL) {
        prev->next = NULL;
    }

    return slow;
}
// merge two sorted linked lists
// problem links:
// leetcode 21, https://leetcode.com/problems/merge-two-sorted-lists/
// https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/

Node* merge(Node* h1, Node*h2) {
    List ans;
    Node* i = h1;
    Node* j = h2;

    while(i != NULL && j != NULL) {
        if(i->data <= j->data) {
            ans.push_back(i->data);
            i = i->next;
        } else {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while(i != NULL) {
        ans.push_back(i->data);
        i = i->next;
    }

    while(j != NULL) {
        ans.push_back(j->data);
        j = j->next;
    }
    return ans.head;
}
// merge sort linked list
// problem links:
// leetcode 148, https://leetcode.com/problems/sort-list/
// https://www.geeksforgeeks.org/sort-a-linked-list-using-merge-sort/
Node* mergeSort(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* rightHead = splitAtMid(head);
    Node* sortedLeft = mergeSort(head);
    Node* sortedRight =mergeSort(rightHead);

    return merge(sortedLeft, sortedRight);
}

Node* reverse(Node* head){
    Node * prev = NULL;
        Node * current = head;
        while(current != NULL){
            Node *  next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            
        }
    return prev;
}
// zigzag linked list
// problem links:
// https://www.geeksforgeeks.org/zigzag-or-wiggle-sort/
// leetcode 273, https://leetcode.com/problems/zigzag-conversion/

Node* zigzag(Node* head){
    Node* rightHeadRev = reverse(splitAtMid(head));

    Node * left = head;
    Node * right = rightHeadRev;
    Node * tail = right;

    while(left != NULL && right!=NULL){
        Node* nextLeft = left->next;
        Node* nextRight = right->next;

        left->next = right;
        right->next = nextLeft;
        tail = right;
        left = nextLeft;
        right = nextRight;

    }

    if(right != NULL){
        tail->next = right;
    }
    return head;
}

int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.insert(10,2);

    // ll.head = mergeSort(ll.head);
    // zigzag(ll.head);
    // ll.remove(1);
    ll.printLL();
    return 0;
}



/* bool isCycle(Node* head){
    Node* slow =head;
    Node* fast = head;

    while(fast != NULL && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
} 

void removeCycle(Node* head){
    Node* slow =head;
    Node* fast = head;
    bool isCycle = false;
    while(fast != NULL && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            isCycle = false;
        }
        if(!isCycle) return;
        slow = head;
        if(slow == fast){
            while(fast->next != slow) fast = fast->next;
            fast->next = NULL;
        }else{
            Node * prev = fast;
            while(slow != fast){
                slow = slow->next;
                prev = fast;
                fast = fast->next;
            }
            prev->next = NULL;
        }
    }
    
}
 */


