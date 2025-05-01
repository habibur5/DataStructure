#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> res;
bool isSafe(vector<string> &board, int row, int col, int n){
    /// horizontal
    for(int i = row; i>=0; i--){
        if(board[row][i]=='Q') return false;
    }
    // vertical

    for(int i = row; i>=0; i--){
        if(board[i][col] == 'Q') return false;
    }

    // left dional

    for(int i = row, j=col; i>=0 && j>=0; i--,j-- ){
        if(board[i][j] == 'Q') return false;
    }

    // right diogonl
    for(int i = row, j=col; i>=0 && j<n; i--,j++ ){
        if(board[i][j] == 'Q') return false;
    }


    return true;
}
void nQueens(vector<string> &board, int row, int n){
    if(row == n){
        res.push_back(board);
        return;
    }
    for(int i=0; i<n; i++){
        if(isSafe(board,row, i, n)){
            board[row][i] = 'Q';
            nQueens(board, row+1, n);
            board[row][i] = '.';
        }
    }
}


int main(){

    
    int n;
    cin>>n;
    vector <string> board(n,string(n,'.'));
    nQueens(board,0,n);

    for(auto it:res){
        for(auto ele:it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}