class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size(), up = 1, down = 1;
        if(len < 1) return len;
        for(int i  = 1; i < len; i++) {
            if(nums[i] > nums[i-1]) up = down + 1;
            else if(nums[i] < nums[i-1]) down = up + 1;
        }
        return max(up, down);
    }
};