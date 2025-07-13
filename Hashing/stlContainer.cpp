#include <bits/stdc++.h>
using namespace std;
int main(){

  /*---------------------
    | Home Work         |
    |-------------------|
    |Red Black Tree     |
    ---------------------

  */
  // Unordered set, unordered map, and unordered multiset

  // map
  unordered_map<string, int> m;
  m["china"] = 70;
  m["india"] = 80;
  m["usa"] = 90;


  for(auto it : m){
    cout<<it.first<<" "<<it.second<<endl;
  }

  if(m.count("china")){
    cout<<"china is present"<<endl;
  }
  else{
    cout<<"china is not present"<<endl;
  }

  return 0;
}