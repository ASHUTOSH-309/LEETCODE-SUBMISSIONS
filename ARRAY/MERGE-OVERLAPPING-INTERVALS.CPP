#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            // For each pair compare its start with the end of previous

            // ans.back() would give the previous intervals
            vector<int>& prev = ans.back();
            int endTimeofPrevious = prev[1];
            int startofcurrent = intervals[i][0];

            if (startofcurrent <= endTimeofPrevious) {
                prev[1] = max(endTimeofPrevious, intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};