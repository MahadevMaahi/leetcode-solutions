class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj_list(n);
        vector<int> dist(n, 1e9); dist[src] = 0;
        for(auto itr: flights) adj_list[itr[0]].push_back({itr[1], itr[2]});
        queue<vector<int>> q; vector<int> u, v;
        u.push_back(0); u.push_back(src); u.push_back(0);
        q.push(u);
        while(!q.empty()) {
            v = q.front();
            if(v[0] <= k) for (auto itr : adj_list[v[1]]) {
                u[0] = v[0] + 1;
                u[1] = itr.first;
                u[2] = v[2] + itr.second;
                if(dist[u[1]] > u[2]) {
                    dist[u[1]] = u[2];
                    q.push(u);
                }
            }
            q.pop();
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};