#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    
            vector<int> ans;
    
            unordered_map<int,int> mpp;
    
            long long sum=0;
    
            for(int i=0;i<grid.size();i++){
    
                for(int j=0;j<grid[0].size();j++){
    
                        sum+=grid[i][j];
                        mpp[grid[i][j]]++;
                        if(mpp[grid[i][j]]==2){
                            // we found the repeating digit 
                            ans.push_back(grid[i][j]);
                        }
                }
            }
    
            int n=grid.size();
           long long int IdealSum = (n * n * (n * n + 1)) / 2;
            ans.push_back(IdealSum-sum+ans[0]);
    
            return ans;
            
        }
    };