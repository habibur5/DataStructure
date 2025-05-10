#include <bits/stdc++.h>
using namespace std;
int binTodec(int bin){
    int p = 1;
    int dec = 0;

    while(bin >0){
        dec+=p*(bin%10);
        bin/=10;
        p*=2;
    }

    return dec;
}

int decTobin(int dec){
    int p = 1;
    int bin  = 0;

    while(dec>0){
        bin+=p*(dec%2);
        dec/=2;
        p*=10;
    }
    return bin;
}

int main(){
    cout<<binTodec(111111)<<endl;
    cout<<decTobin(63)<<endl;
    return 0;
}