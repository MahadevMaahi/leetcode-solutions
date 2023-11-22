class Solution {
public:

    void _generateParenthesis(int i, vector<vector<string>> &ans) {
        for(auto itr : ans[i-1]) {
            ans[i].push_back("()" + itr);
            if(itr != "") {
                ans[i].push_back("(" + itr + ")");
                ans[i].push_back(itr + "()");
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        return ans;
    }
};