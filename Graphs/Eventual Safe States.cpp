class Solution {
public:

    void _dfs(int src, vector<vector<int>>& graph, vector<int> &process) {
        if(process[src] == 2 || process[src] == 1) return;
        process[src] = 1;
        for(auto itr : graph[src]) {
            _dfs(itr, graph, process);
            if(process[itr] == 1) {
                process[src] = 1;
                return;
            }
        }
        process[src] = 2;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> termNode(n, false);
        for(int i = 0; i < n; i++) termNode[i] = graph[i].size() == 0;
        vector<int> process(n, 0), ans;
        for(int i = 0; i < n; i++) process[i] = termNode[i] ? 2 : 0;
        for(int i = 0; i < n; i++) if(process[i] == 0) _dfs(i, graph, process);
        for(int i = 0; i < n; i++) if(process[i] == 2) ans.push_back(i);
        return ans;
    }
};