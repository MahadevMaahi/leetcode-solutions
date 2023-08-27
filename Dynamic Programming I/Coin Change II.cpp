class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        if(len == 0) return 0;
        sort(coins.begin(), coins.end(), greater<int>());
        int dp[amount + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; i - coins[j] >= 0; j++) {
                for(int k = 1; i - (k * coins[j]) >= 0; k++) {
                    dp[i] = dp[i] + dp[i - (k * coins[j])];
                }
            }
        }
        return dp[amount];
    }
};