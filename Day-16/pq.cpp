#include <bits/stdc++.h>
using namespace std;
int updateIthBit(int num, int i, int val){
    num = num & ~(1<<i); // clear i th bit
    return ( num | (val<<i)); // update bit
}

int clearLastIBits(int num, int i){
    int bitMask = (~0)<<i;
    return (num & bitMask);
}
int main(){
    cout<<updateIthBit(7, 3 ,1)<<endl; // 15
    /// clear last i bits
    cout<<clearLastIBits(7, 1)<<endl;
    return 0;
}