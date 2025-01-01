#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (auto edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        if(i!=k && j!=k && dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k]+dist[k][j]<dist[i][j])
                             dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
        // Now dist matrix with all source shortest path is ready ,simply iterate and find the city with minimum number
        // of reachable cities,
        int minCityCount=INT_MAX;
        int ans;
        for(int i=0;i<n;i++){
                int count=0;

                for(int j=0;j<n;j++){
                        if(i!=j && dist[i][j]<=distanceThreshold) count++;

                }
                if(count<=minCityCount){
                    minCityCount=count;
                    ans=i;
                }
        }
        return ans;
    }
};