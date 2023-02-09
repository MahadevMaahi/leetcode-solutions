class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        if(len < 1) return 0;
        int dp[len + 1];
        memset(dp, 0, len + 1);
        for(int i = 2; i <= len; i++) {
            dp[i] = min(dp[i-2] + cost[i-2], dp[i-1] + cost[i-1]);
        }
        return dp[len];
    }
};