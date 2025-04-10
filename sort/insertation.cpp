#include <bits/stdc++.h>
using namespace std;
/* 
time : wrost = n^2
 */

void printArray(int data[],int size){
    for(int i = 0; i< size; i++){
        cout<<data[i]<<endl;
    }
    cout<<endl;
}
void insertionSort(int data[], int size){
    for(int i = 1; i<size; i++){
        int key = data[i];
        int j = i-1;

        while( j >=0 && key < data[j]){
            data[j+1] = data[j];
            --j;
        }
        data[j+1] = i;
    }
}

int main(){
    int data[] = {9, 5, 1, 4, 3};
    int size = sizeof(data) / sizeof(data[0]);
    insertionSort(data, size);
    cout << "Sorted array in ascending order:\n";
    printArray(data, size);

    return 0;
}