#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        vector<int> ans;
        int n=A.size();
        vector<vector<int>> ElementsFoundInBothArrays(n+1,vector<int> (2,0));
        int counter=0;
        for(int i=0;i<n;i++){

                ElementsFoundInBothArrays[A[i]][0]++;
                ElementsFoundInBothArrays[B[i]][1]++;

            if(A[i]!=B[i]){
                if(ElementsFoundInBothArrays[A[i]][0] && ElementsFoundInBothArrays[A[i]][1]){
                    // If A[i] is like found in both the array then it will for sure increase the counter
                    counter++;
                }
                if(ElementsFoundInBothArrays[B[i]][0] && ElementsFoundInBothArrays[B[i]][1]){
                    // If A[i] is like found in both the array then it will for sure increase the counter
                    counter++;
                }
            }
            else counter++;
                ans.push_back(counter);
        }
        return ans;        
    }
};