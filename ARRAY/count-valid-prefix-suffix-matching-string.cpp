#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2) {

        bool ans = false;
        if (str1.size() > str2.size()) return ans;

        int lengthofstr1 = str1.size();
        int lengthofstr2 = str2.size();

        bool isPrefix = str1.substr(0, lengthofstr1) == str2.substr(0, lengthofstr1);
        // Now reverse str2 and check the same
        reverse(str2.begin(), str2.end());
        reverse(str1.begin(), str1.end());
        bool isSuffix = str1.substr(0, lengthofstr1) == str2.substr(0, lengthofstr1);

        return isPrefix && isSuffix;
    }

    int countPrefixSuffixPairs(vector<string>& words) {

        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i+1; j < words.size(); j++) {
                if(isPrefixAndSuffix(words[i],words[j])) ans++;
            }
        }

        return ans;
    }
};