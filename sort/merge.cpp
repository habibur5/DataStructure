#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &v, int start, int mid, int end){

    vector<int>temp;
    int left = start, right= mid+1;

    while(left<=mid && right<=end){
        if(v[left] <= v[right]){
            temp.push_back(v[left]);
            left++;
        }else{
            temp.push_back(v[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(v[left]);
        left++;
    }
    while(right<=end){
        temp.push_back(v[right]);
        right++;
    }

    for(int i = 0; i< temp.size(); i++){
        v[i+start] = temp[i];
    }

}


void mergeSort(vector<int>&v, int start, int end){
    if(start == end) return;

    int mid = start+(end-start)/2;
    mergeSort(v, start, mid);
    mergeSort(v, mid+1, end);
    merge(v, start, mid, end);

}
int main(){
    vector<int> v  = {5,6,8,7,1,40,60,48,24,7,8,65,45,12,54,35,36,45};
    mergeSort(v,0,v.size()-1);
    for(auto it:v){
        cout<<it<<" ";
    }
    return 0;
}