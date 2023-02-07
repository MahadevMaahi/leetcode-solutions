class Solution {
public:

    bool isDigit(char ch) {
        return (ch >= '0' && ch <= '9');
    }

    int calculate(string s) {
        int len = s.length(), sum = 0, last = 0, curr = 0;
        char op = '+';
        if(len == 0) return 0;
        for(int i = 0; i < len; i++) {
            char ch = s[i];
            if(isDigit(ch)) {
                curr = (curr * 10) + (ch - '0');
            }
            if (!isDigit(ch) && ch != ' ' || i == (len - 1)){
                if(op == '+') {
                    sum += last;
                    last = curr;
                } else if (op == '-') {
                    sum += last;
                    last = (-1) * curr;
                } else if (op == '*') {
                    last = last * curr;
                } else if (op == '/') {
                    last = last / curr;
                }
                op = ch;
                curr = 0;
            }
        }
        sum += last;
        return sum;
    }
};