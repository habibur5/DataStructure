#include <bits/stdc++.h>
using namespace std;
void merge(int v[], int start, int mid, int end){
    vector<int> temp;

    int i = start;
    int j = mid+1;

    while(i<= mid && j<=end){
        if(v[i]<= v[j]){
            temp.push_back(v[i++]);
        }else{
            temp.push_back(v[j++]);
        }
    }

    while(i<= mid)  temp.push_back(v[i++]);
    while(j<= end)  temp.push_back(v[j++]);

    for(int i = start, x = 0; i<=end; i++){
        v[i] = temp[x++];
    }

}
void divide(int v[], int start, int end){
    if(start>=end) return;
    int mid = start+(end-start)/2;
    cout<<"start = "<<start<<" mid = "<<mid<<endl;
    divide(v, start, mid);
    cout<<"mid = "<<mid<<" end = "<<end<<endl;
    divide(v, mid+1, end);
    
    cout<<"start = "<<start<<" mid = "<<mid<<" end = "<<end<<endl;
    merge(v, start, mid, end);

}
int main(){
    
    int v[]= {4,3,2,1};
    int n = 4;
    divide(v,0, n-1);

    for(auto it:v) cout<<it<<" ";
    return 0;
}