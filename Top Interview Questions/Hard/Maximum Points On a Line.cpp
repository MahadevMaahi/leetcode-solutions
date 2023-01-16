class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size(), infCnt, ans = 0;
        if(len == 0) return 0;
        float slope;
        for(int i = 0; i < len; i++) {
            unordered_map<float, int> uMap;
            infCnt = 0;
            for(int j = i+1; j < len; j++) {
                if(points[i][0] == points[j][0]) infCnt++;
                else {
                    slope = ((float) (points[j][1] - points[i][1])) / (points[j][0] - points[i][0]);
                    if(uMap.count(slope)) uMap[slope]++; else uMap[slope] = 1;
                }
            }
            for(auto itr : uMap) ans = max(ans, itr.second);
            ans = max(ans, infCnt);
        }
        return ans + 1;
    }
};