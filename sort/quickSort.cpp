#include <bits/stdc++.h>
using namespace std;
int partition(vector<int>&v, int start, int end){

    int idx = start, pivot = v[end];
    for(int i = start; i<end; i++){
        if(v[i] <= pivot){
            swap(v[i], v[idx]);
            idx++;
        }
    }

    swap(v[end], v[idx]);

    return idx;
}

void quickSort(vector<int> &v, int start, int end){

        if(start<end){
            int pv = partition( v,start, end);
            quickSort(v,start, pv-1);
            quickSort(v, pv+1, end);
        }
        
    
}
int main(){
    vector<int> v = {6,5,4,3,2,1};

    quickSort(v,0, v.size()-1);
    for(auto &it:v){
        cout<<it<<" ";
    }
    return 0;
}