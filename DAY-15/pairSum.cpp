#include <bits/stdc++.h>
using namespace std;
/* leetCode 167. Two Sum II - Input array is sorted
*  https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/ */
vector<int> pairSum(vector<int> *vec, int *target){
    int st = 0, end = (*vec).size()-1;
    int currentSum = 0;
    vector<int> ans;
    while(st<end){
        currentSum = (*vec)[st]+ (*vec)[end];
        if(currentSum == *target) {
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }else if(currentSum > *target) end--;
        else st++;
    }
    return ans;
}
int main(){
    
    vector<int> vec = {2,7,11,15};
    int target = 18;
    vector<int> res = pairSum(&vec,&target);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}