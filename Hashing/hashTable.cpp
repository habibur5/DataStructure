#include <bits/stdc++.h>
using namespace std;

/* 
usages:
        * when need to store key-value pairs
            ------------------------
            | Key         | Value  |
            |-------------|--------|
            |  USA        |  1000  |
            |  india      |  150   |
            |  Banglades  |  2000  |
            |  China      |  500   |
            |  Japan      |  300   |
            |~~~~~~~~~~~~~~~~~~~~~~|

        when need to search, insert, delete in O(1) time on average
        when need to handle collisions
Unorderd Data Structure: Hash Table

Time Complexity: operations
  - Search        : O(1) on average, O(n) in worst case
  - Insert        : O(1) on average, O(n) in worst case
  - Delete/Remove : O(1) on average, O(n) in worst case



  lamda = load factor = currentSize / tableSize
  rehashing when lamda > 1
  tableSize = tableSize * 2;
  
*/


class Node{
   
  public:
    string key;
    int value;
    Node *next; // pointer to the next node in case of collision

    Node(string k, int v) : key(k), value(v), next(nullptr) {}
    // Destructor to free the next node
    ~Node() {
        if (next != nullptr) {
            delete next; // Recursively delete the next node
        }
    }
};

class HashTable{
  int tableSize;
  int currentSize; // rehashing when currentSize > tableSize/2
  Node **table; // array of pointers to Node

  // Hash function to compute the index for a given key
  int hashFunction(string key){
    /* 
    1. find ascii value of each character in the string
    2. square the ascii value
    3. sum the squared values
    4. take modulo with tableSize to get the index
    5. return the index
    */

    int hashValue = 0;
    for (char c : key) {
        hashValue += (c * c) % tableSize; // squaring the ascii value and taking modulo with tableSize
    }
    return hashValue% tableSize; // return the index
    // Note: This is a simple hash function and may not be suitable for all use cases
  }
  public:
    HashTable(int size = 5) : tableSize(size), currentSize(0) {
        // Initialize the hash table with null pointers
        table = new Node*[tableSize];

        for (int i = 0; i < tableSize; i++) {
            table[i] = nullptr;
        }
    }

    void rehash(){
      Node **oldTable = table; // Store the old table
      int oldTableSize = tableSize;
      tableSize *= 2; // Double the size of the table
      currentSize = 0; // Reset current size for rehashing
      table = new Node*[tableSize]; // Create a new table with the new size
      for (int i = 0; i < tableSize; i++) {
        table[i] = nullptr;
      }
      // copy old table to new table
      for (int i = 0; i < oldTableSize; i++) {
        Node* temp = oldTable[i];
        while(temp != nullptr) {
          insert(temp->key, temp->value); // Reinsert the old nodes into the new table
          temp = temp->next; // Move to the next node in the linked list
        }
        // Clean up the old nodes to prevent memory leaks
        // This is important to avoid memory leaks when rehashing
        if(oldTable[i] != nullptr) {
          delete oldTable[i]; // Delete the old node to prevent memory leak
        }
      }
      // Delete the old table
      
      delete[] oldTable; // Delete the old table array
    }

    void insert(string key, int value){
      int idx = hashFunction(key);
      Node* newNode = new Node(key, value);
      newNode->next = table[idx];
      table[idx] = newNode; // Insert the new node at the head of the linked list
      currentSize++;

      // Check if rehashing is needed
      double lamda = currentSize/ tableSize;
      if(lamda>1){
        rehash(); // timeComplexity: O(n) for rehashing
        cout << "Rehashing performed. New table size: " << tableSize << endl;
      }
    }

    void remove(string key){
      int idx = hashFunction(key);
      Node* temp = table[idx];
      Node* prev = nullptr;
      while(temp!=nullptr){

        if(temp->key == key){

          if(prev == nullptr) {
            // If the node to be deleted is the first node in the linked list
            table[idx] = temp->next; // Update the head of the linked list
          } else {
            // If the node to be deleted is not the first node
            prev->next = temp->next;
          }
          temp->next = nullptr;
          delete temp;
          currentSize--; 
          return; 
        }
        prev = temp;
        temp = temp->next;
      }

    }

    // Search for a key and return its value
    // If the key is not found, return -1 or some indication of failure

    bool exists(string key){
      int idx = hashFunction(key);
      Node* temp = table[idx];
      while(temp != nullptr) {

        if(temp->key == key) {
          return true; // Key found
        }
        temp = temp->next; // Move to the next node in the linked list
      }
      return false; // Key not found
    }

    int search(string key){

      int idx = hashFunction(key);
      Node* temp = table[idx];
      while(temp != nullptr) {
        if(temp->key == key) {
          return temp->value; // Key found, return its value
        }
        temp = temp->next; // Move to the next node in the linked list
      }
      return -1; // Key not found, return -1 or some indication of failure
    }

    void print(){
      for (int i = 0; i < tableSize; i++) {
        Node* temp = table[i];
        cout << "Index " << i << ": ";
        while(temp != nullptr) {
          cout << "[" << temp->key << ": " << temp->value << "] -> ";
          temp = temp->next; // Move to the next node in the linked list
        }
        cout << "nullptr" << endl; // End of the linked list
      
      }
    }
};


int main(){

    HashTable ht; // Create a hash table of size 10

    // insert some more elements
    ht.insert("USA", 1000);
    ht.insert("India", 150);
    ht.insert("Bangladesh", 2000);
    ht.insert("China", 500);
    ht.insert("Japan", 300);
    ht.insert("Germany", 400);
    ht.insert("France", 600);
    ht.insert("Italy", 700);
    ht.insert("Spain", 800);
    ht.insert("Brazil", 900);
    ht.insert("Russia", 1100);

    ht.print(); // Print the contents of the hash table
    ht.remove("India"); // Remove the key "India"
    cout << "After removing 'India':" << endl;
    ht.print(); // Print the contents of the hash table after removal

  return 0;
}