class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        if(len == 0) return -1;
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for(int i = 0; i < len; i++) {
            for(int j = coins[i]; j <= amount; j++) {
                if(dp[j-coins[i]] != -1 && (dp[j] == -1 || (dp[j] > dp[j-coins[i]] + 1))) {
                    dp[j] = dp[j - coins[i]] + 1;
                }
            }
        }
        return dp[amount];
    }
};