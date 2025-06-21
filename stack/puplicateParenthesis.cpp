/**
** Given a balanced expression that can contain opening and closing parenthesis, check if it
** contains any duplicate parenthesis or not.
Input: ((x+y))+z
Output: true
Explanation: Duplicate () found in subexpression ((X+Y))
Input: (X+Y)
Output: false
Explanation: No duplicate () is found
Input: ((x+Y)+((z)))
Output: true
Explanation: Duplicate () found in subexpression ((z)) */

#include <bits/stdc++.h>
using namespace std;
bool isDuplicate(string &s){
  stack<char> st;
  for(int i = 0; i<s.size(); i++){
    char ch = s[i];
    if(ch!=')'){
      st.push(s[i]);
    }else{
      if(st.top() == '(') return true;
      while(st.top() != '('){
        st.pop();
      }
      st.pop();
    }
  }
  return false;
}
int main(){
  string str1 = "((a+b))"; // true
  string str2 = "((a+b+d+r/y*t-r+e*s))"; //false

  cout<<isDuplicate(str1)<<endl;
  cout<<isDuplicate(str2)<<endl;
  return 0;
}
