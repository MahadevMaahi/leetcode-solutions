class Solution {
public:

    void _dfs(int src, vector<vector<int>> &graph, int dst, vector<int> &path, vector<vector<int>> &ans) {
        path.push_back(src);
        if(src == dst) {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for(auto itr : graph[src]) {
            _dfs(itr, graph, dst, path, ans);
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int src = 0, dst = n - 1;
        vector<vector<int>> ans; vector<int> path;
        _dfs(src, graph, dst, path, ans);
        return ans;
    }
};