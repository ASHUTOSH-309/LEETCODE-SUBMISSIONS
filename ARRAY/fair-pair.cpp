#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& v, int lower, int upper) {
        long long ans = 0;
        sort(v.begin(), v.end());  // Step 1

        for (int i = 0; i < v.size() - 1; i++) {  // Step 2
            auto up = upper_bound(v.begin() + i + 1, v.end(), upper - v[i]);  // Step 3
            auto low = lower_bound(v.begin() + i + 1, v.end(), lower - v[i]);  // Step 4
            ans += (up - low);  // Step 5
        }
        return ans;
    }
};
