#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAllwordsThere(map<string, int>& mpp, vector<string>& words,
                          map<string, int> mapWithOriginalOccurances) {

        for (auto it : words) {
            if ((mapWithOriginalOccurances[it] - mpp[it]) != 0)
                return false;
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {

        set<string> WordContainer;
        vector<int> ans;
        map<string, int> mapWithOriginalOccurances;
        for (auto it : words) {
            mapWithOriginalOccurances[it]++;
        }

        int TotalLengthofPermutation = words.size() * words[0].size();

        for (auto it : words) {
            WordContainer.insert(it);
        }

        for (int i = 0, j = i + TotalLengthofPermutation - 1; j < s.size();
             i++, j++) {
            int l = i;
            int found = false;

            map<string, int> mpp;
            for (int k = 0; k < words.size(); k++) {

                if (WordContainer.find(s.substr(l, words[0].size())) !=
                    WordContainer.end()) {
                    found = true;
                    mpp[s.substr(l, words[0].size())]++;
                    l += words[0].size();

                } else {
                    found = false;
                    break;
                }
            }

            if (found == true &&
                areAllwordsThere(mpp, words, mapWithOriginalOccurances)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};