#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int ans = 0;

        int m = grid.size();
        int n = grid[0].size();

        unordered_map<int, int> RowMap;
        unordered_map<int, int> ColMap;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    RowMap[i]++;
                    ColMap[j]++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if(grid[i][j]==1){
                    if(RowMap[i]>1 || ColMap[j]>1) ans++;
                }

            }
        }

        return ans;
    }
};