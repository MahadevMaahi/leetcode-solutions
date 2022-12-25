class Solution {
public:
    string generateTheString(int n) {
        string str = "";
        for(int i = 0; i < n; i++) str.push_back('a');
        if((n % 2) == 0) {
            str[0] = 'b';
        }
        return str;
    }
};