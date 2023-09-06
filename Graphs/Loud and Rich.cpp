class Solution {
public:

    int _dfs(int i, vector<vector<int>> &adj_list, vector<bool> &visited, vector<int> &quiet, vector<int> &ans) {
        if(visited[i]) return quiet[ans[i]];
        int _min = quiet[ans[i]];
        for(auto v : adj_list[i]) {
            int _sound = _dfs(v, adj_list, visited, quiet, ans);
            if(_sound < quiet[ans[i]]) {
                ans[i] = ans[v];
            }
            _min = min(_min, _sound);
        }
        visited[i] = true;
        return _min;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            ans[i] = i;
        }
        vector<bool> visited(n, false);
        vector<vector<int>> adj_list(n, vector<int>());
        for(auto edge : richer) {
            adj_list[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < n; i++) if(!visited[i]) {
            _dfs(i, adj_list, visited, quiet, ans);
        }
        return ans;
    }
};