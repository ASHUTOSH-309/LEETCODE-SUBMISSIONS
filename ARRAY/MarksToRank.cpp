#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n = arr.size();
        if(n==0) return {};
        vector<int> ans(n);
       
        int rank = 1;
        vector<int> copy=arr;
        sort(copy.begin(),copy.end());
        unordered_map<int,int> MarksToRank;

        MarksToRank[copy[0]]=1;
        for (int i = 1; i < arr.size(); i++) {

            if (copy[i] == copy[i - 1]) {
                MarksToRank[copy[i]]=rank;
            } else {
                rank++;
                MarksToRank[copy[i]]=rank;
            }
        }


        for(int i=0;i<ans.size();i++){
            ans[i]=MarksToRank[arr[i]];
        }

        return ans;
    }
};