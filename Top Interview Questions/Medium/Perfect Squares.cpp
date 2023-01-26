class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= n; i++) {
            int cnt = INT_MAX;
            for(int j = 1; (j * j) <= i; j++) {
                cnt = min(cnt, dp[i - (j * j)] + 1);
            }
            dp[i] = cnt;
        }
        return dp[n];
    }
};