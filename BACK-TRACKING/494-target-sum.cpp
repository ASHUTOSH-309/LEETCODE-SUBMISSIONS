#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long count = 0;
    void ReturnWays(int index, vector<int>& nums, int target) {
        if (index == nums.size()) {

            if (target == 0) {
                count++;
                return;
            }
            return;
        }

      //  ds.push_back(nums[index]);
        ReturnWays(index + 1, nums, target - nums[index]);
        //ds.pop_back();
      //  ds.push_back(-1 * nums[index]);
        ReturnWays(index + 1, nums, target + nums[index]);
        //ds.pop_back();
    }

    int findTargetSumWays(vector<int>& nums, int target) {



        ReturnWays(0, nums, target);
        return count;
    }
};