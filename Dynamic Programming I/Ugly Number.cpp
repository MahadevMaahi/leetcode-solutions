class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 3) return n;
        vector<int> dp = {1};
        int i2 = 0, i3 = 0, i5 = 0, val;
        while(dp.size() < n) {
            val = min({2 * dp[i2], 3 * dp[i3], 5 *dp[i5]});
            dp.push_back(val);
            if((2 * dp[i2]) == dp.back()) i2++;
            if((3 * dp[i3]) == dp.back()) i3++;
            if((5 * dp[i5]) == dp.back()) i5++;
        }
        return dp[n - 1];
    }
};