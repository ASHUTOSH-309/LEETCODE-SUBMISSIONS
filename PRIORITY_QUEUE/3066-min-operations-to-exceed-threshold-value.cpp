#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(ll i=0;i<nums.size();i++) pq.push(nums[i]);

        ll count=0;
        while(!pq.empty() &&  pq.top()<k){

                if(pq.size()>=2){
                ll minima=pq.top();
                pq.pop();

                ll secminima=pq.top();
                pq.pop();

                   pq.push(2*min(minima,secminima)+max(minima,secminima));
                    count++;
                }
                else{
                    break;
                }
        }
        return count;   
    }
};