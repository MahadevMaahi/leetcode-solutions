class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.length(), cLen, k;
        if(len == 0) return "";
        cLen = strs[0].length();
        for(int i = 1; i < len; i++) {
            for(k = 0; k < cLen && k < strs[i].length() && strs[0][k] == strs[i][k]; k++);
            cLen = (cLen > k) ? k : cLen;
        }
        return strs[0].substr(0, cLen);
    }
};