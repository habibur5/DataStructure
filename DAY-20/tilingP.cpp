/* 
    1. kaj ki
    2. kon smallest problem
    3. base case
    */

    /* 
    every lavel have a  choice
    place:
    1. veritcally place
    2. horizontally place
    */
/* 
problem: filling floor by using tiles
board: 2xN
tile: 2x1

problem : google, amazone

leetCode: 
*/
int tilingProblem(int n){
    if(n==1 || n==0) return 1;
    if(n==2) return 2;

    return tilingProblem(n-1) + tilingProblem(n-2);
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    cout<<tilingProblem(4)<<endl;
    return 0;
}