#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    string shortestPalindrome(string s) {
        

        long long start = 0;
        long long end = s.size() - 1;

        while (start <= end) {
            if (s[start] != s[end]) {
                 s.insert(start, 1, s[end]); 
                end++;
            }

            start++;
            end--;
        }

        return s;
    }
};