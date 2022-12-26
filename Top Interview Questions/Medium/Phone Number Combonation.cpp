class Solution {
public:

    string charString(char ch) {
        switch(ch) {
            case('2'): return "abc";
            case('3'): return "def";
            case('4'): return "ghi";
            case('5'): return "jkl";
            case('6'): return "mno";
            case('7'): return "pqrs";
            case('8'): return "tuv";
            case('9'): return "wxyz";
        }
        return "";
    }

    void comboRecur(string A, int index, vector<string> &str, string &s) {
        if(index > A.length()) return;
        if(index == A.length()) {
            if(s.length() != 0) str.push_back(s);
            return;
        }
        string chString = charString(A[index]);
        for(auto &ch : chString) {
            s.push_back(ch);
            comboRecur(A, index + 1, str, s);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> str;
        string s = ""; int index = 0;
        comboRecur(digits, index, str, s);
        return str;
    }
};