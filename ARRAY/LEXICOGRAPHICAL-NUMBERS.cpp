#include<iostream>
#include<bits/stdc++.h>


using namespace std;

class Solution {
public:
    void SortArray(vector<int>& temp, vector<int>& ans) {
        for (int i = 0; i < temp.size(); i++) {
            for (int j = i+1; j < temp.size(); j++) {
                    if(temp[i]>temp[j]){
                        int tempo=ans[i];
                        ans[i]=ans[j];
                        ans[j]=tempo;

                        int temp2=temp[i];
                        temp[i]=temp[j];
                        temp[j]=temp2;
                    }
            }
        }
    }

    vector<int> lexicalOrder(int n) {
        long long digits = to_string(n).size();

        vector<int> ans;
        vector<int> temp;
        for (int i = 1; i <= n; i++) {
            ans.push_back(i);
            int j = i * pow(10, digits - to_string(i).size());
            temp.push_back(j);
        }

        SortArray(temp, ans);

        return ans;
    }
};