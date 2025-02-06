#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {

        //   int ans=0;
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++){
                mpp[nums[i] * nums[j]]++;
            }
        }


        long long ans = 0;

        for (auto it : mpp)
        {
            int freq = it.second;
            if (it.second > 1)
            {
                // from 2 pairs 8 unique permutations can be generated which wiil satisfy the tuple
                // property
                ans += (freq * (freq - 1)) * 4;
            }
        }

        return ans;
    }
};