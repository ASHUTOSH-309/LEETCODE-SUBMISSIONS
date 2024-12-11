#include <algorithm> 
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int maxi = 0;
       // vector<bool> Selected(nums.size());

        sort(nums.begin(), nums.end());

        int maxima = nums[nums.size() - 1] + k;
        int minima = nums[0] - k;



        for (int num = minima; num <= maxima; num++) {
            int count=0;
            for (int i = 0; i < nums.size(); i++) {
          if(nums[i]-k<=num && nums[i]+k>=num){
                    count++;
                }
            }
            maxi= max(maxi,count);
        }

        return maxi;
    }
};