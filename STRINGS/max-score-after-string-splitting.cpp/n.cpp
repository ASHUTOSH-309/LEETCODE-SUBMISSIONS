#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int ans=0;

        int arr[2]={0};
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') arr[0]++;
            else arr[1]++;

        }
            int zero=0;
            int one=0;

        for(int i=0;i<s.size()-1;i++){

            if(s[i]=='0') zero++;
            else one++;

            int oneInRightString=arr[1]-one;
            ans=max(ans,zero+oneInRightString);               
        }


        return ans;
        
    }
};