#include <bits/stdc++.h>
using namespace std;
int main(){
    int size;
    cin>>size;
    int *arr = new int[size]; // dynamic memory
    for(int i = 0 ; i<size; i++){
        arr[i] = i;
        cout<<arr[i]<<" ";
    }

    delete [] arr;
    return 0;
}