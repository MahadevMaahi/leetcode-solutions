class Solution {
public:

    void recurCutPartitions(string s, int low, vector<vector<bool>> &p, vector<string> &curPartitions, vector<vector<string>> &ans) {
        if(low == s.length()) {
            ans.push_back(curPartitions);
            return;
        }
        for(int i = low; i < s.length(); i++) if(p[low][i]) {
            curPartitions.push_back(s.substr(low, i - low + 1));
            recurCutPartitions(s, i+1, p, curPartitions, ans);
            curPartitions.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>  ans;
        int len = s.length();
        if(len == 0) return ans;
        vector<bool> vb(len, false);
        vector<vector<bool>> p(len, vb);
        for(int i = 0; i < len; i++) {
            p[i][i] = true;
            if(i-1 >= 0 && s[i] == s[i-1]) p[i-1][i] = true;
        }
        for(int l = 2; l <= len; l++) {
            for(int i = 0, j = l; j < len; i++, j++) {
                p[i][j] = p[i+1][j-1] && (s[i] == s[j]);
            }
        }
        vector<string> curPartitions;
        recurCutPartitions(s, 0, p, curPartitions, ans);
        return ans;
    }
};