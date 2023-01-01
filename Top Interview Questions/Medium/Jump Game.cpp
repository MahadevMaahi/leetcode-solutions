class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size(), max_index;
        if(len == 1) return true;
        max_index = nums[0];
        for(int i = 1; i < len; i++) {
            if(i > max_index) return false;
            max_index = (i + nums[i] > max_index) ? i + nums[i] : max_index;
            if(max_index >= len - 1) return true;
        }
        return false;
    }
};