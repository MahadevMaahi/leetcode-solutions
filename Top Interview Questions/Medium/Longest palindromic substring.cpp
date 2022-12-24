class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length(), strLen = (2 * len) + 1;
        string str = "";
        str.push_back('#');
        for(int i = 0; i < len; i++) {
            str.push_back(s[i]);
            str.push_back('#');
        }
        vector<int> pLen(strLen, 0);
        int center = 0, right = 0, maxLen = 0, maxCenter = 0, mirror, low, high;

        for(int i = 0; i < strLen; i++) {
            mirror = (2 * center) - i;
            if(right > i) {
                pLen[i] = min(pLen[mirror], right - i);
            }
            low = i - (pLen[i] + 1);
            high = i + (pLen[i] + 1);
            while(low >= 0 && high < strLen && str[low] == str[high]) {
                low--;
                high++;
                pLen[i]++;
            }

            if(pLen[i] > maxLen) {
                maxLen = pLen[i];
                maxCenter = i;
            }

            if(i + pLen[i] > right) {
                center = i;
                right = i + pLen[i];
            }
        }
        str = str.substr(maxCenter - maxLen, (2 * maxLen) + 1);
        string ans = "";
        for(auto ch : str) {
            if(ch != '#') ans.push_back(ch);
        }
        return ans;
    }
};