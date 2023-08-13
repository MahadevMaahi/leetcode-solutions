class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> visited(n + 1, -1);
        queue<int> q;
        vector<vector<int>> adj_list(n + 1);
        for(auto itr : dislikes) {
            adj_list[itr[0]].push_back(itr[1]);
            adj_list[itr[1]].push_back(itr[0]);
        }
        for(int i = 1; i <= n; i++) if(visited[i] == -1) {
            q.push(i); visited[i] = 0;
            while(!q.empty()) {
                int u = q.front();
                for(auto itr : adj_list[u]) {
                    if(visited[u] == visited[itr]) return false;
                    else if(visited[itr] == -1) {
                        visited[itr] = (visited[u] + 1) % 2;
                        q.push(itr);
                    }
                }
                q.pop();
            }
        }
        return true;
    }
};