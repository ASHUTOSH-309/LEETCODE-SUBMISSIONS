#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minOperations(string boxes) {

        int n=boxes.size();
        vector<int> ans;

        vector<int> OneIndices;
        for(int i=0;i<boxes.size();i++){
                if(boxes[i]=='1') OneIndices.push_back(i);
        }

        
        for(int i=0;i<n;i++){
            int score=0;
            for(int j=0;j<OneIndices.size();j++){
                    score+=abs(i-OneIndices[j]);
            }

            ans.push_back(score);

        }
        return ans;
        
    }
};