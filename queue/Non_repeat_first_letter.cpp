#include <bits/stdc++.h>
using namespace std;
void nonRepeat(string &s){
  int sz = s.size();
  queue<char> q;
  int frq[26] = {0};
  
  for(int i= 0; i< sz; i++){
    char curr = s[i];
    ++frq[curr-'a'];
    q.push(curr);

    while(frq[q.front()-'a']>1 && !q.empty()){
      q.pop();
    }
    if(q.empty()){
      cout<<-1<<endl;
    }else cout<<q.front()<<endl;
  }
}
int main(){
  string s = "aabccxb";
  nonRepeat(s);
  return 0;
}