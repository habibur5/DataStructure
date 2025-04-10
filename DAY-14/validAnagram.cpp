#include <bits/stdc++.h>
using namespace std;

/* 
LeetCode 242. Valid Anagram
https://leetcode.com/problems/valid-anagram/
*/
bool isAnagram(string str1, string str2){
    if(str1.length() != str2.length()){
        return false;
    }
    int count[26] = {0};
    for(int i = 0; i<str1.length(); i++){
        count[str1[i]- 'a']++;
    }
    for(int i = 0; i<str2.length(); i++){
        int idx = str2[i]-'a';
        if(count[idx] == 0 ){
            return false;
        }
        count[idx]--;
    }
    return true;

}
int main(){
    string str1 = "aacc";
    string str2 = "ccac";
    if(isAnagram(str1, str2)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}