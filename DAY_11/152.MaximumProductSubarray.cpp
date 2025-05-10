#include <bits/stdc++.h>
using namespace std;

int maxProducts(vector<int>& nums) {
        int maxi = INT_MIN;
        int prod=1;
        for(int i=0;i<nums.size();i++)
        {
            prod*=nums[i];
            maxi=max(prod,maxi);
            cout<<maxi<<" ";
            if(prod==0)
            prod=1;
        }
        cout<<endl;
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            prod*=nums[i];

            maxi=max(prod,maxi);
            if(prod==0) prod=1;
            cout<<maxi<<" ";
        }
        cout<<endl;
        return maxi;
    } 

int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> minDp(n);
        vector<int> maxDp(n);
        minDp[0] = nums[0];
        maxDp[0] = nums[0];
        int res = maxDp[0]; 

        for(int i = 1; i < n; i++){
            if(nums[i] >= 0){
                minDp[i] = min(minDp[i - 1] * nums[i], nums[i]);
                maxDp[i] = max(maxDp[i - 1] * nums[i], nums[i]);
            }else{
                minDp[i] = min(maxDp[i - 1] * nums[i], nums[i]);
                maxDp[i] = max(minDp[i - 1] * nums[i], nums[i]);
            }
            res = max(res, maxDp[i]);
        }
        for(auto min: minDp) cout<<min<<" ";
        cout<<endl;
        for (auto max : maxDp) cout<<max<<" ";
        cout<<endl;
        return res;
    }
int main(){
    vector<int> v = {2,3,-2,4};
    cout<<maxProduct(v)<<endl;
    return 0;
}