#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {

            int alice = queries[i][0];
            int bob = queries[i][1];
            int maxBuildingindex = max(alice, bob);

            if (heights[maxBuildingindex] >= heights[alice] &&
                heights[maxBuildingindex] >= heights[bob]) {
                ans.push_back(maxBuildingindex);
                continue;
            }

            bool flag=false;

            for (int i = maxBuildingindex; i < heights.size(); i++) {
                if (heights[i] >= heights[alice] && heights[i] >= heights[bob]) {
                    ans.push_back(i);
                    flag=true;
                    break;
                }
            }

            if(!flag) ans.push_back(-1);
        }

        return ans;
    }
};