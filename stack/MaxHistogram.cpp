#include <bits/stdc++.h>
using namespace std;
void NSER(vector<int> &v){

  int sz= v.size();
  stack<int>st;
  vector<int> nsl(sz);
  vector<int> nsr(sz);

/*   nsl[0] = -1;
  st.push(0); */
  for(int i = 0; i<sz; i++){
    int cele = v[i];
    while(!st.empty() && cele <= v[st.top()]){
      st.pop();
    }

    if(st.empty()){
      nsl[i] = -1;
    }else{
      nsl[i] = v[st.top()]; 
    }
    
    st.push(i);
  }

  while(!st.empty()){
    st.pop();
  }

/*   st.push(sz-1);
  nsr[sz-1] = sz; */
  for(int i = sz-1; i>=0; i--){
    while(!st.empty() && v[i] <= v[st.top()]){
      st.pop();
    }
    if(st.empty()){
      nsr[i] = sz;
    }else{
      nsr[i] = st.top();
    }
    st.push(i);
  }

  int mx = INT_MIN;
  for(int i = 0; i<sz; i++){
    int area = v[i] * (nsr[i]-nsl[i]-1);
    mx = max(mx,area);
  }

  cout<<mx<<endl;
}



int main(){
  vector<int> v = {2,1,5,6,2,3};
  NSER(v);
  return 0;
}