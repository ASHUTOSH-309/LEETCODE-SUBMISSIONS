#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        unordered_map<char,int> mpp;
        
        for(int i=0;i<s.size();i++) mpp[s[i]]++;
        int counter=0;
        for(char ch='a';ch<='z';ch++){
            if(mpp[ch]%2==1) counter++;
            // odd frequecny character will detrmine the minimum number of palindromes you have to have construct
            // even freq can easily be distributed back and forth now let's go
            // and the max palindromes =string size
            // if oddfreqcharcters > k then its false
            // if k> s.size() that is more than the max number of palindromes that can be created then we are sure that
            // it's not possibe to fulfil the requirements as extra k-s.size() palindromes are required
            if(counter>k) return false;
        }

        return true;

    }
};