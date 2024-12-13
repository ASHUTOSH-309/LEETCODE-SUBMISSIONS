#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryOneCount(int num){
        int count=0;
        while(num){
            count+=num%2;
            num/=2;
        }
        return count;
    }



    vector<int> countBits(int n) { 
        vector<int> ans(n+1);
        ans[0]=0;
        for(int i=0;i<=n;i++){
            ans[i]=binaryOneCount(i);
        }
        
        return ans;

    }
};