class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj_list(n + 1);
        vector<int> colour(n + 1, 0);
        for(auto edge : paths) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        for(int i = 1; i <= n; i++) {
            vector<bool> color(5, false);
            for(auto list : adj_list[i]) {
                color[colour[list]] = true;
            }
            for(int j = 1; j <= 4; j++) if(color[j] == false) {
                colour[i] = j; break;
            }
        }
        colour.erase(colour.begin());
        return colour;
    }
};