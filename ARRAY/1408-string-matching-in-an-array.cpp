#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isSubstr(string str1, string str2) {
        // Check if str1 is a substring of str2 using the find() function
        return str2.find(str1) != string::npos;
    }

    vector<string> stringMatching(vector<string>& words) {

        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string str = words[i];
            for (int j = 0; j < n; j++) {

                if (j != i && isSubstr(str, words[j])) {
                    ans.push_back(str);
                    break;
                }
            }
        }

        return ans;
    }
};