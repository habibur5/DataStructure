#include <bits/stdc++.h>
using namespace std;

vector<int> countSort(vector<int>&v, int n, int maxVal){
    int count[maxVal+1] = {0};

    // store number of frequency or occurence of each number
    for(int i=0; i<n;i++) 
    count[v[i]]++;

    for(int i = 1; i<=maxVal; i++){
        count[i]+=count[i-1];
    }
    vector<int> output(n);
    for(int i = n-1; i>=0; i--){
        output[--count[v[i]]] = v[i];
    }
    return output;
}
int main(){
    vector<int> v= {40,64,51 ,5 ,6, 40, 6 ,4 ,4,11,60};

    vector<int> res = countSort(v,11,64);

    for(auto it:res){
        cout<<it<<" ";
    }
    return 0;
}

// o(n)+o(n)+0(n)+o(n)+o(max)

// O(n+max) time complexity