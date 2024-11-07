#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxCount = 0;

        for (int bit = 0; bit < 32; ++bit) {
            int count = 0;
            for (int num : candidates) {
                if (num & (1 << bit)) { // Check if `bit` is set in `num`
                    count++;
                }
            }
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
