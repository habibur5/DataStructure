#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> v){
  int n= v.size();
  vector<int> ans(n);
  stack<int> st;

  for(int i = 0; i<n; i++){
    while(!st.empty() && v[i] > v[st.top()]){
      ans[st.top()] = v[i];
      st.pop();
      
    }
    st.push(i);
  }
  
  while (!st.empty())
  {
    ans[st.top()] = -1;
    st.pop();
  }

  return ans;
  
}

vector<int> NGE2(vector<int> &v){
  int n = v.size();
  vector<int> nge(n);
  stack<int> st;
  nge[n-1] = -1;
  st.push(v[n-1]);
  for(int i = n-2; i>=0; i--){
    int current = v[i];
    while(!st.empty() && current >= st.top()){
      st.pop();
    }
    if(st.empty()){
      nge[i] = -1;
    }else{
      nge[i] = st.top();
    }
    st.push(current);
    
  }
  return nge;

}
int main(){
  vector<int> v = {8,6,4,1,2,3,0,7,8,9};
  vector<int> res = NGE2(v);

  for(int it : res) cout<< it<<" ";

  return 0;
}