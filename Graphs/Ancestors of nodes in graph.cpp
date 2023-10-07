class Solution {
public:

    void _dfs(int index, vector<vector<int>> &adj_list, vector<bool> &visited, vector<unordered_set<int>> &ans) {
        if(visited[index] == true) return;
        for(auto i : adj_list[index]) {
            _dfs(i, adj_list, visited, ans);
            ans[index].insert(i);
            for(auto ancestor : ans[i]) ans[index].insert(ancestor);
        }
        visited[index] = true;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n);
        for(auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj_list[v].push_back(u);
        }
        vector<unordered_set<int>> ans(n);
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) if (visited[i] == false) {
            _dfs(i, adj_list, visited, ans);
        }
        vector<vector<int>> as(n);
        for(int i = 0; i < n; i++) {
            for (auto parent : ans[i]) as[i].push_back(parent);
            sort(as[i].begin(), as[i].end());
        }
        return as;
    }
};