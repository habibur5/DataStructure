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
};
class List {
    Node* head;
    Node *tail;

    public:
        List(){
            head = tail = NULL;
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
            //cout<<tail->next<<endl;
            tail = newNode;
            
        }
    }
    void printLL(){
        Node* temp = head;
        while(temp !=NULL){
            cout<< temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};


int main(){
    List ll;
    ll.push_front(1);
    ll.push_back(6);
    ll.push_front(2);
    ll.push_back(5);
    ll.push_front(3);

    ll.printLL();
    return 0;
}