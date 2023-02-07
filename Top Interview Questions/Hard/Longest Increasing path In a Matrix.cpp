class Solution {
public:

    void _dfs(vector<vector<int>> &matrix, int i, int j, int row, int col, vector<vector<int>> &dp) {
        if(dp[i][j] > 0) return;
        int _max = 0;
        if(i > 0 && matrix[i-1][j] > matrix[i][j]) {
                if(dp[i-1][j] == 0) {
                    _dfs(matrix, i-1, j, row, col, dp);
                }
            _max = max(_max, dp[i-1][j]);
        }
        if(j > 0 && matrix[i][j-1] > matrix[i][j]) {
                if(dp[i][j-1] == 0) {
                    _dfs(matrix, i, j-1, row, col, dp);
                }
            _max = max(_max, dp[i][j-1]);
        }
        if(i < row - 1 && matrix[i+1][j] > matrix[i][j]) {
            if(dp[i+1][j] == 0) {
                _dfs(matrix, i+1, j, row, col, dp);
            }
            _max = max(_max, dp[i+1][j]);
        }
        if(j < col - 1 && matrix[i][j+1] > matrix[i][j]) {
            if(dp[i][j+1] == 0) {
                _dfs(matrix, i, j+1, row, col, dp);
            }
            _max = max(_max, dp[i][j+1]);
        }
        dp[i][j] = _max + 1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int _max = 1;

        vector<vector<int>> dp(row, vector<int>(col, 0));

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(dp[i][j] == 0) {
                    _dfs(matrix, i, j, row, col, dp);
                }
                _max = max(_max, dp[i][j]);
            }
        }
        return _max;
    }
};