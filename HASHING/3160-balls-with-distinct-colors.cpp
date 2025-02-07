#include<bits/stdc++.h>
using namespace std;



typedef long long int ll;
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        vector<int> ans;

        unordered_map<ll, ll> mpp;
        unordered_map<ll, ll> colorTracker;

        for (int i = 0; i < queries.size(); i++) {

            int ball = queries[i][0];
            int color = queries[i][1];

            if (mpp[ball]) {// ball is aready colored then from colorTracker,
                colorTracker[mpp[ball]]--;
                if(colorTracker[mpp[ball]]==0){
                    colorTracker.erase(mpp[ball]);
                } 
                mpp[ball] = color;
            }
            else{
                // when ball is colored for the first time
                mpp[ball]=color;

            }
            colorTracker[color]++;
            ans.push_back(colorTracker.size());
        }

        return ans;
    }
};