#include<bits/stdc++.h>


using namespace std;


class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k==0) return 0;
        int ans = -1;
        map<char, int> Frequency;

        for (int i = 0; i < s.size(); i++) {
            Frequency[s[i]]++;
        }

        if (Frequency['a'] < k || Frequency['b'] < k || Frequency['c'] < k)
            return ans;

        ans=INT_MAX;
        map<char, int> FreqFront;

        for (int i = 0; i < s.size(); i++) {
            FreqFront[s[i]]++;
            map<char, int> FreqBack;
            bool isLeastKConditionTrue=FreqFront['a']>=k && FreqFront['b']>=k && FreqFront['c']>=k;
            int j;

            for (j = s.size() - 1; j > i && !isLeastKConditionTrue; j--) {
                FreqBack[s[j]]++;
                bool MinimumAs = (FreqFront['a'] + FreqBack['a']) >= k;
                bool MinimumBs = (FreqFront['b'] + FreqBack['b']) >= k;
                bool MinimumC = (FreqFront['c'] + FreqBack['c']) >= k;
                isLeastKConditionTrue = MinimumAs && MinimumBs && MinimumC;

            }
            int n=s.size();
            ans=min(ans, n-j+i);
        }

        return ans;
    }
};