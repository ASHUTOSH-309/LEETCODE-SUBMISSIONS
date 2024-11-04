#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    string compressedString(string word) {

        string comp="";

        for(int i=0;i<word.size();i++){

            long long count=1;
            char ch=word[i];
            while(word[i]==word[i+1]){
                count++;
                i++;
                if(count>=9) break;
            }


            comp+=to_string(count)+ch;
        }

        return comp;
    }
};