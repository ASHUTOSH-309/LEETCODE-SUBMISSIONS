#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        map<int, int> mpp;

        int minimumAmongIntervals = INT_MAX;
        int maximumAmongIntervals = INT_MIN;
        for (int i = 0; i < intervals.size(); i++) {
            mpp[intervals[i][0]] = intervals[i][1];
            minimumAmongIntervals = min(minimumAmongIntervals, intervals[i][0]);
            maximumAmongIntervals = max(maximumAmongIntervals, intervals[i][1]);
        }

        int globalCount = INT_MIN;
        for (int i = minimumAmongIntervals; i <= maximumAmongIntervals; i++) {

            int localCount = 0;
            for (auto it : mpp) {
                if (it.first <= i && it.second >= i) {
                    localCount++;
                }
            }
            globalCount = max(globalCount, localCount);
        }

        return globalCount;
    }
};