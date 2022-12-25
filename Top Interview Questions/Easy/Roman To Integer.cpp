class Solution {
public:
    int getValue(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int len = s.length();
        int ans = getValue(s[len - 1]);
        for(int i = len - 2; i >= 0; i--) {
            if(getValue(s[i]) < getValue(s[i+1])) {
                ans = ans - getValue(s[i]);
            } else {
                ans = ans + getValue(s[i]);
            }
        }
        return ans;
    }
};