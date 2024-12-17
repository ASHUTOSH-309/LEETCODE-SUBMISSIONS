#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;

        priority_queue<int> pq;

        for(int i=0;i<gifts.size();i++){
            pq.push(gifts[i]);
        }

        for(int i=0;i<k;i++){
            int num=pq.top();
            pq.pop();
            pq.push(floor(sqrt(num)*1.0));
        }


        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }


        return ans;
        
    }
};