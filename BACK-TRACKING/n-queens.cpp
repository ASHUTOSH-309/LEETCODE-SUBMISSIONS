#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSafeToPlaceQueen(int row, int col, vector<string>& board, int n) {
        int x = row;
        int y = col;

        // check for left direction

        while (col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        row = x;
        col = y;

        // check for the left diagonal attack;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        // check for the right diagonal attack
        row = x;
        col = y;

        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        // Now if no attack from three directions then simply return truew

        return true;

    }

    void generateAllPossibleBoards(int col, vector<string>& board,
                                   vector<vector<string>>& ans, int n) {

        if (col == n) {
            ans.push_back(board);
            return;
        }

        // iterate through all the rows for each column and check whether it is
        // safe to place queen over the chess board

        for (int row = 0; row < n; row++) {

            if (isSafeToPlaceQueen(row, col, board, n)) {
                board[row][col] = 'Q';
                // now go for next column
                generateAllPossibleBoards(col + 1, board, ans, n);
                // remove the queen on back track
                board[row][col] = '.';
            }
        }
    }

        vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n, '.');

        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        generateAllPossibleBoards(0, board, ans, n);

        return ans;
    }
};