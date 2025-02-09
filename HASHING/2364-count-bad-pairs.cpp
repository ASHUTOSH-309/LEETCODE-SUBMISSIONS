#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        long long count = 0;

        long long total_pairs=(nums.size())*(nums.size()-1)/2;

        unordered_map<long long,long long> mpp;

        for(long long i=0;i<nums.size();i++) mpp[nums[i]-i]++;

        long long good_pairs=0;
        for(auto it: mpp) good_pairs+=it.second*(it.second-1)/2;

        count=total_pairs-good_pairs;

        return count;
    }
};