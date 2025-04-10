/* 
Print all Binary Strings of size N without any consecutive 1s.
platform: paytm
 */
#include <bits/stdc++.h>
using namespace std;
void f(int n, int lastPlace, string ans){
    if(n==0) {
        cout<<ans<<endl;
        return;
    }
    if(lastPlace!=1){
        f(n-1, 0, ans+'0');
        f(n-1, 1, ans+'1');
    }else{
        f(n-1, 0, ans+'0');
    }
}

void f2(int n, string ans){
    if(n==0) {
        cout<<ans<<endl;
        return;
    }
    if(ans[ans.size()]!=1){
        f(n-1, 0, ans+'0');
        f(n-1, 1, ans+'1');
    }else{
        f(n-1, 0, ans+'0');
    }
}


int main(){
    string ans="";
    f2(3,ans);
    return 0;
}