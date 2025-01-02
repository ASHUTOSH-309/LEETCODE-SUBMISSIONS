#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool isVowel(char ch){

        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';

    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;

        vector<int> VowelString(words.size(),0);
        
        if(isVowel(words[0][0]) && isVowel(words[0][words[0].size()-1])){
            VowelString[0]++;
        }

        for(int i=1;i<words.size();i++){

            string str=words[i];
            if(isVowel(str[0]) && isVowel(str[str.size()-1])) VowelString[i]=VowelString[i-1]+1;
            else VowelString[i]=VowelString[i-1];
        }

        for(int i=0;i<queries.size();i++){
            int left=queries[i][0];
            int right=queries[i][1];
            if(left!=0)ans.push_back(VowelString[right]-VowelString[max(left-1,0)]);
            else ans.push_back(VowelString[right]);
        }

        return ans;
        
    }
};