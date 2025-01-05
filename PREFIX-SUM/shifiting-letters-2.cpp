#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

     vector<int> Moves(s.size() + 1, 0); // +1 for avoiding overflow in right + 1

        for (int i = 0; i < shifts.size(); i++) {
            int left = shifts[i][0];
            int right = shifts[i][1];
            int direction = shifts[i][2];
            
            if (direction == 1) { // Forward shift
                Moves[left] += 1;
                Moves[right + 1] -= 1;
            } else { // Backward shift
                Moves[left] -= 1;
                Moves[right + 1] += 1;
            }
        }

        // Step 2: Calculate Net Moves for Each Index
        int netShift = 0;
        for (int i = 0; i < s.size(); i++) {
            netShift += Moves[i]; // Accumulate shifts
            int shift = (netShift % 26 + 26) % 26; // Normalize to [0, 25]
            
            // Step 3: Apply Shift to Character
            s[i] = 'a' + (s[i] - 'a' + shift + 26) % 26;
        }

        return s;
    }
    
};