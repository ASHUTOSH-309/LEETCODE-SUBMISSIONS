#include<iostream>
#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {

        map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        vector<int> ans;

        for (auto it : mpp) {
            if(it.second ==2){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
