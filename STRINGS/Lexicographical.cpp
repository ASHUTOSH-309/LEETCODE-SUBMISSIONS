#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<string> ans;
        for (int i = 1; i <= n; i++)
        {
            ans.push_back(to_string(i));
        }
        sort(ans.begin(), ans.end());
        vector<int> FinalAns;

        for (int i = 0; i < n; i++)
        {
            FinalAns.push_back(stoi(ans[i]));
        }

        return FinalAns;
    }
};