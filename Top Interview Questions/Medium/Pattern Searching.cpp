class Solution {
public:
    int strStr(string haystack, string needle) {
        int nLen = needle.length(), hLen = haystack.length(), i = 1, prevLps = 0, j;
        if (nLen == 0) return 0;
        vector<int> lps(nLen, 0);
        while(i < nLen) {
            if(needle[i] == needle[prevLps]) {
                lps[i] = prevLps + 1;
                prevLps = prevLps + 1;
                i = i + 1;
            } else if(prevLps == 0) {
                i = i + 1;
            } else {
                prevLps = lps[prevLps - 1];
            }
        }
        i = 0; j = 0;
        while(j < hLen) {
            if(needle[i] == haystack[j]) {
                i = i + 1;
                j = j + 1;
            } else if (i == 0) {
                j = j + 1;
            } else {
                i = lps[i - 1];
            }
            if(i == nLen) {
                return j - nLen;
            }
        }
        return -1;
    }
};