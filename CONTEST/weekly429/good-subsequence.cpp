#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    void generateValidSubsequence(int index, vector<int>& nums,vector<int>& temp,long long& count) {

        if (temp.size() > 4) return;

        if (index == nums.size()) {
            // Entire array has been traversed
            if (temp.size() == 4) {
                int p = temp[0];
                int q = temp[1];
                int r = temp[2];
                int s = temp[3];
                if (q - p > 1 && r - q > 1 && s - r > 1) {
                    if (nums[p] * nums[r] == nums[q] * nums[s]) {
                        count++;                        
                    }
                }
            }
            return ;
        }

        temp.push_back(index);
        generateValidSubsequence(index + 1, nums, temp, count);

        temp.pop_back();
        generateValidSubsequence(index + 1, nums, temp, count);
    }

    long long numberOfSubsequences(vector<int>& nums) {
        long long count = 0;

        int size = nums.size();
        vector<int> temp;

        generateValidSubsequence(0, nums, temp, count);

        return count;
    }
};