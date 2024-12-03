#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        string ans;
        long long start=0;

        for(int i=0;i<spaces.size();i++){

            // spaces[i] is the current pointer and start is previous pointer 
            ans+= s.substr(start,spaces[i]-start)+" ";
            start=spaces[i];
        }
        
        if(start==spaces.size())  ans+= s.substr(start,s.size()-start+1);
        else{ ans+= s.substr(start,s.size()-start+1);}
        
        return ans;
    }
};