class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length(), size;
        if(len == 0) return true;
        unordered_set<string> uSet;
        for(string str : wordDict) uSet.insert(str);
        vector<bool> dp(len, false);
        vector<int> mIndex;
        mIndex.push_back(-1);
        for(int i = 0; i < len; i++) {
            size = mIndex.size();
            for(int j = size - 1; j >= 0; j--) {
                if(uSet.count(s.substr(mIndex[j] + 1, i - mIndex[j]))) {
                    dp[i] = true;
                    mIndex.push_back(i);
                    break;
                }
            }
        }
        return dp[len - 1];
    }
};