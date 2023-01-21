class Solution {
public:

    bool recurDFSCyclic(vector<vector<int>> &adj_list, int index, vector<int> &visit) {
        visit[index] = 1;
        int len = adj_list[index].size();
        for(int i = 0; i < len; i++) {
            if(visit[adj_list[index][i]] == 1) return true;
            else if(visit[adj_list[index][i]] == 0 && recurDFSCyclic(adj_list, adj_list[index][i], visit)){
                return true;
            }
        }
        visit[index] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 0 || numCourses == 1) return true;
        int len = prerequisites.size();
        if(len == 0) return true;
        vector<int> ans, def, visit(numCourses, 0);
        vector<vector<int>> adj_list(numCourses, def);
        for(int i = 0; i < len; i++) adj_list[prerequisites[i][0]].push_back(prerequisites[i][1]);
        for(int i = 0; i < numCourses; i++) if(visit[i] == 0) {
            if(recurDFSCyclic(adj_list, i, visit)) return false;
        }
        return true;
    }
};