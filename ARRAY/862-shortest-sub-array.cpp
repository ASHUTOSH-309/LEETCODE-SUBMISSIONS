#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int shortestSubarray(vector<int>& nums, int k) {
        int global_minima = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            long long sum=0;
            for (int j = i; j < nums.size(); j++) {
                    sum+=nums[j];

                    if(sum>=k && (j-i+1 <global_minima)){
                        global_minima=min(global_minima,j-i+1);
                        break;
                    }

            }
        }
        if(global_minima==INT_MAX) {
            return -1;
        }
        cout<<global_minima;
        return global_minima;
    }

};