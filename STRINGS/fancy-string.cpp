#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
      string makeFancyString(string s) {
        stack<char> st;
        st.push(s[0]);

        int n = s.size(),cnt = 1;
        for(int i=1;i<n;i++){
            if(s[i] == st.top()){
                cnt++;
                if(cnt < 3) st.push(s[i]);
            }
            else{
                cnt = 1;
                st.push(s[i]);
            }
        }
        int size=st.size();
        vector<char> ans(size);
        long long backIterator=st.size()-1;
        while(!st.empty()){
            ans[backIterator]=st.top();
            st.pop();
            backIterator--;
        }

        string myString="";
        for(char ch: ans){
            myString+=ch;
        }

        return myString;
    }
};