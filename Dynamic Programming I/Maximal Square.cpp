class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), _max = 0;
        int dp[row][col]; memset(dp, 0, sizeof(dp));
        for(int i = 0; i < row; i++) dp[i][0] = (matrix[i][0] - '0'), _max = max(_max, dp[i][0]);
        for(int i = 0; i < col; i++) dp[0][i] = (matrix[0][i] - '0'), _max = max(_max, dp[0][i]);
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if((matrix[i][j] - '0') == 1) {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                _max = max(_max, dp[i][j]);
            }
        }
        return (_max * _max);
    }
};