#include <bits/stdc++.h>
using namespace std;
void sprialMatrix(int arr[][4], int row, int col){
    int srow = 0, scol = 0;
    int erow = row-1, ecol = col-1;

        while(erow>=srow && ecol>= scol){
            // top row
            for(int j = scol; j<=ecol; j++){
                cout<<arr[srow][j]<<" ";
            }
            // right column
            for(int i = srow+1; i<=erow; i++){
                cout<<arr[i][ecol]<<" ";
            }

            // last row 
            for(int j = ecol-1; j>= scol; j--){
                if(srow == erow) break;
                cout<< arr[erow][j]<<" ";
            }
            // first column
            for(int i = erow-1; i>= srow+1; i--){
                if(scol == ecol) break;
                cout<<arr[i][scol]<<" ";
            }
            
            srow++, erow--;
            scol++, ecol--;
        }

}

int main(){
    int matrix[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    sprialMatrix(matrix, 4,4);
    return 0;
}