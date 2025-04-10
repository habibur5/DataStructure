#include <bits/stdc++.h>
using namespace std;

/* 
Platform: Google, Microsoft

*/
void removeDuplicates(string s, string ans, int i, bool map[26]){

    if(i == s.size()) {
        cout<<ans<<endl;
        return;
    }
    char ch = s[i];
    int mapIdx  = ch -'a';

    if(map[mapIdx] == true)
        removeDuplicates(s, ans, i+1, map);
    else{
        map[mapIdx] = true;

        removeDuplicates(s, ans+s[i], i+1, map);
    }
}

void removeDuplicate(string s, string ans, bool map[26]){
    int size = s.size()-1;
    if(size+1 == 0) {
        cout<<ans<<endl;
        return;
    }
    
    char ch = s[size];
    int mapIdx  = ch -'a';
    string sub = s.substr(0, size);
    if(map[mapIdx] == true)

        removeDuplicate(sub, ans, map);
    else{
        map[mapIdx] = true;

        removeDuplicate(sub, ch+ans, map);
    }
}
int main(){
    
    string s = "appnnacolleget"; // string muteable in c++

    string ans = "";
    bool map[26] = {false};

    removeDuplicate(s, ans, map);
    return 0;
}