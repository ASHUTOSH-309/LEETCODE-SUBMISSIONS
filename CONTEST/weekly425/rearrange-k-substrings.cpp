#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {

        int splitSize=s.size()/k;


        map<string,int> KStringsofS;
        map<string,int> KStringsofT;

        for(int i=0;i<s.size();i+=splitSize){
            KStringsofS[s.substr(i,splitSize)]++;
            KStringsofT[t.substr(i,splitSize)]++;    
        }

        for(auto it: KStringsofS){

            if(KStringsofT[it.first]==KStringsofS[it.first]){
                KStringsofT[it.first]--; 
                KStringsofS[it.first]--;
            }
            else{
                return false;
            }
            
        }




        return true;
        
    }
};