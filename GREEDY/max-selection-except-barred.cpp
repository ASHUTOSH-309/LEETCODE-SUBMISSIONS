#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int maxCount=0;
        unordered_map<int,int> mpp;

        for(int i=0;i<banned.size();i++){
            mpp[banned[i]]++;
        }
        long long sum=0;
        for(int i=1;i<=n;i++){

            if((mpp.find(i)==mpp.end()) && sum+i<=maxSum){
                sum+=i;
                maxCount++;
            }
        }

        return maxCount;
        
    }
};