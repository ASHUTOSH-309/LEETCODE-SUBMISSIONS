#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;
     
        string ans="";

        int size=word.size();

        int requiredSubstringSize=word.size()-numFriends+1;

        for(int i=0;i<=size-requiredSubstringSize;i++){
                ans=max(ans,word.substr(i,requiredSubstringSize));
        
        }

        for(int i=0;i<ans.size();i++){

            for(int j=i;j<ans.size();j++){
                ans=max(ans,ans.substr(i,j-i+1));
            }

            
        }
        


        return ans;
        
    }
};