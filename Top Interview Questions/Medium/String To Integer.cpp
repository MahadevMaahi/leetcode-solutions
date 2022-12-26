class Solution {
public:

    bool isNotDigit(char ch) {
        return (ch < '0' || ch > '9');
    }

    int myAtoi(string s) {
        int len = s.length(), i = 0, sign = 1;
        long ans = 0;
        while(i < len && s[i] == ' ') i++;
        if(i < len && s[i] == '-') sign = -1;
        if(i < len && (s[i] == '-' || s[i] == '+')) i++;
        while(i < len) {
            if(s[i] == ' ' || isNotDigit(s[i])) break;
            ans = (ans * 10) + (s[i] - '0');
            if(sign == 1 && ans > INT_MAX) return INT_MAX;
            else if(sign == -1 && (-1 * ans) < INT_MIN) return INT_MIN;
            i++;
        }
        return (int) (sign * ans);
    }
};