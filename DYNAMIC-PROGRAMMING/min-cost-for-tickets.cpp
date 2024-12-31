#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
       vector<long long> dp(days[days.size()-1]+1,0);
       dp[0]=0;

       unordered_set<int> st;
       for(int i=0;i<days.size();i++) st.insert(days[i]);

       for(int i=1;i<=days[days.size()-1];i++){

            if(st.find(i)==st.end()){
                // No trip on i the day
                dp[i]=dp[i-1];
                continue;
            }
        
            dp[i]=min({dp[(i-7>0)? i-7:0]+costs[1], dp[(i-30)>0? i-30:0]+costs[2],dp[i-1]+costs[0]});
       }

       return dp[days[days.size()-1]];
    }
};