class Solution {
public:

    static bool compareString(string s1, string s2) {
        return (s1 + s2) > (s2 + s1);
    }

    string largestNumber(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return "";
        vector<string> str;
        for(int i : nums) str.push_back(to_string(i));
        sort(str.begin(), str.end(), compareString);
        string s = "";
        for(string st : str) s = s + st;
        return (s[0] == '0') ? "0" : s;
    }
};