#include <bits/stdc++.h>
using namespace std;

void func(int mat[][4], int n, int m){
    cout<< "0th row ptr "<< mat<<endl;             
    cout<< "1st row ptr "<< (mat+1)<< endl;             
    cout<< "2nd row ptr "<< (mat+2)<< endl;

    cout<< "0th row ptr "<< *mat<<endl;             
    cout<< "1st row ptr "<< *(mat+1)<< endl;             
    cout<< "2nd row 2 pos value  "<< *(*(mat+2)+2)<< endl;             
}
void func2(int (*mat)[4], int n , int m){

}
int main(){
    int mat[4][4] = {
        { 1, 2, 3, 4},
        { 5, 6, 7, 8},
        { 9, 10, 11, 12},
        { 13, 14, 15, 16}
    };
    /* 2D Array names behaves as a row pointer. its point full row */
    /* cout<< mat<<" != "<< mat+1<<endl;
    cout<< mat<<" = "<< &mat[0][0]<<endl;
    cout<< mat+1<<" != "<< &mat[0][1]<<endl; */


    func(mat, 4,4);     
    func2(mat, 4,4);     
    return 0;
}