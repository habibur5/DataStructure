#include <bits/stdc++.h>
using namespace std;

void binToDec(int binNum){
    int n = binNum;
    int dec = 0;
    int p = 1;

    while(n>0){
        int lastDig = n%10;
        dec+=lastDig*p;
        p*=2;
        n/=10;
    }
    cout<<dec<<endl;
}

void decToBin(int dec){
    int n = dec;
    int pow = 1;
    int bin = 0;
    while(n>0){
        int rem  = n%2;
        bin+= rem*pow;
        n/=2;
        pow*=10;
    }
    cout<<bin<<endl;
}
int main(){
    decToBin(10);
    return 0;
}