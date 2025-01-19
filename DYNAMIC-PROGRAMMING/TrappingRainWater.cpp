#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        if(height.size()<=2) return 0;

        int n=height.size();
        vector<vector<int>> dp(n,vector<int> (2,0));

       // dp[i][0]--> this will tell the max height from 0 to i
       // dp[i][1]--> this will tell the min height from i to last building 
        dp[0][0]=height[0];
        dp[n-1][1]=height[n-1];
        
       for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],height[i]);
            dp[n-i-1][1]=max(dp[n-i][1],height[n-i-1]);
       } 

        int TrappedWater=0;
        for(int i=1;i<n-1;i++){
            TrappedWater+= max(min(dp[i-1][0], dp[i+1][1])-height[i],0);
        }

        return TrappedWater;
        
    }
};