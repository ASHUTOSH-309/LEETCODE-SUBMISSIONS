#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int Max=0;
        int n=s.size();

        for(int i=0;i<n;i++){
           vector<int> charCountTracker(256,0);
           // string temp="";
            for(int j=i;j<n;j++){

                    if(charCountTracker[s[j]]==1) break;
                    
                    if(j-i+1>Max) Max=j-i+1;
                    charCountTracker[s[j]]=1;

            }

        }
        return Max;
        
    }
};