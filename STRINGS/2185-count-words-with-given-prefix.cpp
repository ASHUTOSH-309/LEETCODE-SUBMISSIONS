#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(int i=0;i<words.size();i++){
                string str=words[i];
                if(words[i].size()>=pref.size()){
                    if(str.substr(0,pref.size())==pref) ans++;
                }

        }
        return ans;        
    }
};