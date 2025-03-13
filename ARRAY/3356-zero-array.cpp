#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    
            int ans=0;
            int n=queries.size();
    
    
            long long sum=0;
    
    
            for(int i=0;i<nums.size();i++) sum+=nums[i];
            if(sum==0) return 0;
    
            for(int i=0;i<n;i++){
    
                int left=queries[i][0];
                int right=queries[i][1];
                int margin=queries[i][2];
    
    
                for(int j=left;j<=right;j++){
                    if(nums[j]!=0){
                           if(nums[j]-margin>=0){
                                nums[j]=nums[j]-margin;
                                sum-=margin;
                           }
                           else{
                       
                                sum-=nums[j];
                                nums[j]=0;
                           }
                    }
                }
              
                if(sum==0) return i+1;
               
    
    
            }
    
            return -1;
            
        }
    };