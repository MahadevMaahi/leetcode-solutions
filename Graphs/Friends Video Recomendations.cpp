class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = watchedVideos.size();
        queue<int> q; vector<bool> visited(n, false);
        q.push(id); int currLevel = 0; visited[id] = true;
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                int front = q.front();
                for(auto i : friends[front]) if(!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
                q.pop();
            }
            currLevel++;
            if(currLevel == level) break;
        }
        map<string, int> mp;
        while(!q.empty()) {
            for(auto vid : watchedVideos[q.front()]) {
                mp[vid]++;
            }
            q.pop();
        }
        vector<pair<int, string>> unSortedAns;
        for(auto itr : mp) unSortedAns.push_back(make_pair(itr.second, itr.first));
        sort(unSortedAns.begin(), unSortedAns.end());
        vector<string> ans;
        for(auto itr : unSortedAns) ans.push_back(itr.second);
        return ans;
    }
};