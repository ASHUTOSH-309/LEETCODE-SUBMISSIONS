#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string> ans;
        if (digits.size() == 0)
            return ans;

        unordered_map<int, string> mpp;
        mpp[2] = "abc";
        mpp[3] = "def";
        mpp[4] = "ghi";
        mpp[5] = "jkl";
        mpp[6] = "mno";
        mpp[7] = "pqrs";
        mpp[8] = "tuv";
        mpp[9] = "wxyz";

        vector<string> s(digits.size(), "");

        for (int i = 0; i < digits.size(); i++) {
            s[i] = mpp[digits[i] - '0'];
        }

        if (digits.size() == 1) {
            string str = mpp[digits[0] - '0'];
            for (int i = 0; i < str.size(); i++)
                ans.push_back(str.substr(i,1));
        }
        if (digits.size() == 2) {

            string first = mpp[digits[0] - '0'];
            string second = mpp[digits[1] - '0'];

            for (int i = 0; i < first.size(); i++) {
                string ch1 = first.substr(i, 1);
                for (int j = 0; j < second.size(); j++) {
                    string ch2 = second.substr(j, 1);
                    ans.push_back(ch1 + ch2);
                }
            }
            return ans;
        }
        if (digits.size() == 3) {

            string first = mpp[digits[0] - '0'];// abc
            string second = mpp[digits[1] - '0'];// def
            string third = mpp[digits[2] - '0'];// ghi

            for (int i = 0; i < first.size(); i++) {
                string ch1 = first.substr(i, 1);
                for (int j = 0; j < second.size(); j++) {
                    string ch2 = second.substr(j, 1);
                    for (int k = 0; k < third.size(); k++) {
                        string ch3 = third.substr(k, 1);
                        ans.push_back(ch1 + ch2 + ch3);
                    }
                }
            }
            return ans;
        }
        if (digits.size() == 4) {

            string first = mpp[digits[0] - '0'];
            string second = mpp[digits[1] - '0'];
            string third = mpp[digits[2] - '0'];
            string fourth = mpp[digits[3] - '0'];

            for (int i = 0; i < first.size(); i++) {
                string ch1 = first.substr(i, 1);
                for (int j = 0; j < second.size(); j++) {
                    string ch2 = second.substr(j, 1);
                    for (int k = 0; k < third.size(); k++) {
                        string ch3 = third.substr(k, 1);

                        for(int l=0;l<fourth.size();l++){
                            string ch4=fourth.substr(l,1);
                            ans.push_back(ch1 + ch2 + ch3+ch4);

                        }
                    }
                }
            }
            return ans;
        }

        return ans;
    }
};