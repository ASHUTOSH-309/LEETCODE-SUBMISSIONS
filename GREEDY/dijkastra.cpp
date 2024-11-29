#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        
     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // min heap to select the minimum weight vertex;
        
        pq.push({0,src});
        int n=adj.size();
        vector<bool> vis(n,false);
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        
        
        while(!pq.empty()){
            
            int weight=pq.top().first;
            int node=pq.top().second;
            
            pq.pop();
            vis[node]=true;
            
            
            for(auto x: adj[node]){
              // it contains list of neighbours of current selected node
            
                  int neighbour=x.first;
                  int edgeWeight=x.second;
                  
                  if(!vis[neighbour]){
                      // attemot to relax this neighbour
                      if(weight+edgeWeight<dist[neighbour]){
                          dist[neighbour]=weight+edgeWeight;
                          pq.push({dist[neighbour],neighbour});
                      }
                  }
              
            }
            
        }
        
        return dist;
        
        
    }
};
