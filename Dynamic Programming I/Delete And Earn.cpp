class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int len = nums.size(), _max = 0;
        if(len == 0) return 0;
        for(int i : nums) _max = max(i, _max);
        long int _hash[_max + 1], dp[_max + 1];
        memset(_hash, 0, sizeof(_hash));
        memset(dp, 0, sizeof(dp));
        for(int i : nums) _hash[i]++;
        dp[0] = 0; dp[1] = (1 * _hash[1]);
        for(int i = 2; i <= _max; i++) {
            dp[i] = max(dp[i-2] + (i * _hash[i]), dp[i-1]);
        }
        return dp[_max];
    }
};