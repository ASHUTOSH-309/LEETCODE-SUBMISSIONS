#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include <numeric>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {

            for (int j = i; j < nums.size(); j++) {
                int start=i;
                int end=j+1;
              
               sum= max(accumulate(nums.begin() + start, nums.begin() + end, 0),sum);

            }
        }

        return sum;
    }
};