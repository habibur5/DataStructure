#include <bits/stdc++.h>
using namespace std;
/* 
* leet code : 121. Best Time to Buy and Sell Stock
* https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/
void maxProfit(int *prices, int n){
    // int bestBuy[n]; //! it does not support in leet code
    int bestBuy[100000];
    bestBuy[0] = INT_MAX;

    // take time o(n)
    for(int i = 1; i<n; i++){
        bestBuy[i] = min(bestBuy[i-1], prices[i-1]);
    }
    int maxProfit = 0;

    // take time o(n)
    for(int i = 0; i<n; i++){
        int currentProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currentProfit);
    } 

    cout<<maxProfit<<endl;

}
int main(){
    int prices[6] = {7,1,5,3,6,4};

    int n = 6;
    maxProfit(prices, n);
    return 0;
}

// total time T = o(n)+o(n) = o(2n) = o(n)