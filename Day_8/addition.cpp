#include <bits/stdc++.h>
using namespace std;
int decToBin(int num){
    int p = 1;
    int bin = 0;
    while(num>0){
        bin+=p*(num%2);
        p*=10;
        num/=2;
    }
    return bin;
}
int binToDec(int binNum){

}
int binAddition(int n1, int n2) {
    
    return decToBin(binToDec(n1) + binToDec(n2));
}
int main(){
    cout<<binToDec(binAddition(11,11))<<endl;
    return 0;
}