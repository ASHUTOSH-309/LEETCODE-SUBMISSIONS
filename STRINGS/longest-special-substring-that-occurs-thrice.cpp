#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maximumLength(string s) {
        int ans = -1;

        unordered_map<string, int> mpp;

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if(s[i]!=s[j]) break;
                mpp[s.substr(i,j-i+1)]++;
                //if(s[j]!=s[j-1]) break;
            }
        }


        for(auto it: mpp){
            cout<<it.first<<" "<<it.second<<endl;

            if(it.second>=3){
                int stringLength=it.first.size();
                ans=max(ans,stringLength );
            }
        }

        return ans;
    }
};