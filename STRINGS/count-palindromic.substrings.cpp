#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPalindromicSubsequence(string s) {

        int ans=0;
        int n=s.size();

        vector<int> firstOccurence(26,-1);
        vector<int> SecondOccurence(26,-1);

        for(int i=0;i<n;i++){
            if(firstOccurence[s[i]-'a']==-1){
                // current i is for the first index where the charctter s[i] is occuring
                firstOccurence[s[i]-'a']=i;

            }
         
                // A better second occurence alternative is found for the character s[i]
                SecondOccurence[s[i]-'a']=i;
            
        }


        for(int i=0;i<26;i++){
               set<char> st;
                if(firstOccurence[i]!=-1  && SecondOccurence[i]-firstOccurence[i]+1>=3){
                    // i th character actually exists in the string then we can count 
                    for(int j=firstOccurence[i]+1; j<SecondOccurence[i];j++){
                            st.insert(s[j]);
                    }
                    ans+=st.size();
                }
        }
        
        return ans;
    }
};