#include <bits/stdc++.h>
using namespace std;

// for 0 based indexing
// index i(present) 
/* 
  leftChild = 2*i+1;
  rightChild = 2*i+2

  parrent =( i-1 )/ 2

*/

// for 1 based indexing
// index i(present) 
/* 
  leftChild = 2*i;
  rightChild = 2*i;

  parrent = i / 2

*/

class Heap{
  vector<int> vec;
  public:
    void push(int val){
      vec.push_back(val);
      int x = vec.size()-1;
      int parI = (x-1)/2;
      while(parI >=0 && vec[x]> vec[parI]){
        swap(vec[parI], vec[x]);
        x= parI;
        parI = (x-1)/2;
      }
    }

    void heapify(int i){
      int largest = i;
      int left = 2*i + 1;
      int right = 2*i + 2;

      if(left < vec.size() && vec[left] > vec[largest]){
        largest = left;
      }
      if(right < vec.size() && vec[right] > vec[largest]){
        largest = right;
      }
      if(largest != i){
        swap(vec[i], vec[largest]);
        heapify(largest);
      }
    }

    void pop(){
      vec[0] = vec[vec.size()-1];
      vec.pop_back();
      heapify(0);


    }

    int top(){
      return vec[0];
    }
    bool empty(){
      return vec.size()==0;
    }
};


int main(){

  // max heap
  Heap heap;
  heap.push(50);
  heap.push(10);
  heap.push(100);
  cout<<heap.top()<<endl;
  heap.pop();
  cout<<heap.top()<<endl;



  return 0;
}