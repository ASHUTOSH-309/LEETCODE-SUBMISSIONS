#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution {
public:
    ll SumofDigits(ll num) {

        ll sum = 0;
        while (num != 0) {
            sum += num % 10;
            num = num / 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {

        if (nums.size() == 1)
            return -1;

        ll ans = -1;
        unordered_map<ll, priority_queue<ll>> mpp;
      

        for (int i = 0; i < nums.size(); i++) {
            mpp[-1*SumofDigits(nums[i])].push(nums[i]);
        }
        ll count = 0;
        for (auto it : mpp) {
            
            if (it.second.size() >= 2) {
                ll first=it.second.top();
                it.second.pop();
                ans=max(ans,it.second.top()+first);
            }
        }

        return ans;
    }
};