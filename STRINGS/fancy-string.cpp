#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {

        string ans;

        if(s.size()<3) return s;

        for(int i=0;i<=s.size()-3 && s.size()>=3;i++){

            if(s[i]==s[i+1] && s[i]==s[i+2]){
                    s.erase(i,1);
            i--;
            }

        }

        ans=s;
        return ans;
        
    }
};