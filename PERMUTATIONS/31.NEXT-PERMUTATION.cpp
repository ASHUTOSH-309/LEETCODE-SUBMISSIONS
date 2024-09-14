
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        long long i = nums.size() - 1;

        /* 
    
        while (nums[i - 1] >= nums[i] && i >= 1)
            i--;
        while ( nums[findsmallestgreater] > nums[i]  &&  findsmallestgreater <= nums.size() - 1 )
            findsmallestgreater++;

            These two would result in a runtime error, very important to consider the usage order
         */

        if (i == 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }

        i--;
        long long findsmallestgreater = i + 1;
        while (findsmallestgreater <= nums.size() - 1 && nums[findsmallestgreater] > nums[i])
            findsmallestgreater++;

        findsmallestgreater--;

        swap(nums[findsmallestgreater], nums[i]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};
