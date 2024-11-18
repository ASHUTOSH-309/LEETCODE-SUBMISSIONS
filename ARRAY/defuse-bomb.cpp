#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        vector<int> ans;
        for(int i=0;i<code.size();i++){

                if(k>0){
                        // replace i th number with next sum of next k numbers
                      //  i---> i+k-1;
                        if(i+k>code.size()-1){
                        // segregate into two parts
                        // 1. i---> code.size()-1
                        // 2. 0--> k+i-n
                            long long sum=0;

                            for(int j=i+1;j<=code.size()-1;j++)  sum+=code[j];
                            for(int j=0;j<=k+i-code.size();j++) sum+=code[j];          
                            ans.push_back(sum);

                        }
                        else{
                            long long sum=0;
                            for(int j=i+1;j<=i+k;j++) sum+=code[j];
                            
                            ans.push_back(sum);
                        }
                }
                else if(k<0){


                    if(i-abs(k)<0){
                    long long sum=0;

                        // segregate into two parts
                         //   1. i-1 to 0;   // i elements
                         //   2 n-1 to n-(k-i)// k-i elements
                        for(int j=i-1;j>=0;j--) sum+=code[j];
                        for(int j=code.size()-1;j>=code.size()-abs(k)+i;j--) sum+=code[j];

                        ans.push_back(sum);

                    }
                    else{
                        // when k th preceeding index is like in bounds >=0
                        long long sum=0;

                        for(int j=i-abs(k);j<=i-1;j++) sum+=code[j]; 
                        ans.push_back(sum);

                    }



                }
                else{

                    vector<int> ans(code.size());
                    return ans;

                }
        }

        return ans;
        
    }
};