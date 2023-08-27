class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> level(n, -1);
        queue<int> q;
        for(int i = 0; i < n; i++) if(level[i] == -1) {
            q.push(i); int lvl = 0;
            while(!q.empty()) {
                int len = q.size();
                while(len--) {
                    int u = q.front();
                    level[u] = lvl;
                    for(auto itr: graph[u]) if(level[itr] == -1) q.push(itr);
                    else if(level[itr] == lvl) return false;
                    q.pop();
                }
                lvl = (lvl + 1) % 2;
            }
        }
        return true;
    }
};