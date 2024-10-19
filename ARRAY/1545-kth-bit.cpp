#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string reverseString(string s) {

        int start = 0;
        int end = s.size() - 1;

        while (start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }

        return s;
    }

    string Invert(string s) {

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                s[i] = '1';
            else {
                s[i] = '0';
            }
        }
        return s;
    }

    string findString(int n) {
        if (n == 1)
            return "0";
        string prevString = findString(n - 1);
        string InvertPrevious = Invert(prevString);
        return prevString + "1" + reverseString(InvertPrevious);
    }

    char findKthBit(int n, int k) {
        string Result = findString(n);
        return Result[k - 1];
    }
};