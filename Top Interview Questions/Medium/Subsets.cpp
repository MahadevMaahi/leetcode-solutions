class Solution {
public:

    void subsetReccur(vector<vector<int>> &ans, vector<int> &nums, vector<int> &itr, int index, int len) {
        if(index == len) {
            ans.push_back(itr);
            return;
        }

        subsetReccur(ans, nums, itr, index + 1, len);
        itr.push_back(nums[index]);
        subsetReccur(ans, nums, itr, index + 1, len);
        itr.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; vector<int> itr;
        int len = nums.size();
        subsetReccur(ans, nums, itr, 0, len);
        return ans;
    }
};