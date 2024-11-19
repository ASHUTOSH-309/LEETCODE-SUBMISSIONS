#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long global_max = 0;
        long long sum = 0;

        map<int, int> CountTracker;
        int i;
        bool isFirstSubArrayValid=true;
        for ( i = 0; i < k; i++) {
            CountTracker[nums[i]]++;
            sum += nums[i];

               for(auto it : CountTracker){
                    if(it.second>1){
                            isFirstSubArrayValid=false;
                            break;
                    }
                }

            if(!isFirstSubArrayValid) break;
            if(i==k-1) global_max=max(global_max,sum);
        }

        if(i!=k){
            CountTracker[nums[i]]++;
            sum+=nums[i];
            i++;
        }

        int j;
        for ( j = k; j <= nums.size() - 1; j++) {

            sum += nums[j];
            sum -= nums[j - k];
            CountTracker[nums[j-k]]--;
            CountTracker[nums[j]]++;

            // Now sum contains the sum of elements of a k size subarray ending
            // at i;

// Required to check for all the keys if any of them life having occurence greater than 1
        

            bool isValidSubarray=true;
            for(auto it : CountTracker){
                if(it.second>1){
                        isValidSubarray=false;
                        break;
                }

            }

            if(!isValidSubarray) continue;

            global_max=max(global_max,sum);

        }

        return global_max;
    }
};