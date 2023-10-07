class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        if(start_node == end_node) return 1.0;
        vector<vector<pair<int, double>>> adj_list(n);
        vector<double> probDist(n, 0.0);
        vector<bool> visited(n, false);
        int edgeCount = edges.size();
        for(int i = 0; i < edgeCount; i++) {
            adj_list[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            adj_list[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        priority_queue<pair<double, int>> pq;
        pq.push(make_pair(1.0, start_node));
        while(!pq.empty()) {
            pair<double, int> node = pq.top();
            pq.pop();
            int u = node.second;
            double prob = node.first;
            if(u == end_node) return prob;
            else if (visited[u] == false) {
                visited[u] = true;
                for(auto edge : adj_list[u]) {
                    int v = edge.first;
                    double weight = edge.second;
                    if(visited[v] == false && probDist[v] < (prob * weight)) {
                        probDist[v] = (prob * weight);
                        pq.push(make_pair((prob * weight), v));
                    }
                }
            }
        }
        return probDist[end_node];
    }
};