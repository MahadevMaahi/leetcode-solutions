class Solution {

    bool isCyclic(vector<vector<int>> &adj_list, int index, vector<int> &visit, vector<int> &ans) {
        visit[index] = 1;
        for(int i = 0; i < adj_list[index].size(); i++) {
            if(visit[adj_list[index][i]] == 1) return true;
            else if(visit[adj_list[index][i]] == 0) {
                if(isCyclic(adj_list, adj_list[index][i], visit, ans)) {
                    return true;
                }
            }
        }
        visit[index] = 2;
        ans.push_back(index);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans, def, visit(numCourses, 0);
        if(numCourses == 0) return def;
        vector<vector<int>> adj_list(numCourses, def);
        for(int i = 0; i < prerequisites.size(); i++) adj_list[prerequisites[i][0]].push_back(prerequisites[i][1]);
        for(int i = 0; i < numCourses; i++) if(visit[i] == 0) {
            if(isCyclic(adj_list, i, visit, ans)) return def;
        }
        return ans;
    }
};