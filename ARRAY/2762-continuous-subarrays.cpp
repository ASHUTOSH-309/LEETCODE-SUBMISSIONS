#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int maxi=nums[i];
            int mini=maxi;
            for (int j = i; j < nums.size(); j++) {
               
                if(nums[j] > maxi) maxi=nums[j];
                if(nums[j]< mini) mini=nums[j];

                if (abs(maxi- mini) <= 2 ) {    
                    ans++;
                }
                else break;
            }
        }

        return ans;
    }
};