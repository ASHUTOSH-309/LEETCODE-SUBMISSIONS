#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
    
            int max_profit=0;
    
             vector<int> MaximaFromItoJ(prices.size(),0);
             MaximaFromItoJ[prices.size()-1]=prices[prices.size()-1];
    
                for(int i=prices.size()-2;i>=0;i--){
                    MaximaFromItoJ[i]=max( MaximaFromItoJ[i+1],prices[i]);
                }
    
                for(int i=0;i<prices.size();i++){
                    cout<<MaximaFromItoJ[i]<<endl;
                    max_profit=max(max_profit,MaximaFromItoJ[i]-prices[i]);
                }
    
        
            return max_profit;  
        }
    };