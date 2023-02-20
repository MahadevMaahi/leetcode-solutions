class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), _min = INT_MAX;
        vector<vector<int>> dp(col, vector<int> (row, 0));
        for(int i = 0; i < col; i++) dp[0][i] = matrix[0][i];
        for(int i = 1; i < row; i++) {
            for(int j = 0; j < col; j++) {
                dp[i][j] = matrix[i][j] + min({dp[i-1][j],
                 (j-1 >= 0 ? dp[i-1][j-1] : INT_MAX),
                 (j+1 < col ? dp[i-1][j+1] : INT_MAX)});
            }
        }
        for(int i = 0; i < col; i++) _min = min(_min, dp[row-1][i]);
        return _min;
    }
};