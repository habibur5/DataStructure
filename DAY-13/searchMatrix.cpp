#include <bits/stdc++.h>
using namespace std;
/* 
* LeeCode 74. Search a 2D Matrix
* https://leetcode.com/problems/search-a-2d-matrix/
*/

/* 
* home work
* Burite force Method
* Binrary Search
* Strier Search Use other conners
*/
/// time o(n+m);
bool StrierSearch(int matrix[][4], int n, int m, int key){
    int i = 0, j = m-1;
    while(i<n && j>=0){
        if(matrix[i][j]== key){
            cout<<i+1<<" "<<j+1<<endl;
            return true;
        }else if(matrix[i][j]> key){
            // left
            j--;
        }else{
            i++;
        }
    }
    cout<<"key not found"<<endl;
    return false;
}
int main(){
    int matrix[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };
    StrierSearch(matrix, 4, 4, 50);
    return 0;
}