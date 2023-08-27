class Solution {
public:

    void _dfs(vector<bool> &isVisited, vector<vector<int>> &isConnected, int index) {
        if(isVisited[index]) return;
        isVisited[index] = true;
        for(int i = 0; i < isVisited.size(); i++) if(!isVisited[i] && isConnected[index][i]) {
            _dfs(isVisited, isConnected, i);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        if(n == 0) return 0;
        vector<bool> isVisited(n, false);
        for(int i = 0; i < n; i++) if(!isVisited[i]) {
            _dfs(isVisited, isConnected, i);
            ans++;
        }
        return ans;
    }
};