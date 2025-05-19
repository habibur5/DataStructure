#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int val){
            data = val;
            next = NULL;
            prev = NULL;
        }

};

class DoublyLinkedlist{
  public:
    Node * head;
    Node * tail;

    DoublyLinkedlist(){
      head = NULL;
      tail = NULL;
    }
    void print(){

        Node *temp = head;
        while(temp !=NULL ){
          cout<<temp->data<<" <=> ";
          temp = temp->next;
        }
      cout<<"NULL"<<endl;
    }
    void push_front(int val){
      Node* newNode = new Node(val);

      if(head == NULL){
        head = newNode;
        tail = newNode;
      }
      else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
      }
    }

    void push_back(int val){
      Node* nNode = new Node(val);
      if(head == NULL){
        head = tail = nNode;
      }
      else{
        nNode->prev = tail;
        tail->next = nNode;
        tail = nNode;
      }
    }
};


int main(){
    
    DoublyLinkedlist dll;
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);
    dll.push_back(4);
    dll.push_back(5);
    dll.push_back(6);
    dll.print();



    return 0;
}