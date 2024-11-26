#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        int ans=0;
        // graph has n nodes
        int m=edges.size();

        // the guy who is weaker than none is the champion

        map<int,int> mpp;
        for(int i=0;i<n;i++) mpp[i]=0;

        for(int i=0;i<edges.size();i++){
            mpp[edges[i][1]]++;
        }
        int count=0;
        for(auto it: mpp){
            if(it.second==0){
                count++;
                if(count==2) return -1;
                ans=it.first;
            }
        }
        return ans;
        
    }
};