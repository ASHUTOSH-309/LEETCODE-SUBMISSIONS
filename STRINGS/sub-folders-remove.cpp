#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool existsAsLeadingSubstring(string s1, string s2) {
        // will check if s1 has s2 as the substring
        if(s1.size()<s2.size()) return false;

        for(int i=0;i<s2.size();i++){
            if(s1[i]!=s2[i]){
                return false;
            }
            if(s1.size()>s2.size() && i==s2.size()-1 && s1[i+1]!='/'){
                return false;
            }
        }
        return true;
    }

    vector<string> removeSubfolders(vector<string>& folder) {

        vector<string> ans;
        sort(folder.begin(), folder.end());
        if (folder[0] == "/") {
            ans.push_back(folder[0]);
            return ans;
        }

        string startFolder = folder[0];

        for (int i = 0; i < folder.size(); i++) {
            if (i == 0) {
                ans.push_back(folder[0]);
                continue;
            }
            if (!existsAsLeadingSubstring(folder[i], startFolder)) {
                ans.push_back(folder[i]);
                startFolder=folder[i];
            }
        }

        return ans;
    }
};