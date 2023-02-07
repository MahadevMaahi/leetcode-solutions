class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> ans;
        vector<vector<int>> bucket(len + 1);
        if(len == 0) return ans;
        unordered_map<int, int> uMap;
        for(int i : nums) uMap[i]++;
        for(auto itr : uMap) bucket[itr.second].push_back(itr.first);
        for(int i = len; i >= 0 && ans.size() < k; i--) {
            for(int j = 0; j < bucket[i].size() && ans.size() < k; j++) {
                ans.push_back(bucket[i][j]);
            }
        }
        return ans;
    }
};