class Solution {
public:

    void recurDFS(vector<vector<char>> &grid, int i, int j, int row, int col) {
        grid[i][j] = '0';
        if(i-1 >= 0 && grid[i-1][j] == '1') recurDFS(grid, i-1, j, row, col);
        if(j-1 >= 0 && grid[i][j-1] == '1') recurDFS(grid, i, j-1, row, col);
        if(i+1 < row && grid[i+1][j] == '1') recurDFS(grid, i+1, j, row, col);
        if(j+1 < col && grid[i][j+1] == '1') recurDFS(grid, i, j+1, row, col);
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(), cnt = 0;
        for(int i = 0; i < row; i++) for(int j = 0; j < col; j++) {
            if(grid[i][j] == '1') {
                cnt++;
                recurDFS(grid, i, j, row, col);
            }
        }
        return cnt;
    }
};