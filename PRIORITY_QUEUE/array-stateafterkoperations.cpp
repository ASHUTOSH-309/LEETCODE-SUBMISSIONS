#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int> ans(nums.size());

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        for (int i = 0; i < nums.size(); i++) {
            int number = nums[i];
            pq.push({number, i});
        }

        for (int i = 0; i < k; i++) {

            int mini = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            nums[index] = nums[index] * multiplier;
            pq.push({nums[index], index});
        }

        while (!pq.empty()) {

            int ele = pq.top().first;
            int index = pq.top().second;
            ans[index] = ele;
            pq.pop();
        }

        return ans;
    }
};