#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                long long sum = nums[i] + nums[j];
                if (sum >= lower && sum <= upper)
                    ans++;
            }
        }

        return ans;
    }
};