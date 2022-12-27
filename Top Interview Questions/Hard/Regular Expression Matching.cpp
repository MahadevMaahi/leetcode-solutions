class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        vector<bool> vb(pLen + 1, false);
        vector<vector<bool>> dp(sLen + 1, vb);
        dp[0][0] = true;
        for(int i = 1; i <= pLen; i++) {
            if(p[i-1] == '*') {
                dp[0][i] = dp[0][i-2];
            }
        }

        for(int i = 1; i <= sLen; i++) {
            for(int j = 1; j <= pLen; j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if(p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2];
                    if(p[j-2] == s[i-1] || p[j-2] == '.') {
                        dp[i][j] = dp[i][j] | dp[i-1][j];
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[sLen][pLen];
    }
};