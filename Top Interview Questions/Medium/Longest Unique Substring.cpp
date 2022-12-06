class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length(), i = 0, j = 0, maxLen = 0;
        unordered_map<char, int> mp;
        while(j < len) {
            if(mp.find(s[j]) == mp.end()) {
                mp[s[j]] = j;
                if(maxLen < (j - i + 1)) {
                    maxLen = (j - i + 1);
                }
                j++;
            } else {
                int ind = mp[s[j]];
                while(i <= ind) {
                    mp.erease(s[i]);
                    i++;
                }
            }
        }
        return maxLen;
    }
};