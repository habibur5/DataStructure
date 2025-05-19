#include <bits/stdc++.h>
using namespace std;
/* when we use counting sort we need to know the range of the elements
   so we can use counting sort when the range of the elements is small
   and we can use counting sort when the range of the elements is large
   but the number of elements is small
   so we can use counting sort when the range of the elements is small
   and we can use counting sort when the range of the elements is large
   but the number of elements is small
   so we can use counting sort when the range of the elements is small
   and we can use counting sort when the range of the elements is large
   but the number of elements is small
 */

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
        output [--count[v[i]]] = v[i];
    }
    return output;
}
int main(){
    vector<int> v= {1,5 ,6,1,5};

    vector<int> res = countSort(v,5,6);

    for(auto &it:res){
        cout<<it<<" ";
    }
    return 0;
}

// o(n)+o(n)+0(n)+o(n)+o(max)

// O(n+max) time complexity