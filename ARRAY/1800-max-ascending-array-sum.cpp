#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& arr) {

        int n=arr.size();

        long long global_maxima=0;

        long long local_maxima=arr[0];

        bool flag=false;
        for(int i=1;i<n;i++){

          if(arr[i-1]<arr[i]){
            local_maxima+=arr[i];
            cout<<local_maxima;

          } 
          else{
            flag=true;
            global_maxima=max(global_maxima,local_maxima);
            local_maxima=arr[i];
          } 
    
        }
          global_maxima=max(global_maxima,local_maxima);

        if(flag==false){
            return local_maxima;
        }

        return global_maxima;
        
    }
};