#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkIfPartitionCanBeCreated(vector<int>& arr, int i, int j, unordered_map<int,bool>& mpp) {

        for (int z = i; z <= j; z++) {
            if (mpp.find(z)==mpp.end())
                return false;
        }

        return true;
    }

    int maxChunksToSorted(vector<int>& arr) {

        int maxChunks = 0;

        for (int i = 0; i < arr.size(); i++) {
            unordered_map<int, bool> mpp;

            for (int j = i; j < arr.size(); j++) {
                // check if all numbers from i to j are present, if yes then
                // break the loop and reinitialize the i pointer

                mpp[arr[j]] = true;
                if (checkIfPartitionCanBeCreated(arr, i, j,mpp)) {
                    maxChunks++;
                    i=j+1;     
                }
            }
        }

        return maxChunks;
    }
};