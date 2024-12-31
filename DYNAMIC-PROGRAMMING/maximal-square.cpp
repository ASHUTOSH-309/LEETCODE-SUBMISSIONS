#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;

        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<vector<int>> dp(rows,vector<int>(cols,0));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){

                    if(i==0 || j==0){
                        if(matrix[i][j]=='1') dp[i][j]=1;
                    }
                    else{
                        if(matrix[i][j]=='1') dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                    }
                    ans=max(ans,dp[i][j]);
            }
        }

        return ans*ans;

        
    }
};