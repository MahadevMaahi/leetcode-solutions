class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = s.length(), i = 0;
        if(len == 0 || len < k) return 0;
        if(k <= 1) return len;
        vector<int> mp(26, 0);
        for(char ch : s) mp[ch-'a']++;
        while(i < len && mp[s[i]-'a'] >= k) i++;
        if(i == len) return len;
        int x = longestSubstring(s.substr(0, i), k);
        while(i < len && mp[s[i]-'a'] < k) i++;
        int y = longestSubstring(s.substr(i), k);
        return max(x, y); 
    }
};