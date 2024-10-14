#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
    
        long long operations=0;
        long long score=0;

        priority_queue<int> pq;

    
        for(int i=0;i<nums.size();i++){
                pq.push(nums[i]);
        }

        while(!pq.empty()){
            int topElement=pq.top();
            score+=pq.top();
            pq.pop();
            pq.push(ceil(topElement/3.0));
            operations++;
            if(operations==k) break;

        }
        return score;
    }
};