#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int ans = 0;
        
        unordered_map<char,long long> mpp;
        for(int i=0;i<n;i++) mpp[s[i]]++;


        for(auto it:mpp){
            if(it.second%2==0) ans+=2;
            else ans+=1;
        }
        
        return ans;
    }
};
