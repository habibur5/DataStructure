#include <bits/stdc++.h>
using namespace std;

void insert(vector<int>&v){
    int size = v.size();

    for(int i = 1; i<size; i++){
        
        int j = i-1;
        int key = v[i];
        while(j>=0 && v[j]> key){
            swap(v[j], v[j+1]);
            j--;
        }
        
    }
}
int main(){

    vector<int>v = {42, 1,32, 23};
    insert(v);
    for(auto &it:v) cout<<it<<" ";
    
    return 0;
}