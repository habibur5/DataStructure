#include <bits/stdc++.h>
using namespace std;
// time n^3
void maxSubArrySum1(int *arr,int n){
    int maxSum = INT_MIN;
    for(int start = 0; start<n; start++){
        for(int end = start; end<n; end++){
            int currentSum = 0;
            for(int i = start; i<= end; i++){
                currentSum+=arr[i];
            }
            maxSum = max(maxSum,currentSum);
        }
    }
    cout<<maxSum<<endl;
}

// intermediate optimize
// time n^2
void maxSubArrySum2(int *arr,int n){
    int maxSum = INT_MIN;
    for(int start = 0; start<n; start++){
        int currentSum = 0;
        for(int end = start; end<n; end++){
            currentSum+=arr[end];
            maxSum = max(maxSum,currentSum);
        }
    }
    cout<<maxSum<<endl;
}
// kadans algorithm VVI
void maxSubArrySum3(int *arr,int n){
    int maxSum = INT_MIN;
    int currentSum = 0;
    for(int start = 0; start<n; start++){
        currentSum+=arr[start];
        maxSum = max(maxSum,currentSum);
        if(currentSum<0){
            currentSum = 0;
        }
    }
    cout<<maxSum<<endl;
}


int main(){
    int arr[6] = {2,-3,6,-5,4,2};
    maxSubArrySum3(arr, 6);
    return 0;
}