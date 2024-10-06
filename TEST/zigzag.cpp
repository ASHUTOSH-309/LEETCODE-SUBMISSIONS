#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {

        string ans;

        // Edge case: if only 1 row is given or numRows >= s.size()
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }

        // Initialize 2D vector to hold the zigzag pattern
        vector<vector<char>> ansMatrix(numRows, vector<char>(2000, 0));
        int k = 0;
        int col = 0;
        int j;

        while (k < s.size())
        {

            // Going down vertically in the zigzag pattern
            for (j = 0; j < numRows && k < s.size(); j++)
            {
                ansMatrix[j][col] = s[k];
                k++;
            }

            j -= 2; // To step back and start the diagonal movement
            col++;

            // Going diagonally upwards in the zigzag pattern
            while (j > 0 && k < s.size())
            {
                ansMatrix[j][col] = s[k];
                j--;
                col++;
                k++;
            }
        }

        // Collecting the answer from the zigzag pattern stored in ansMatrix
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < col; j++)  // Iterate until the last used column
            {
                if (ansMatrix[i][j])  // Append non-null characters to the answer
                {
                    ans += ansMatrix[i][j];
                }
            }
        }

        return ans;
    }
};

int main(){

    Solution s1;
    cout << s1.convert("PAYPALISHIRING", 3) << endl;

    return 0;
}
