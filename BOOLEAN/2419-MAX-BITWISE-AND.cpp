#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int size = nums.size();
        long long maxi = 0;
        long long max_length = 0;

        vector<pair<int, int>> temp;
        for (int i = 0; i < size; i++)
        {
            long long length = 0;
            int bitwiseResult = nums[i];
            for (int j = i; j < size; j++)
            {
                bitwiseResult = bitwiseResult & nums[j];
                length = j - i + 1;
                if (bitwiseResult == 0)
                    break;
                if (bitwiseResult > maxi)
                {
                    maxi = bitwiseResult;
                    max_length = length;
                }
                else if (bitwiseResult == maxi)
                {
                    if (length > max_length)
                        max_length = length;
                }
            }
        }
        return max_length;
    }
};

// 40 out of 51 test cases passed, need to be optimized