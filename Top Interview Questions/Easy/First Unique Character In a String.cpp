class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.length(), ans = len;
        if(len == 0) return len;
        vector<int> dp(26, -1);
        for(int i = 0; i < len; i++) {
            if(dp[s[i] - 'a'] == -1) dp[s[i] - 'a'] = i;
            else dp[s[i] - 'a'] = -2;
        }
        for(int i = 0; i < 26; i++) if(dp[i] >= 0 && ans > dp[i]) ans = dp[i];
        return ans == len ? -1 : ans;
    }
};