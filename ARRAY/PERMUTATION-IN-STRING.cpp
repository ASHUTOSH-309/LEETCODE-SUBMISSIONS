#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> GiveMeCount(string s) {

        vector<int> CharCount(26);
        for (int i = 0; i < s.size(); i++)
            CharCount[s[i] - 'a']++;

        return CharCount;
    }

    bool checkInclusion(string s1, string s2) {

        vector<int> S1Count(26);
        vector<int> S2Count(26);

        for (int i = 0; i < s1.size(); i++) {
            S1Count[s1[i] - 'a']++;
        }
  

  

        for (int i = 0; i < s2.size(); i++) {
            for (int j = i; j < s2.size(); j++) {

                if (j - i + 1 > s2.size()) break;
                vector<int> currentSubstrCharCount =
                    GiveMeCount(s2.substr(i, j - i + 1));

                int flag=0;
                for (int i = 0; i < 26; i++) {
                    if (S1Count[i] != currentSubstrCharCount[i]){
                        flag=1;
                        break;
                    }                 
                }
                if(flag==1) continue;
                return true;
            }
        }

        return false;
    }
};