#include<bits/stdc++.h>


using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {

        int size1 = str1.size();
        int size2 = str2.size();
        int count = 0;

        int j = 0;
        for (int i = 0; i < size1; i++) {
            char current_char = str1[i];
            char next_char;

            if (current_char == 'z')
                next_char = 'a';
            else
                next_char = current_char + 1;

            if (current_char == str2[j] || next_char == str2[j]) {
                j++;
                if (j == size2)
                    return true;
            }
        }

        return false;
    }
};