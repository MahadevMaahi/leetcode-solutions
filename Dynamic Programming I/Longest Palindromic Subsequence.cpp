class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l = s.length();
        int dp[l][l]; memset(dp, 0, sizeof(dp));
        for(int i = 0; i < l; i++) dp[i][i] = 1;
        for(int i = 1; i < l; i++) if(s[i-1] == s[i]) dp[i-1][i] = 2; else dp[i-1][i] = 1;
        for(int len = 3; len <= l; len++) {
            for(int i = 0, j = len - 1; j < l; i++, j++) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][l-1];
    }
};