#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void dfs(int row, int col, vector < vector<int>> & image,
             vector<vector<int>>& ans, int initialColor, int Newcolor,
             int delRow[], int delCol[]) {

        ans[row][col] = Newcolor;
        //{row,col}===> They both are combinedly representing our current cell

        int gridRows = image.size();
        int gridCols = image[0].size();

        for (int i = 0; i < 4; i++) {
            // Iterate in four directions pertaining to the current cell
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < gridRows && ncol < gridCols &&
                image[nrow][ncol] == initialColor &&
                ans[nrow][ncol] != Newcolor)
                dfs(nrow, ncol, image, ans, initialColor, Newcolor, delRow,
                    delCol);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int rows = image.size();
        int cols = image[0].size();

        int initialColor = image[sr][sc];

        vector<vector<int>> ans = image;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        dfs(sr, sc, image, ans, initialColor, color, delRow, delCol);

        return ans;
    }
};