class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size(), _min = INT_MAX;
        vector<int> temp; vector<vector<int>> dp(row, temp);
        dp[0].push_back(triangle[0][0]);
        for(int i = 1; i < row; i++) {
            for(int j = 0; j < triangle[i].size(); j++) {
                dp[i].push_back(triangle[i][j] + min({(j < dp[i-1].size() ? dp[i-1][j] : INT_MAX),
                 (j-1 >= 0 ? dp[i-1][j-1] : INT_MAX)}));
            }
        }
        for(int i = 0; i < triangle[row-1].size(); i++) _min = min(_min, dp[row-1][i]);
        return _min;
    }
};