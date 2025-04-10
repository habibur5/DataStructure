#include <bits/stdc++.h>
using namespace std;
int main(){
    int row, col;
    cin>> row>>col;
    int **matrix = new int*[row];

    for(int i = 0; i<row; i++){
        matrix[i] = new int[col];
    }

    //! matrix[i][j] = *(*(matrix+i)+j) for 2d array

    // data store
    int x = 1;
    for(int i = 0; i<row; i++)
        for(int j = 0; j<col; j++){
            //  *(*(matrix+i)+j) = x++;
            matrix[i][j] = x++;

            cout<<matrix[i][j]<<" ";
            
        }
    cout<<endl;
    cout<<matrix[2][2]<<endl;
    cout<< *(*(matrix+2)+2)<<endl;
    return 0;
}