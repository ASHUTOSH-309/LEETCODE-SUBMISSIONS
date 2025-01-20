#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int rows=mat.size();
        int cols=mat[0].size();

        vector<int> RowVector(rows,0);
        vector<int> ColVector(cols,0);


        unordered_map<int,pair<int,int>> mpp;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                    mpp[mat[i][j]]={i,j};
            }
        }

        for(int i=0;i<arr.size();i++){

            auto it=mpp[arr[i]];
            int currx=it.first;
            int curry=it.second;
            RowVector[currx]++;
            if(RowVector[currx]==cols) return i;
            ColVector[curry]++;
            if(ColVector[curry]==rows) return i;

        }

        return 0;
        
    }
};