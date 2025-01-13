#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int ans = n;

        unordered_map<char, set<int>> mppAheadIndex;
        unordered_map<char, set<int>> mppBeforeIndex;

        for (int i = 0; i < n; i++) {
            mppAheadIndex[s[i]].insert(i);
            mppBeforeIndex[s[i]].insert(-i);
        } 

        for (int i = 1; i < n - 1; i++) {
            if (s[i] != '*') {
                auto itAhead = mppAheadIndex[s[i]].upper_bound(i);
                auto itPrefix = mppBeforeIndex[s[i]].upper_bound(-i);

                int aheadValue = (itAhead != mppAheadIndex[s[i]].end()) ? *itAhead : -1;
                int prefixValue = (itPrefix != mppBeforeIndex[s[i]].end()) ? -*itPrefix : -1;

                if (aheadValue != -1 && prefixValue != -1) {
                    s[aheadValue] = '*';
                    s[prefixValue] = '*';
                    ans -= 2;

                    // Update the data structures to reflect changes
                    mppAheadIndex[s[i]].erase(aheadValue);
                    mppBeforeIndex[s[i]].erase(-prefixValue);
                }
            }
        }

        return ans;
    }
};
