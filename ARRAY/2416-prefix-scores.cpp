#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution {
public:
    int ReturnPrefixMatchingCount(string prefix, vector<string>& words) {
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {

            if (words[i].size() >= prefix.size()) {
                if (words[i].substr(0, prefix.size()) == prefix)
                    ans++;
            }
        }
        return ans;
    }

    vector<int> sumPrefixScores(vector<string>& words) {

        vector<int> ans;
        int n = words.size();

        for (int i = 0; i < words.size(); i++) {
            long long count = 0;
            for (int j = 0; j < words[i].size(); j++) {
                count += ReturnPrefixMatchingCount(
                    words[i].substr(0, j + 1), words);
            }
            ans.push_back(count);
        }

        return ans;
    }
};