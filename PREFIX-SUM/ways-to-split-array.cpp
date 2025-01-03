#include<bits/stdc++.h>


using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int n=nums.size();
        int ans=0;


        vector<long long> PrefixSum(n,0);
        
        PrefixSum[0]=nums[0];

        for(int i=1;i<n;i++){
            PrefixSum[i]=PrefixSum[i-1]+nums[i];
        }

        for(int i=0;i<nums.size()-1;i++){
                if(PrefixSum[i]>=PrefixSum[n-1]-PrefixSum[i]) ans++;
        }

        return ans;
        
    }
};