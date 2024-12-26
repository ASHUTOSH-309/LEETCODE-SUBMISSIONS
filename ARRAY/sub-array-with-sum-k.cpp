#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int count=0;


        unordered_map<int,int> mpp;
        mpp.insert({0,1});

        int sum=0;
        for(int i=0;i<nums.size();i++){

            sum+=nums[i];

            if(mpp.find(sum-k)!=mpp.end()){

                // sum-k key exists in the map, hence there are some leading 
                // subarrays available with sum as sum-k;
                count+=mpp[sum-k];
            }

            mpp[sum]++;

        }


        return count;
        
    }
};