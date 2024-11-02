#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isCircularSentence(string sentence) {

        vector<string> words;
        istringstream iss(sentence);
        string word;

        while (iss >> word) {
            words.push_back(word);
        }

        for (int i = 0; i < words.size(); i++) {
            if(i==words.size()-1){
                //when iterator is at last string the we will compare it with first string
                if(words[0][0]==words[i][words[i].size()-1]) return true;
                return false;
            }

            long long sizeofIthString = words[i].size();
            if (words[i][sizeofIthString - 1] != words[i + 1][0]) {
                return false;
            }
        }

        return true;
    }
};