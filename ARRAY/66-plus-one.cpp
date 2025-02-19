#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
    
            vector<int> ans(digits.begin(),digits.end());
    
            int lastDigit = (digits[digits.size() - 1] + 1) % 10;
            ans[ans.size()-1]=lastDigit;
         
            int carry = (digits[digits.size() - 1] + 1) / 10;
    
            for (int i = digits.size() - 2; i >= 0; i--) {
                ans[i] = (carry + digits[i]) % 10;
                carry = (carry + digits[i]) / 10;
            }
    
            if(carry==1) {
                 ans.insert(ans.begin(), 1); 
            }
    
            return ans;
        }
    };