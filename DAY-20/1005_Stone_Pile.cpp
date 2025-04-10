#include <bits/stdc++.h>

using namespace std;

int n;
    
int arr[22] = {5,8,13,27,14};
int sum = 0;
int ans;
int step = 0;

vector<int> res;

void backtrack(int i, int s) {

    res.push_back(s);
    if(i == n) {
        ans = min(ans, abs(sum - s*2));
        return;
    }

    backtrack(i+1, s);
    backtrack(i+1, s+arr[i]);
}


int main() {
    n=5;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    ans = sum;
    backtrack(0, 0);
    cout<<ans<<endl;

    cout<<"step = "<<step<<endl;

    for(auto it: res){
        cout<< it<<" ";
    }
    return 0;
}