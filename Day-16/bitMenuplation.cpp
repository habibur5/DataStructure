#include <bits/stdc++.h>
using namespace std;
bool oddOrEven(int *n){
    if((*n&1)) return false;
    else return true;
}

int getIthBit(int num, int i){
    int bitMask = 1<<i ;
    if(!(num & bitMask)) return 0;
    else return 1;
}
int setIthBit(int num, int i){
    int bitMask = 1<<i; /// 000100..
    return (num | bitMask);
}

int clearIthBit(int num, int i){
    int bitMusk = ~(1<<i);  /// 111011..
    return (num & bitMusk);
}

bool isPowerOf2(int num){
    if(!(num & (num-1))) return true;
    else return false;
}

int countSetBits(int num){
    int count = 0;
    while(num>0){
        int last_digit = num & 1;
        count+=last_digit;
        num>>=1;
    }
    return count;
}

void fastExpo(int x, int n){
    int ans = 1;
    while(n>0){
        int lastBit = n&1;
        if(lastBit){
            ans = ans*x;
        }
        x =  x*x;
        n=n>>1;
    }
    cout<<ans<<endl;
}



int main(){
/* Bitwise and 1 & 1 =1 other wise 0
            or  0|0 = 0 other wise 1
            xor ^ same  = 0
            Xnor  same = 1
*/
    // OR OR EVEN
    /* 
    int num= 111;
    if(oddOrEven(&num))         
        cout<<num<<" is positive"<<endl;
    else cout<<num<< " is negative"<<endl;


    /// Get ith bit
      
    cout<<getIthBit(7,1)<<endl; // 
    cout<<setIthBit(5,2)<<endl;
    cout<<clearIthBit(6,1)<<endl; // 4

    cout<<isPowerOf2(4)<<endl;
    cout<<isPowerOf2(3)<<endl;

    cout<<countSetBits(15)<<endl;

    */
    
    fastExpo(5,3);
    return 0;
}