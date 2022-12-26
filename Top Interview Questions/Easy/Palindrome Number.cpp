class Solution {
public:

    bool isPalindromeString(string s) {
        int len = s.length(), i = 0, j = len - 1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    bool isPalindrome(int x) {
        if(x < 0) return false;
        else if(x / 10 == 0) return true;
        string str = "";
        while(x != 0) {
            str.push_back('0' + (x % 10));
            x = x / 10;
        }
        return isPalindromeString(str);
    }
};