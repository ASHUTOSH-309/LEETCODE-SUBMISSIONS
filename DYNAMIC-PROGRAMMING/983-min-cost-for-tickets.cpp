#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost = INT_MAX;

    int findCostofTravelling(int index, vector<int>& days, vector<int>& costs,vector<int>& dp) {

        if (index >= days.size()) {
         return 0;
        }

        if(dp[index]!=-1) return dp[index];

        // if one day pass is taken
       int cost_1= findCostofTravelling(index + 1, days, costs,dp)+ costs[0];
        // i f 7 days pass if taken
        int j=index;
       

            while (j<days.size() && days[j] <= days[index] + 6) {
                j++;
            } 
       

            int cost_7=findCostofTravelling(j, days, costs,dp)+costs[1];

        j=index;

            while (j<days.size() && (days[j] <= days[index] + 29)) {
                j++;
            } 
      

       int cost_30= findCostofTravelling(j, days, costs,dp)+ costs[2];

       return dp[index]=min({cost_1,cost_7,cost_30});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int> dp(days[days.size()-1]+1,-1);
        return findCostofTravelling(0,days, costs, dp);
    }
};