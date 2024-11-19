#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {


            long long global_max=0;
            for(int i=0;i<=nums.size()-k;i++){
                    long long sum=0;
                    bool AreDistinct=true;
                    for(int j=i;j<i+k;j++){
                            sum+=nums[j];
                            if( (j<i+k-1) && (nums[j]==nums[j+1]) ){
                                    AreDistinct=false;
                                    break;
                            }
                    }

                    if(AreDistinct) global_max=max(global_max,sum);
            }

            return global_max;
    }
};