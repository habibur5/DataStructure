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

        ~Node(){
            if( next != NULL){
                
                delete next;
                next = NULL;
            }
        }
};
class List {
    

    public:
        Node* head;
        Node *tail;
        List(){
            head = tail = NULL;
        }
        ~List(){
            if(head !=NULL){
                delete head;
                head = NULL;
            }
        }
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

        while (temp->next->next != NULL)
        {   
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
    
    int getSize(){
        int sz = 0;
        Node * temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
            ++sz;
        }
        return sz;
        
    }
    void remove(int n){
        Node* prev = head;
        int sz = getSize();
        if(n<0){
            n = sqrt(pow(n,2));
            for(int i = 1 ; i<=(sz-n); i++){
                prev = prev->next;
            }
            Node * toDelete = prev->next;
            prev->next = prev->next->next;
            toDelete->next = NULL;
            delete toDelete;
        }
        else{
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
                prev->next = prev->next->next;
                toDelete->next = NULL;
            }
            delete toDelete;
            }
            
        }

    }
    void insert(int val, int pos){
        if(pos == 0) {
            push_front(val);
            return;
        }
        Node * newNode = new Node(val);
        
        Node * temp = head;
        for(int i = 0; i<pos-1; i++){
            if(temp== NULL){
                cout<<"Invalid Position: "<<pos<<endl;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
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
    void removeCycle(){
        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;
        while(fast != NULL && fast->next){
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



int main(){
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    /* ll.pop_back(); */
    //ll.remove(5);
    //ll.insert(10,1);
    //ll.reverse();
    ll.tail->next = ll.head;
    
    //ll.printLL();
    (ll.isCycle() == true) ? cout <<"cycle exit"<<endl : cout<<"cycle doesnot exit"<<endl;
    ll.removeCycle();
    ll.printLL();
    return 0;
}