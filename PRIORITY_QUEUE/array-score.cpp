#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        long long score = 0;
      

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < nums.size(); i++)
            pq.push({nums[i], i});

        vector<bool> visited(nums.size(), false);

        while (!pq.empty()) {
            auto ele = pq.top();
            int num = ele.first;
            int index = ele.second;
            bool flag = false;
            if (!visited[index]) {
                flag = true; // flag will determine whether the element is
                             // visited or not
                score += num;
            }

            pq.pop();

            if (flag) {
                if (index > 0 && index < nums.size()) {
                    // this is an intermediate index, not the first or last
                    // index
                    visited[index - 1] = true;
                    visited[index + 1] = true;
                } else if (index == 0) {
                    visited[index + 1] = true;
                } else {
                    visited[index - 1] = true;
                }
            }

            if (flag)
                visited[index] = true;
        }

        return score;
    }
};