#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>&v, int start, int end){
    int idx= start, pvoit = v[end];

    for(int i = start; i<=end; i++){
        if(v[i]<= pvoit){
            swap(v[i], v[idx]);
            idx++;
        }
    }
    swap(pvoit, v[idx]);
    return idx;
}


int randPovit(vector<int> &v, int start, int end){
    srand(time(0));
    int randPvoitIdx = start+ rand() % (end-start);
    swap(v[randPvoitIdx], v[end]);
    return partition(v,start, end);
}
void quickSort(vector<int>&v, int start, int end){
    if(start>=end) return;

    int pvoitIdx = randPovit(v,start,end);

    quickSort(v, start, pvoitIdx-1);
    quickSort(v, pvoitIdx+1, end);
    
}
int main(){
    vector<int> v = {10,45,89,78,92,1,66,88};
    quickSort(v,0,v.size()-1);

    for(auto &it:v){
        cout<<it<<" ";
    }
}