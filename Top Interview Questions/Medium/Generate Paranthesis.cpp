class Solution {
public:

    void reccurParanthesis(vector<string> &str, string &s, int &open, int &close, int n) {
        if(open == n && close == n) {
            str.push_back(s);
            return;
        }
        if(open < n) {
            s.push_back('('); open++;
            reccurParanthesis(str, s, open, close, n);
            s.pop_back(); open--;
        }

        if(open > close) {
            s.push_back(')'); close++;
            reccurParanthesis(str, s, open, close, n);
            s.pop_back(); close--;
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> str;
        string s = ""; int open = 0, close = 0;
        reccurParanthesis(str, s, open, close, n);
        return str;
    }
};