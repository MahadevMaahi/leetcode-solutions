class Solution {
public:

    void _swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void getPermutations(vector<int> &nums, int index, int len, vector<vector<int>> &ans) {
        if(index == len) {
            ans.push_back(nums);
            return;
        }

        for(int i = index, i < len; i++) {
            _swap(nums, i, index);
            getPermutations(nums, index + 1, len, ans);
            _swap(nums, i, index);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.length();
        vector<vector<int>> ans;
        getPermutations(nums, 0, len, ans);
        return ans;
    }
};