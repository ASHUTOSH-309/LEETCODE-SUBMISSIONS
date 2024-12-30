#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    const int m=1e9+7;
    int CountPossibleStrings(int CurrentSize,int Zero, int One,int high, int low,vector<int>& dp){

        if(CurrentSize>high) return 0;
        if(dp[CurrentSize] != -1) return dp[CurrentSize];
        bool includeCurrent=false;

        if(CurrentSize>=low && CurrentSize<=high){
            includeCurrent=true;     
        }

        int ZeroCount= CountPossibleStrings(CurrentSize+Zero,Zero,One,high,low,dp);
        int OneCount=  CountPossibleStrings(CurrentSize+One,Zero,One,high, low,dp);


        return dp[CurrentSize]=(includeCurrent+ZeroCount+OneCount)%m;
    }


    int countGoodStrings(int low, int high, int zero, int one) {
    
        vector<int> dp(high+1,-1);
        return  CountPossibleStrings(0,zero,one,high,low,dp);       
    }
};