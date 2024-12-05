#include<bits/stdc++.h>


using namespace std;

vector<vector<int>> GeneratePowerSet(vector<int> nums){

    int size=nums.size();
    vector<vector<int>> ans;


    for(int i=0;i<(1<<size);i++){
        vector<int> ds;
        for(int j=0;j<size;j++){

            if((1<<j) & i){
                ds.push_back(nums[j]);
            }
        }
        ans.push_back(ds);
    }


    return ans;



}