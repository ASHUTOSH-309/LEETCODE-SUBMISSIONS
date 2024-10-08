
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSwaps(string s)
    {

        int ans = 0;
        int n = s.size();

        int open = 0;
        int close = 0;
        int k = n - 1;

        while (s[k] != '[')
            k--;
        for (int i = 0; i < n; i++)
        {

            if (s[i] == '[')
                open++;
            else if (s[i] == ']')
                close++;

            if (close > open)
            {
                close--;
                open++;
                ans++;
                swap(s[i], s[k]);
                while (i < k && s[k] != '[')
                    k--;
            }
        }

        return ans;
    }
};