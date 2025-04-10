#include <bits/stdc++.h>
using namespace std;
/*
* LeetCode 42. Trapping Rain Water
* https://leetcode.com/problems/trapping-rain-water/ 
 */
int trap (int *arr, int n){
    int leftMax[n];
    leftMax[0] = arr[0];
    for(int i = 1; i<n; i++){
        leftMax[i] = max(leftMax[i-1], arr[i-1]);
    }
    cout<<endl;
    int rightMax[n];
    rightMax[n-1] = arr[n-1];
    for(int i = n-2; i>=0; i--){
        rightMax[i] = max(rightMax[i+1], arr[i+1]);
    }
    int trapWater = 0;
    for(int i = 0; i<n; i++){
        int current =min(leftMax[i], rightMax[i])-arr[i];
        if(current>0) trapWater+=current;
    }

    return trapWater;

}
int main(){
    int heights[7] = {4,2,0,6,3,2,5};
    int n = 7;
    int waterTrap = trap(heights, n);
    cout<<waterTrap<<endl;
    return 0;
}