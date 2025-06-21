#include <bits/stdc++.h>
using namespace std;

int main(){
  list<int> ll;
  ll.push_front(2);
  ll.push_front(1);
  ll.push_back(3);
  ll.push_back(4);
  for(auto it: ll){
    cout<<it<<endl;
  }
  return 0;
}