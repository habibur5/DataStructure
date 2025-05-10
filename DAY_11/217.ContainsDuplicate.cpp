#include <bits/stdc++.h>
using namespace std;
/* 
    you can solve this different types of method
    1. loop in loop time n^2
    2. sorted nethod time nlogn
    3. unorder method
*/
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        /* unordered_set<int> elems;
        for (auto iter : nums)
        {
           if (elems.contains(iter)) // cpp -v 20+
                return true;
            
            elems.insert(iter);
            cout<<iter<<endl;
        }
        
        return false; */
        for (int i:nums) {
            if(seen.count(i) >0) return true;
            else seen.insert(i);
        }
        return false;
    }
int main(){
    vector<int> v = {1,1,1,3,3,4,3,2,4,2};
    containsDuplicate(v);
    return 0;
}

/* 
    show runtime is 0:  auto init = atexit([]() { ofstream("display_runtime.txt") << "0";});
*/