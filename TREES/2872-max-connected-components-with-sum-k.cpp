#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dfs(int node, vector<vector<int>>& adj, vector<int>& vals, int k,
                  int& counter, int parent) {

        long long sum = vals[node];

        for (auto negh : adj[node]) {
            if (negh != parent) {
                sum += dfs(negh, adj, vals, k, counter, node);
            }
        }
        sum%=k;
        if(sum==0) counter++;
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& vals, int k) {

        int counter = 0;

        vector<vector<int>> adj(n);

        for (auto it : edges) {
            int firstNode = it[0];
            int SecondNode = it[1];
            adj[firstNode].push_back(SecondNode);
            adj[SecondNode].push_back(firstNode);
        }

        dfs(0, adj, vals, k, counter, -1);

        return counter;
    }
};