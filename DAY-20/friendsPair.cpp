/* 
Find total ways in which n friends can be paired up.
Each friend can only be paired once.
 */

/*
threre is twist in this case

Goldman Sachs
 */

#include <bits/stdc++.h>
using namespace std;

int f(int n){
    if(n==1 || n==2) return n;

    return f(n-1)+f(n-2);
}
int main(){
    cout<<f(10)<<endl;
    return 0;
}