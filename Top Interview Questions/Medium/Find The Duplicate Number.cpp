class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size(), xr = -1;
        if(len == 0) return xr;
        for(int i = 0; i < len; i++) {
            if(nums[abs(nums[i])] < 0) return abs(nums[i]);
            else nums[abs(nums[i])] = -1 * nums[abs(nums[i])];
        }
        return xr;
    }
};