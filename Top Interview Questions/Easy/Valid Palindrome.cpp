class Solution {
public:

    bool isAlphaNumeric(char ch) {    
        return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
    }
    
    bool isAlpha(char ch) {
        return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
    }

    bool isPalindrome(string s) {
        int len = s.length();
        if(len == 0) return true;
        int i = 0, j = len - 1;
        while(i < j && !isAlphaNumeric(s[i])) i++;
        while(i < j && !isAlphaNumeric(s[j])) j--;
        while(i < j) {
            while(i < j && !isAlphaNumeric(s[i])) i++;
            while(i < j && !isAlphaNumeric(s[j])) j--;
            if(s[i] != s[j]) {
                if(isAlpha(s[i]) && isAlpha(s[j])) {
                    if(s[i] - 'A' != s[j] - 'a' && s[i] - 'a' != s[j] - 'A' ) return false;
                } else return false;
            }
            i++; j--;
            while(i < j && !isAlphaNumeric(s[i])) i++;
            while(i < j && !isAlphaNumeric(s[j])) j--;
        }
        return true;
    }
};