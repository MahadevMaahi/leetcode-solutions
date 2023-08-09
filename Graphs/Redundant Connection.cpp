class Solution {
public:

    int find_parent(int i, vector<int> &parent) {
        if(parent[i] == i) return i;
        return parent[i] = find_parent(parent[i], parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int size = edges.size();
        vector<int> parent(size + 1, 0);
        for(int i = 1; i <= size; i++) parent[i] = i; 
        for(int i = 0; i < size; i++) {
            int u = find_parent(edges[i][0], parent);
            int v = find_parent(edges[i][1], parent);
            if(u == v) {
                return edges[i];
            } else {
                parent[u] = v;
            }
        }
        return edges[0];
    }
};