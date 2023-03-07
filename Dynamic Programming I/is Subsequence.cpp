class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0) return true;
        int len = t.length(), i = 0, j = 0;
        while(j < len) {
            if(s[i] == t[j]) i++;
            if(i == s.length()) return true;
            j++;
        }
        return false;
    }
};