class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        int op=0;
        for (int col = 0; col < cols; col++) {

            for (int row = 1; row < rows; row++) {
                    if(grid[row-1][col]>=grid[row][col]){
                        op+=abs(grid[row-1][col]-grid[row][col])+1;
                        grid[row][col]=grid[row-1][col]+1;
                    }     
            }
        }

        return op;
    }
};