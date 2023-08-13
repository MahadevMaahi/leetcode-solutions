class Solution {
public:

    void _dfs(int src, vector<vector<int>>& rooms, vector<bool> &visited) {
        if(visited[src]) return;
        visited[src] = true;
        for(auto itr : rooms[src]) _dfs(itr, rooms, visited);
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        _dfs(0, rooms, visited);
        for(int i = 0; i < n; i++) if(visited[i] == false) return false;
        return true;
    }
};