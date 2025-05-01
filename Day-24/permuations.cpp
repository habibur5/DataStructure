#include <bits/stdc++.h>
using namespace std;

void permutations(string str, string ans){
    int n = str.length();
    if(n == 0){
        cout << ans << endl;
        return;
    }
    for(int i = 0; i<str.length(); i++){
        if(i != 0 && str[i] == str[i-1]) continue; 
        char ch = str[i];
        string ros = str.substr(0, i) + str.substr(i+1); 
        permutations(ros, ans + ch);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s = "abc";
    string ans;
    permutations(s, ans);
    return 0;
}