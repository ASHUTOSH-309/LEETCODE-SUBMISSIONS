#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

       unordered_map<int,long> FreqInFinalXorComputation;

        int len1=nums1.size();
        int len2=nums2.size();


       for(auto num : nums1) FreqInFinalXorComputation[num]+=len2;
       for(auto num: nums2) FreqInFinalXorComputation[num]+=len1;

        int ans=0;
       for(auto [value,freq] : FreqInFinalXorComputation){

            if( freq%2 ==1)  ans= ans ^ value;

       }

        return ans;
    }
};